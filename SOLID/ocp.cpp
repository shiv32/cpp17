/*
 Software Components (such as classes, modules, function, etc) should be open for extension but close for modifications.
*/

#include <iostream>
#include <memory>

/*
//violate OCP

class Notes
{
public:
    void Add();
    ~Notes() = default;
};

*/

class Notes
{
public:
    virtual void Add();
    virtual ~Notes() = default;
};

void Notes::Add()
{
    std::cout << "Add in Note class." << std::endl;
}

class AddContact : public Notes
{
public:
    void Add() override;
};

void AddContact::Add()
{
    std::cout << "Add extended in AddContact class." << std::endl;
}

int main()
{
    std::unique_ptr<Notes> np = std::make_unique<Notes>();
    std::unique_ptr<AddContact> ap = std::make_unique<AddContact>();
    np->Add();
    ap->Add();
    return 0;
}