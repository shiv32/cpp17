#pragma once

class AbstractClass;

class ConcreteClass1 : public AbstractClass
{
protected:
    void RequiredOperations1() const override;
    void RequiredOperation2() const override;
};