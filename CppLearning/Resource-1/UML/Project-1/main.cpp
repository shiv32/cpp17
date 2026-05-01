#include <iostream>
#include <memory>

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
        std::cout << "Engine running with " << horsepower << " HP\n";
    }

private:
    int horsepower;
};

// ----------------- COMPOSITION -----------------
class Car
{
public:
    // Engine is a part of Car (Composition)
    Car() : engine(150) // created inside Car
    { 
        std::cout << "Car constructed (composition)\n";
    }

    ~Car()
    {
        std::cout << "Car destroyed\n";
    }

    void drive()
    {
        engine.start(); // directly access
    }

private:
    Engine engine; // Composition (engine owned by Car)
};

// ----------------- AGGREGATION -----------------
class Driver
{
public:
    // Driver just *uses* an existing Car (Aggregation)
    Driver(std::shared_ptr<Car> carPtr) : car(carPtr)
    {
        std::cout << "Driver constructed (aggregation)\n";
    }

    ~Driver()
    {
        std::cout << "Driver destroyed\n";
    }

    void go()
    {
        if (car)
            car->drive();
    }

private:
    std::shared_ptr<Car> car; // Aggregation (does not own car)
};

// ----------------- DEMO -----------------
int main()
{
    std::cout << "---- Composition Demo ----\n";
    
    {
        Car car;     // Car owns Engine
        car.drive(); // Engine starts

    } // Engine automatically destroyed when Car goes out of scope

    std::cout << "\n---- Aggregation Demo ----\n";

    {
        auto sharedCar = std::make_shared<Car>(); // Car created

        {

            Driver driver(sharedCar); // Driver uses Car but doesn’t own
            driver.go();

        } // Driver destroyed, Car still exists

        std::cout << "Driver out of scope, but Car still alive\n";

    } // Car finally destroyed

    return 0;
}
