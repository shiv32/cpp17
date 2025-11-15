#include <iostream>

struct Foo
{

    Foo()
    {
        std::clog << "foo ctor" << std::endl;
    }

    ~Foo()
    {
        std::clog << "foo dtor" << std::endl;
    }
};

int main()
{

    // Foo *myFoo = (Foo *)malloc(sizeof(Foo));
    // free(myFoo);

    Foo* myOtherFoo = new Foo();
    delete myOtherFoo;

    return 0;
}
