#pragma once

class AbstractClass;

class ConcreteClass2 : public AbstractClass
{
protected:
    void RequiredOperations1() const override;
    void RequiredOperation2() const override;
    void Hook1() const override;
};