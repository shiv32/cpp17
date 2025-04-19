#pragma once

#include "Builder.hpp"
#include "Product1.hpp"

class ConcreteBuilder1 : public Builder
{
private:
    Product1 *product;

    /**
     * A fresh builder instance should contain a blank product object, which is
     * used in further assembly.
     */
public:
    ConcreteBuilder1();

    ~ConcreteBuilder1();

    void Reset();

    /**
     * All production steps work with the same product instance.
     */

    void ProducePartA() const override;

    void ProducePartB() const override;

    void ProducePartC() const override;

    Product1 *GetProduct();
};