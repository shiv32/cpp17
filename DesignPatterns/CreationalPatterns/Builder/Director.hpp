/**
 * @file Director.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include "Builder.hpp"

class Director
{
    /**
     * @var Builder
     */
private:
    Builder *builder;
    /**
     * The Director works with any builder instance that the client code passes
     * to it. This way, the client code may alter the final type of the newly
     * assembled product.
     */

public:
    void set_builder(Builder *builder);

    /**
     * The Director can construct several product variations using the same
     * building steps.
     */

    void BuildMinimalViableProduct();
    void BuildFullFeaturedProduct();
};