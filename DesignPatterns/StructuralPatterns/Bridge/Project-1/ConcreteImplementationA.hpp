/**
 * @file ConcreteImplementationA.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-03-15
 *
 * @copyright Copyright (c) 2025
 *
 */

/**
 * Each Concrete Implementation corresponds to a specific platform and
 * implements the Implementation interface using that platform's API.
 */
#pragma once
#include "Implementation.hpp"

class ConcreteImplementationA : public Implementation
{
public:
    std::string OperationImplementation() const override;
};