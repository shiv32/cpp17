/*
Objects of superclass can be should be replaceable with objects of subclass without altering the correctness of program
*/

#include <iostream>
#include <exception>

/*
// breakng lsp
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

void makeBirdFly(FlyingBird &bird)
{
    bird.fly();
}

int main()
{

    Crow cr;
    makeBirdFly(cr);

    Penguin pn;
    // makeBirdFly(pn);  //compile time error

    return 0;
}