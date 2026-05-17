#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>

// ====================== STATE ======================
struct State
{
    double position{0.0}; // meters
    double velocity{0.0}; // m/s
    double mass{1000.0};  // kg
};

// ====================== ENTITY ======================
class Rocket
{
public:
    State state;
    double thrust{0.0};

    void applyThrust(double t)
    {
        thrust = t;
    }
};

// ====================== PHYSICS (Strategy) ======================
class IPhysicsModel
{
public:
    virtual double computeAcceleration(const Rocket &rocket) = 0;
    virtual ~IPhysicsModel() = default;
};

class BasicPhysics : public IPhysicsModel
{
public:
    double computeAcceleration(const Rocket &rocket) override
    {
        const double g = 9.81;
        double thrustAcc = rocket.thrust / rocket.state.mass;
        return thrustAcc - g;
    }
};

// ====================== INTEGRATOR (Strategy) ======================
class IIntegrator
{
public:
    virtual void step(Rocket &rocket, IPhysicsModel &physics, double dt) = 0;
    virtual ~IIntegrator() = default;
};

class EulerIntegrator : public IIntegrator
{
public:
    void step(Rocket &rocket, IPhysicsModel &physics, double dt) override
    {
        double acc = physics.computeAcceleration(rocket);

        rocket.state.velocity += acc * dt;
        rocket.state.position += rocket.state.velocity * dt;
    }
};

// ====================== OBSERVER ======================
class Observer
{
public:
    virtual void update(const Rocket &rocket) = 0;
    virtual ~Observer() = default;
};

class Telemetry : public Observer
{
public:
    void update(const Rocket &rocket) override
    {
        std::cout << "Pos: " << rocket.state.position
                  << " m | Vel: " << rocket.state.velocity
                  << " m/s | Thrust: " << rocket.thrust << " N\n";
    }
};

// ====================== COMMAND ======================
class Command
{
public:
    virtual void execute(Rocket &rocket) = 0;
    virtual ~Command() = default;
};

class SetThrustCommand : public Command
{
    double thrust;

public:
    SetThrustCommand(double t) : thrust(t) {}

    void execute(Rocket &rocket) override
    {
        rocket.applyThrust(thrust);
    }
};

// ====================== ENGINE ======================
class SimulationEngine
{
    Rocket rocket;
    std::unique_ptr<IPhysicsModel> physics;
    std::unique_ptr<IIntegrator> integrator;
    std::vector<Observer *> observers;

public:
    SimulationEngine()
    {
        physics = std::make_unique<BasicPhysics>();
        integrator = std::make_unique<EulerIntegrator>();
    }

    void addObserver(Observer *obs)
    {
        observers.push_back(obs);
    }

    void executeCommand(Command &cmd)
    {
        cmd.execute(rocket);
    }

    void run()
    {
        const double dt = 0.1;

        for (int i = 0; i < 100; ++i)
        {
            integrator->step(rocket, *physics, dt);

            for (auto obs : observers)
            {
                obs->update(rocket);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};

// ====================== MAIN ======================
int main()
{
    SimulationEngine engine;
    Telemetry telemetry;

    engine.addObserver(&telemetry);

    // Set thrust (try changing this value)
    SetThrustCommand thrustCmd(15000);
    // SetThrustCommand thrustCmd(5000); // rocket may fall
    // SetThrustCommand thrustCmd(20000); // strong lift
    // SetThrustCommand thrustCmd(0); //free fall
    // SetThrustCommand thrustCmd(-3); //force downward

    engine.executeCommand(thrustCmd);

    engine.run();

    return 0;
}