#pragma once

class Animal
{
public:
    /*
        The typeid operator only works correctly if the class has at least
        one virtual method, that is, when the class has a vtable.
    */
    virtual ~Animal() = default;
    //~Animal() = default;
};