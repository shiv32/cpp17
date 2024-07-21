/*
    Single Responsibility Principle
        Class should have only one reason to change.

        g++ srp.cpp -o test
*/

#include <iostream>
#include <memory>

/*
//Violate SRP

class Notes
{
public:
    virtual void Add() = 0;
    virtual void Remove() = 0;
    virtual void Edit() = 0;
    virtual void Display() = 0;
    virtual ~Notes() = default;
};

*/

class Notes
{
public:
    virtual void Add() = 0;
    virtual void Remove() = 0;
    virtual void Edit() = 0;
    virtual ~Notes() = default;
};

class AddContact final : public Notes
{
public:
    void Add() override;
    void Remove() override;
    void Edit() override;
};

void AddContact::Add()
{
    std::cout << "Contact added successfully." << std::endl;
}

void AddContact::Remove()
{
    std::cout << "Contact removed successfully." << std::endl;
}

void AddContact::Edit()
{
    std::cout << "Contact edit successfully." << std::endl;
}

class View
{
public:
    void Display(std::unique_ptr<Notes> myNp);
};

void View::Display(std::unique_ptr<Notes> myNp)
{
    myNp->Add();
    myNp->Edit();
    myNp->Remove();
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::unique_ptr<AddContact> ac = std::make_unique<AddContact>();
    std::unique_ptr<View> vw = std::make_unique<View>();

    vw->Display(std::move(ac));

    return 0;
}