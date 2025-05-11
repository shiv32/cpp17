#pragma once

#include <memory>

class Strategy;

class Context
{
private:
    std::unique_ptr<Strategy> strategy_;
   
public:
    explicit Context(std::unique_ptr<Strategy> &&strategy = {});
    void set_strategy(std::unique_ptr<Strategy> &&strategy);
    void doSomeBusinessLogic() const;
};