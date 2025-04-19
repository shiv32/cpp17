#include "ConcreteBuilder1.hpp"

ConcreteBuilder1::ConcreteBuilder1()
{
    this->Reset();
}

ConcreteBuilder1::~ConcreteBuilder1()
{
    delete product;
}

void ConcreteBuilder1::Reset()
{
    this->product = new Product1();
}

void ConcreteBuilder1::ProducePartA() const
{
    this->product->parts_.push_back("PartA1");
}

void ConcreteBuilder1::ProducePartB() const
{
    this->product->parts_.push_back("PartB1");
}

void ConcreteBuilder1::ProducePartC() const
{
    this->product->parts_.push_back("PartC1");
}

Product1 *ConcreteBuilder1::GetProduct()
{
    Product1 *result = this->product;
    this->Reset();
    return result;
}
