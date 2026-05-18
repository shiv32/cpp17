
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <cmath>
#include <sstream>

// ===================== Math =====================
struct Vec3
{
    float x{0}, y{0}, z{0};

    Vec3() = default;
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3 &other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vec3 operator*(float scalar) const
    {
        return {x * scalar, y * scalar, z * scalar};
    }
};

// ===================== Entity =====================
struct Entity
{
    int id;
    Vec3 position;
    Vec3 velocity;
};

// ===================== Frame Data =====================
struct EntityState
{
    int id;
    Vec3 position;
};

struct FrameData
{
    int frameNumber;
    std::vector<EntityState> entities;
};

// ===================== Observer Interface =====================
class IFrameListener
{
public:
    virtual ~IFrameListener() = default;
    virtual void onFrame(const FrameData &frame) = 0;
};

// ===================== Console Publisher =====================
class ConsolePublisher : public IFrameListener
{
public:
    void onFrame(const FrameData &frame) override
    {
        std::ostringstream oss;
        oss << "Frame " << frame.frameNumber << "\n";
        for (const auto &e : frame.entities)
        {
            oss << "  Entity " << e.id
                << " -> Pos(" << e.position.x
                << ", " << e.position.y
                << ", " << e.position.z << ")\n";
        }
        std::cout << oss.str() << std::endl;
    }
};

// ===================== Simulation Engine =====================
class SimulationEngine
{
public:
    void addEntity(const Entity &e)
    {
        entities.push_back(e);
    }

    void addListener(std::shared_ptr<IFrameListener> listener)
    {
        listeners.push_back(listener);
    }

    void run(int maxFrames = 100)
    {
        const float dt = 0.016f; // ~60 FPS
        int frame = 0;

        while (frame < maxFrames)
        {
            update(dt);
            FrameData frameData = buildFrame(frame);
            publish(frameData);

            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            frame++;
        }
    }

private:
    std::vector<Entity> entities;
    std::vector<std::shared_ptr<IFrameListener>> listeners;

    void update(float dt)
    {
        for (auto &e : entities)
        {
            // simple physics: position += velocity * dt
            e.position = e.position + e.velocity * dt;

            // add a tiny oscillation (just to make it interesting)
            e.position.y += std::sin(e.position.x) * 0.01f;
        }
    }

    FrameData buildFrame(int frameNumber)
    {
        FrameData frame;
        frame.frameNumber = frameNumber;

        for (const auto &e : entities)
        {
            frame.entities.push_back({e.id, e.position});
        }

        return frame;
    }

    void publish(const FrameData &frame)
    {
        for (auto &listener : listeners)
        {
            listener->onFrame(frame);
        }
    }
};

// ===================== Main =====================
int main()
{
    SimulationEngine engine;

    // Add entities
    engine.addEntity({1, {0, 0, 0}, {1.0f, 0.2f, 0.5f}});
    engine.addEntity({2, {5, 1, -2}, {-0.5f, 0.1f, 0.3f}});
    engine.addEntity({3, {-3, 2, 1}, {0.2f, -0.1f, 0.4f}});

    // Add output listener
    auto console = std::make_shared<ConsolePublisher>();
    engine.addListener(console);

    // Run simulation
    engine.run(50);

    return 0;
}