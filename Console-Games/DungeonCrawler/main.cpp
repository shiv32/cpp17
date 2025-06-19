#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <functional>

// Forward declaration
class Actor;
class GameEngine;

// Observer Pattern: Combat Logger
class Observer
{
public:
    virtual void onNotify(const std::string &event) = 0;
};

class CombatLogger : public Observer
{
public:
    void onNotify(const std::string &event) override
    {
        std::cout << "[LOG] " << event << "\n";
    }
};

// Strategy Pattern: Enemy AI
class Behavior
{
public:
    // virtual void act(Actor* self, Actor* player) = 0;
    virtual void act(std::shared_ptr<Actor> self, std::shared_ptr<Actor> player) = 0;
};

class AggressiveBehavior : public Behavior
{
public:
    // void act(Actor* self, Actor* player) override;
    void act(std::shared_ptr<Actor> self, std::shared_ptr<Actor> player) override;
};

// Base Actor class
class Actor : public std::enable_shared_from_this<Actor>
{
protected:
    std::string name;
    int hp;
    std::shared_ptr<Behavior> behavior;
    std::vector<Observer *> observers;

public:
    Actor(std::string name, int hp) : name(name), hp(hp) {}
    virtual ~Actor() = default;

    virtual void Tick(GameEngine &engine) = 0;

    void setBehavior(std::shared_ptr<Behavior> b) { behavior = b; }

    void addObserver(Observer *obs) { observers.push_back(obs); }

    void notify(const std::string &msg)
    {
        for (auto *obs : observers)
            obs->onNotify(msg);
    }

    void takeDamage(int dmg)
    {
        hp -= dmg;
        notify(name + " takes " + std::to_string(dmg) + " damage.");
        if (hp <= 0)
            notify(name + " has been defeated!");
    }

    bool isAlive() const { return hp > 0; }

    const std::string &getName() const { return name; }
    int getHP() const { return hp; }

    friend class AggressiveBehavior;
};

// Player Actor
class Player : public Actor
{
public:
    Player(std::string name) : Actor(name, 20) {}

    void Tick(GameEngine &engine) override
    {
        // Player actions are handled by input commands
    }

    void attack(Actor *target)
    {
        notify(name + " attacks " + target->getName() + "!");
        target->takeDamage(5);
    }
};

// Enemy Actor
class Enemy : public Actor
{
public:
    Enemy(std::string name) : Actor(name, 10) {}

    void Tick(GameEngine &engine) override;

    void setTarget(Actor *target)
    {
        setBehavior(std::make_shared<AggressiveBehavior>());
    }
};

void AggressiveBehavior::act(std::shared_ptr<Actor> self, std::shared_ptr<Actor> player)
{
    if (player->isAlive())
    {
        self->notify(self->getName() + " attacks " + player->getName() + "!");
        player->takeDamage(4);
    }
}

// Command Pattern
class Command
{
public:
    virtual void execute(GameEngine &engine) = 0;
};

class AttackCommand : public Command
{
public:
    void execute(GameEngine &engine) override;
};

class MoveCommand : public Command
{
    std::string direction;

public:
    MoveCommand(std::string dir) : direction(dir) {}

    void execute(GameEngine &engine) override
    {
        std::cout << "You move " << direction << ".\n";
    }
};

// Game Engine
class GameEngine
{
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Actor>> actors;
    std::map<std::string, std::shared_ptr<Command>> commandMap;
    CombatLogger logger;

public:
    GameEngine()
    {
        player = std::make_shared<Player>("Hero");
        player->addObserver(&logger);

        auto enemy = std::make_shared<Enemy>("Goblin");
        enemy->addObserver(&logger);
        enemy->setBehavior(std::make_shared<AggressiveBehavior>());

        actors.push_back(player);
        actors.push_back(enemy);

        commandMap["attack"] = std::make_shared<AttackCommand>();
        commandMap["north"] = std::make_shared<MoveCommand>("north");
        commandMap["south"] = std::make_shared<MoveCommand>("south");
    }

    void Run()
    {
        std::string input;
        while (player->isAlive())
        {
            std::cout << "\n> ";
            std::getline(std::cin, input);
            if (commandMap.count(input))
            {
                commandMap[input]->execute(*this);
            }
            else
            {
                std::cout << "Unknown command.\n";
            }

            // Simulate actors
            for (auto &actor : actors)
            {
                if (actor->isAlive())
                    actor->Tick(*this);
            }

            if (!getEnemy()->isAlive())
            {
                std::cout << "\n🎉 You defeated the goblin! Game Over.\n";
                break;
            }
        }

        if (!player->isAlive())
            std::cout << "\n💀 You died! Game Over.\n";
    }

    std::shared_ptr<Player> getPlayer() { return player; }

    std::shared_ptr<Actor> getEnemy()
    {
        for (auto &a : actors)
        {
            if (a.get() != player.get())
                return a;
        }
        return nullptr;
    }
};

void Enemy::Tick(GameEngine &engine)
{
    if (behavior)
        behavior->act(shared_from_this(), engine.getPlayer());
}

// Command execution
void AttackCommand::execute(GameEngine &engine)
{
    engine.getPlayer()->attack(engine.getEnemy().get());
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::cout << "🔷 Dungeon Console Crawler\n";
    std::cout << "Type `north`, `south`, or `attack`\n";

    GameEngine engine;
    engine.Run();
    return 0;
}
