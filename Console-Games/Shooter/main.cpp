#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <thread>
#include <chrono>

// ==== Observer Pattern ====
class Observer
{
public:
    virtual void onNotify(const std::string &message) = 0;
};

class ConsoleNotifier : public Observer
{
public:
    void onNotify(const std::string &message) override
    {
        std::cout << "[Notify] " << message << "\n";
    }
};

// ==== Singleton Pattern ====
class GameManager
{
    GameManager() = default;

public:
    static GameManager &getInstance()
    {
        static GameManager instance;
        return instance;
    }

    bool running = true;
    std::shared_ptr<Observer> observer;

    void notify(const std::string &msg)
    {
        if (observer)
            observer->onNotify(msg);
    }

    GameManager(GameManager const &) = delete;
    void operator=(GameManager const &) = delete;
};

// ==== Command Pattern ====
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class Player
{
    int health = 100;
    int ammo = 6;
    const int maxAmmo = 6;

public:
    void shoot()
    {
        if (ammo > 0)
        {
            std::cout << "Bang! Bullet fired.\n";
            ammo--;
        }
        else
        {
            std::cout << "Click! Out of ammo.\n";
        }
    }

    void reload()
    {
        std::cout << "Reloading...\n";
        ammo = maxAmmo;
    }

    void takeDamage(int dmg)
    {
        health -= dmg;
        std::cout << "You took " << dmg << " damage. Health: " << health << "\n";
        if (health <= 0)
        {
            GameManager::getInstance().notify("Player Died");
            GameManager::getInstance().running = false;
        }
    }

    void status()
    {
        std::cout << "[Player] Health: " << health << ", Ammo: " << ammo << "\n";
    }
};

class ShootCommand : public Command
{
    Player &player;

public:
    ShootCommand(Player &p) : player(p) {}
    void execute() override
    {
        player.shoot();
    }
};

class ReloadCommand : public Command
{
    Player &player;

public:
    ReloadCommand(Player &p) : player(p) {}
    void execute() override
    {
        player.reload();
    }
};

class QuitCommand : public Command
{
public:
    void execute() override
    {
        std::cout << "Quitting game...\n";
        GameManager::getInstance().running = false;
    }
};

// ==== Factory Pattern ====
class CommandFactory
{
    Player &player;

public:
    CommandFactory(Player &p) : player(p) {}

    std::unique_ptr<Command> create(char input)
    {
        switch (tolower(input))
        {
        case 's':
            return std::make_unique<ShootCommand>(player);
        case 'r':
            return std::make_unique<ReloadCommand>(player);
        case 'q':
            return std::make_unique<QuitCommand>();
        default:
            return nullptr;
        }
    }
};

// ==== Strategy Pattern ====
class EnemyStrategy
{
public:
    virtual void attack(Player &player) = 0;
    virtual ~EnemyStrategy() = default;
};

class RandomAttack : public EnemyStrategy
{
public:
    void attack(Player &player) override
    {
        if (rand() % 2 == 0)
        {
            std::cout << "[Enemy] Fires!\n";
            player.takeDamage(10);
        }
        else
        {
            std::cout << "[Enemy] Misses this turn.\n";
        }
    }
};

class Enemy
{
    std::unique_ptr<EnemyStrategy> strategy;

public:
    Enemy(std::unique_ptr<EnemyStrategy> s) : strategy(std::move(s)) {}
    void act(Player &player)
    {
        strategy->attack(player);
    }
};

// ==== Game Loop ====
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    srand(static_cast<unsigned int>(time(0)));
    Player player;
    GameManager::getInstance().observer = std::make_shared<ConsoleNotifier>();
    CommandFactory factory(player);
    Enemy enemy(std::make_unique<RandomAttack>());

    while (GameManager::getInstance().running)
    {
        player.status();
        std::cout << "Enter [S]hoot [R]eload [Q]uit: ";
        char input;
        std::cin >> input;

        auto cmd = factory.create(input);
        if (cmd)
            cmd->execute();
        else
            std::cout << "Unknown command.\n";

        enemy.act(player);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
