#pragma once

class SharedState;
class UniqueState;

class Flyweight
{
private:
    SharedState *shared_state_;

public:
    Flyweight(const SharedState *shared_state);
    Flyweight(const Flyweight &other);
    
    ~Flyweight();

    SharedState *shared_state() const;
    void Operation(const UniqueState &unique_state) const;
};