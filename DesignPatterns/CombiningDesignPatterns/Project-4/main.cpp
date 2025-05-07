// Mini Turn-Based RPG Battle System (Pattern Focused)
// Patterns used: Factory, Strategy, Command, Observer, State

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <functional>

// Forward declarations
class Character;
class BattleContext;

// --------------------- Observer Pattern ------------------------
class Observer
{
public:
    virtual void onEvent(const std::string &message) = 0;
};

class ConsoleLogger : public Observer
{
public:
    void onEvent(const std::string &message) override
    {
        std::cout << "[Log] " << message << std::endl;
    }
};

// --------------------- Command Pattern ------------------------
class Command
{
public:
    virtual void execute(Character &user, Character &target) = 0;
    virtual ~Command() = default;
};

class AttackCommand : public Command
{
public:
    void execute(Character &user, Character &target) override;
};

// --------------------- Strategy Pattern ------------------------
class AttackStrategy
{
public:
    virtual int calculateDamage(Character &attacker) = 0;
    virtual ~AttackStrategy() = default;
};

class NormalAttack : public AttackStrategy
{
public:
    int calculateDamage(Character &attacker) override;
};

// --------------------- Character ------------------------
class Character
{
    std::string name;
    int hp;
    std::unique_ptr<AttackStrategy> attackStrategy;
    std::vector<Observer *> observers;

public:
    Character(const std::string &name, int hp, std::unique_ptr<AttackStrategy> strategy)
        : name(name), hp(hp), attackStrategy(std::move(strategy)) {}

    void attach(Observer *obs) { observers.push_back(obs); }

    void notify(const std::string &msg)
    {
        for (auto obs : observers)
            obs->onEvent(msg);
    }

    void takeDamage(int dmg)
    {
        hp -= dmg;
        if (hp < 0)
            hp = 0;
        notify(name + " takes " + std::to_string(dmg) + " damage. HP: " + std::to_string(hp));
    }

    void attack(Character &target)
    {
        int dmg = attackStrategy->calculateDamage(*this);
        target.takeDamage(dmg);
    }

    const std::string &getName() const { return name; }
    bool isAlive() const { return hp > 0; }
};

// Implementation of strategies and commands
int NormalAttack::calculateDamage(Character &)
{
    return 10 + rand() % 6; // Random base damage
}

void AttackCommand::execute(Character &user, Character &target)
{
    user.attack(target);
}

// --------------------- Factory Pattern ------------------------
class CharacterFactory
{
public:
    static std::unique_ptr<Character> createWarrior(const std::string &name)
    {
        return std::make_unique<Character>(name, 100, std::make_unique<NormalAttack>());
    }
};

// --------------------- State Pattern ------------------------
class BattleState
{
public:
    virtual void handle(BattleContext &context) = 0;
    virtual ~BattleState() = default;
};

class PlayerTurn : public BattleState
{
public:
    void handle(BattleContext &context) override;
};

class EnemyTurn : public BattleState
{
public:
    void handle(BattleContext &context) override;
};

// --------------------- Battle Context ------------------------
class BattleContext
{
    std::unique_ptr<BattleState> state;

public:
    Character &player;
    Character &enemy;

    BattleContext(Character &p, Character &e)
        : player(p), enemy(e), state(std::make_unique<PlayerTurn>()) {}

    void setState(std::unique_ptr<BattleState> s) { state = std::move(s); }
    void nextTurn() { state->handle(*this); }
};

void PlayerTurn::handle(BattleContext &context)
{
    ConsoleLogger logger;
    context.player.attach(&logger);
    context.enemy.attach(&logger);

    std::cout << "\nPlayer's Turn: Choose an action\n1. Attack\n> ";
    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
        AttackCommand attack;
        attack.execute(context.player, context.enemy);
    }

    if (!context.enemy.isAlive())
    {
        std::cout << "Enemy defeated!\n";
        return;
    }
    context.setState(std::make_unique<EnemyTurn>());
    context.nextTurn();
}

void EnemyTurn::handle(BattleContext &context)
{
    std::cout << "\nEnemy's Turn:\n";
    AttackCommand attack;
    attack.execute(context.enemy, context.player);

    if (!context.player.isAlive())
    {
        std::cout << "You were defeated...\n";
        return;
    }

    context.setState(std::make_unique<PlayerTurn>());
    context.nextTurn();
}

// --------------------- Main ------------------------
int main()
{

    srand(time(nullptr));

    auto player = CharacterFactory::createWarrior("Hero");
    auto enemy = CharacterFactory::createWarrior("Goblin");

    BattleContext context(*player, *enemy);

    context.nextTurn();

    return 0;
}
