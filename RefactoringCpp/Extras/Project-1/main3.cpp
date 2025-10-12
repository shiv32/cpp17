#include <iostream>

//Inheritance from a base currency class

class Currency
{
public:
    virtual std::string name() const = 0;
    virtual ~Currency() = default;
};

class USD : public Currency
{
public:
    std::string name() const override 
    { 
        return "USD"; 
    }
};

class Euro : public Currency
{
public:
    std::string name() const override 
    { 
        return "EUR"; 
    }
};

// USD and Euro can still be mixed inadvertently

int main(int argc, char *argv[])
{

    return 0;
}