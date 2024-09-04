/**
 * @file Romance.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-09-04
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include "Paperback.hpp"

class Romance : public Paperback
{
public:
    virtual std::string getDescription() const override;
    virtual int getHeight() const override;
};