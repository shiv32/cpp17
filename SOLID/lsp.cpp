/*
    Liskov Substitution Principle
        Objects of superclass can be should be replaceable with objects of subclass without
        altering the correctness of program.

        g++ lsp.cpp -o test

        g++ lsp.cpp -o test && ./test && rm test
*/

#include <iostream>
#include <exception>
#include <memory>

/*
// Violate lsp

class Bird {
    public:
        virtual void fly() = 0;
};

class Crow : public Bird {
    public:
        void fly() override {
            std::cout << "Crow is flying" << std::endl;
        }
};

class Penguin : public Bird {
    public:
        void fly() override {
            throw std::runtime_error("Penguins can't fly");
        }
};

void makeBirdFly(Bird& bird) {
    bird.fly();
}
*/

// follow lsp

class Bird
{
public:
    virtual bool canFly() = 0;
};

class FlyingBird : public Bird
{
public:
    bool canFly() override
    {
        return true;
    }
    virtual void fly() = 0;
};

class Crow : public FlyingBird
{
public:
    void fly() override
    {
        std::cout << "Crow is flying" << std::endl;
    }
};

class Penguin : public Bird
{
public:
    bool canFly() override
    {
        return false;
    }
};

// void makeBirdFly(FlyingBird &bird)
// {
//     bird.fly();
// }

// smart pointer
void makeBirdFly(std::unique_ptr<FlyingBird> bird)
{
    bird->fly();
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // Crow cr;
    // makeBirdFly(cr);

    // Penguin pn;
    // makeBirdFly(pn);  //compile time error

    //-------------(smart pointer)--------------------------------
    auto cr = std::make_unique<Crow>();
    makeBirdFly(std::move(cr));

    // auto pn = std::make_unique<Penguin>();
    // makeBirdFly(std::move(pn)); // compile time error

    return 0;
}