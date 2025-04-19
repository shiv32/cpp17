#include "Director.hpp"

void Director::set_builder(Builder *builder)
{
    this->builder = builder;
}

void Director::BuildMinimalViableProduct()
{
    this->builder->ProducePartA();
}

void Director::BuildFullFeaturedProduct()
{
    this->builder->ProducePartA();
    this->builder->ProducePartB();
    this->builder->ProducePartC();
}
