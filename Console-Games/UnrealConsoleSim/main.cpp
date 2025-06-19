#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

// === Composite Pattern: Component System ===
class Component
{
public:
    virtual void Update(float dt) = 0;
    virtual ~Component() = default;
};

class MovementComponent : public Component
{
public:
    void Update(float) override
    {
        std::cout << "  - Moving forward\n";
    }
};

// === Actor Base ===
class Actor
{
    std::vector<std::unique_ptr<Component>> components;
    std::string name;

public:
    Actor(std::string name) : name(std::move(name)) {}
    virtual ~Actor() = default;

    void AddComponent(std::unique_ptr<Component> comp)
    {
        components.push_back(std::move(comp));
    }

    virtual void Tick(float dt)
    {
        std::cout << name << " Tick:\n";
        for (auto &comp : components)
            comp->Update(dt);
    }
};

// === Factory Method Pattern ===
class ActorFactory
{
public:
    static std::unique_ptr<Actor> Create(const std::string &type)
    {
        if (type == "Hero")
        {
            auto actor = std::make_unique<Actor>("Hero");
            actor->AddComponent(std::make_unique<MovementComponent>());
            return actor;
        }
        return nullptr;
    }
};

// === Singleton Pattern: Game Engine ===
class Engine
{
    std::vector<class Actor *> actors;
    bool running = true;
    Engine() = default;

public:
    static Engine &Get()
    {
        static Engine instance;
        return instance;
    }

    void AddActor(class Actor *actor)
    {
        actors.push_back(actor);
    }

    void Run()
    {
        std::string input;
        while (running)
        {
            for (auto *actor : actors)
                actor->Tick(0.016f); // fake deltaTime
            std::cout << "\n> Enter command (move/quit): ";
            std::getline(std::cin, input);
            if (input == "quit")
                running = false;
            else if (input == "move")
                Notify("MoveEvent");
        }
    }

    // === Observer Pattern: Event System ===
    using Callback = std::function<void()>;
    std::unordered_map<std::string, std::vector<Callback>> listeners;

    void Subscribe(const std::string &event, Callback cb)
    {
        listeners[event].push_back(cb);
    }

    void Notify(const std::string &event)
    {
        for (auto &cb : listeners[event])
            cb();
    }
};

// === Command Pattern ===
class Command
{
public:
    virtual void Execute() = 0;
    virtual ~Command() = default;
};

class MoveCommand : public Command
{
public:
    void Execute() override
    {
        Engine::Get().Notify("MoveEvent");
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto hero = ActorFactory::Create("Hero");

    // Observer Pattern: Subscribe to move event
    Engine::Get().Subscribe("MoveEvent", [heroPtr = hero.get()]
                            {
                                heroPtr->Tick(0.016f); // simulate on move
                            });

    Engine::Get().AddActor(hero.get());
    Engine::Get().Run();

    return 0;
}
