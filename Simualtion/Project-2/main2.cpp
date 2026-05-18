/*
           Assertion '__n < this->size()' failed
           
    Bug fix : Somewhere, a car’s position is going out of bounds.

    What you just learned (this is valuable)
        Simulation bugs are often math/logic, not syntax
        Always validate state invariants
        Circular systems need modulo-safe math
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>

struct Car
{
    int id;
    int position;
    int speed;
};

class TrafficSimulation
{
private:
    int roadLength;
    int maxSpeed;
    std::vector<Car> cars;

public:
    TrafficSimulation(int length, int maxSpd)
        : roadLength(length), maxSpeed(maxSpd) {}

    void addCar(int id, int pos, int speed)
    {
        cars.push_back({id, pos, speed});
    }

    void update()
    {
        std::sort(cars.begin(), cars.end(),
                  [](const Car &a, const Car &b)
                  {
                      return a.position > b.position;
                  });

        for (size_t i = 0; i < cars.size(); ++i)
        {
            Car &car = cars[i];

            int distance = roadLength;

            if (i > 0)
            {
                const Car &front = cars[i - 1];
                distance = (front.position - car.position - 1 + roadLength) % roadLength;
            }

            // accelerate
            if (car.speed < maxSpeed)
            {
                car.speed++;
            }

            // avoid collision
            if (car.speed > distance)
            {
                car.speed = distance;
            }

            if (car.speed < 0)
                car.speed = 0;

            // move
            car.position += car.speed;

            // wrap safely
            car.position = (car.position % roadLength + roadLength) % roadLength;
        }
    }
    void render()
    {
        std::vector<char> road(roadLength, '.');

        for (const auto &car : cars)
        {
            road[car.position] = 'A' + (car.id % 26);
        }

        for (char c : road)
        {
            std::cout << c;
        }
        std::cout << "\n";
    }
};

int main()
{
    TrafficSimulation sim(50, 5);

    // Add cars (id, position, speed)
    sim.addCar(0, 0, 1);
    sim.addCar(1, 10, 2);
    sim.addCar(2, 20, 1);
    sim.addCar(3, 30, 3);

    for (int step = 0; step < 100; ++step)
    {
        system("clear"); // use "cls" on Windows

        std::cout << "Step: " << step << "\n";

        sim.update();
        sim.render();

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}