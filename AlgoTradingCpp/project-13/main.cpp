#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>
#include <ctime>

enum class MarketState
{
    UP,
    DOWN,
    STABLE
};

std::string toString(MarketState state)
{
    switch (state)
    {
    case MarketState::UP:
        return "UP";
    case MarketState::DOWN:
        return "DOWN";
    case MarketState::STABLE:
        return "STABLE";
    default:
        return "UNKNOWN";
    }
}

class MarkovModel
{
    std::unordered_map<MarketState, std::vector<std::pair<MarketState, double>>> transitions;
    std::mt19937 rng;

public:
    MarkovModel()
    {
        rng.seed(static_cast<unsigned>(time(nullptr)));

        transitions[MarketState::UP] = {
            {MarketState::UP, 0.4},
            {MarketState::DOWN, 0.3},
            {MarketState::STABLE, 0.3}};
        transitions[MarketState::DOWN] = {
            {MarketState::UP, 0.2},
            {MarketState::DOWN, 0.5},
            {MarketState::STABLE, 0.3}};
        transitions[MarketState::STABLE] = {
            {MarketState::UP, 0.3},
            {MarketState::DOWN, 0.3},
            {MarketState::STABLE, 0.4}};
    }

    MarketState nextState(MarketState current)
    {
        std::uniform_real_distribution<> dist(0.0, 1.0);
        double rnd = dist(rng);
        double cumulative = 0.0;

        for (const auto &pair : transitions[current])
        {
            cumulative += pair.second;
            if (rnd < cumulative)
                return pair.first;
        }
        return current; // fallback
    }

    void simulate(MarketState start, int steps)
    {
        MarketState state = start;
        std::cout << "Start: " << toString(state) << "\n";
        for (int i = 0; i < steps; ++i)
        {
            state = nextState(state);
            std::cout << "Step " << i + 1 << ": " << toString(state) << "\n";
        }
    }
};

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    MarkovModel model;
    model.simulate(MarketState::STABLE, 10);
    return 0;
}
