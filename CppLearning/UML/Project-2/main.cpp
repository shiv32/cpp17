#include <iostream>
#include <memory>
#include <string>

//
// -------- Composition --------
//
class Engine
{
public:
    Engine(int hp) : horsepower(hp)
    {
        std::cout << "Engine constructed (" << horsepower << " HP)\n";
    }
    ~Engine()
    {
        std::cout << "Engine destroyed\n";
    }

    void start() const
    {
        std::cout << "Engine started (" << horsepower << " HP)\n";
    }

private:
    int horsepower;
};

class Car
{
public:
    // Composition: Car owns Engine completely
    Car(std::string model, int hp)
        : modelName(std::move(model)), engine(hp)
    {
        std::cout << "Car " << modelName << " constructed (composition)\n";
    }

    ~Car()
    {
        std::cout << "Car " << modelName << " destroyed\n";
    }

    void drive() const
    {
        std::cout << "Car " << modelName << " is driving...\n";
        engine.start();
    }

    std::string getModel() const { return modelName; }

private:
    std::string modelName;
    Engine engine; // Composition: Engine dies with Car
};

//
// -------- Aggregation --------
//
class Driver
{
public:
    // Aggregation: Driver uses Car, but does not own it
    Driver(std::string name, std::shared_ptr<Car> c)
        : driverName(std::move(name)), car(c)
    {
        std::cout << "Driver " << driverName << " constructed (aggregation)\n";
    }

    ~Driver()
    {
        std::cout << "Driver " << driverName << " destroyed\n";
    }

    void goForDrive() const
    {
        if (auto c = car.lock())
        {
            std::cout << driverName << " is driving " << c->getModel() << "\n";
            c->drive();
        }
        else
        {
            std::cout << driverName << " has no car to drive\n";
        }
    }

private:
    std::string driverName;
    std::weak_ptr<Car> car; // weak_ptr → aggregation, no ownership
};

//
// -------- Association --------
//
class Mechanic
{
public:
    Mechanic(std::string n) : name(std::move(n))
    {
        std::cout << "Mechanic " << name << " created\n";
    }

    ~Mechanic()
    {
        std::cout << "Mechanic " << name << " destroyed\n";
    }

    // Association: Mechanic works *on* any Car (no ownership)
    void service(Car &car)
    {
        std::cout << "Mechanic " << name << " is servicing " << car.getModel() << "\n";
    }

private:
    std::string name;
};

//
// -------- MAIN DEMO --------
//
int main()
{
    std::cout << "---- Start Demo ----\n";

    auto carPtr = std::make_shared<Car>("Tesla Model X", 500); // Composition: Car owns Engine

    {

        Driver driver("Alice", carPtr); // Aggregation
        driver.goForDrive();

        Mechanic mech("Bob"); // Association
        mech.service(*carPtr);

    } // Driver and Mechanic destroyed, Car still alive

    std::cout << "Driver and Mechanic out of scope, but Car still alive\n";

    std::cout << "---- End Demo ----\n";
    
    return 0;
}
