#include <iostream>
#include <memory>

// --- Abstract base class for all states ---
class State
{
public:
	virtual ~State() = default;
	virtual void enter() = 0;
	virtual void update() = 0;
	virtual std::unique_ptr<State> next() = 0;
};

// --- Concrete states ---
class RedState : public State
{
public:
	void enter() override { std::cout << "State: RED\n"; }
	void update() override { std::cout << "Stop! Waiting...\n"; }
	std::unique_ptr<State> next() override;
};

class GreenState : public State
{
public:
	void enter() override { std::cout << "State: GREEN\n"; }
	void update() override { std::cout << "Go!\n"; }
	std::unique_ptr<State> next() override;
};

class YellowState : public State
{
public:
	void enter() override { std::cout << "State: YELLOW\n"; }
	void update() override { std::cout << "Slow down!\n"; }
	std::unique_ptr<State> next() override;
};

// --- State transitions ---
std::unique_ptr<State> RedState::next() { return std::make_unique<GreenState>(); }
std::unique_ptr<State> GreenState::next() { return std::make_unique<YellowState>(); }
std::unique_ptr<State> YellowState::next() { return std::make_unique<RedState>(); }

// --- Context class controlling state transitions ---
class TrafficLight
{
	std::unique_ptr<State> current;

public:
	TrafficLight() : current(std::make_unique<RedState>())
	{
		
	}

	void cycle()
	{
		current->enter();
		current->update();
		current = current->next();
	}
};

// --- Main demo ---
int main()
{
	TrafficLight light;

	for (int i = 0; i < 5; ++i)
	{
		light.cycle();
	}
}
