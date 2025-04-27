#include <iostream>
#include "FlyweightFactory.hpp"
#include "SharedState.hpp"

std::string FlyweightFactory::GetKey(const SharedState &ss) const
{
    return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
}

FlyweightFactory::FlyweightFactory(std::initializer_list<SharedState> share_states)
{
    for (const SharedState &ss : share_states)
    {
        this->flyweights_.insert(std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
        // this->flyweights_.emplace(this->GetKey(ss), Flyweight(&ss));
    }
}

Flyweight FlyweightFactory::GetFlyweight(const SharedState &shared_state)
{
    std::string key = this->GetKey(shared_state);

    if (this->flyweights_.find(key) == this->flyweights_.end())
    {
        std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
        this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
    }
    else
    {
        std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
    }

    return this->flyweights_.at(key);
}

void FlyweightFactory::ListFlyweights() const
{
    size_t count = this->flyweights_.size();

    std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
    
    for (std::pair<std::string, Flyweight> pair : this->flyweights_)
    {
        std::cout << pair.first << "\n";
    }
}
