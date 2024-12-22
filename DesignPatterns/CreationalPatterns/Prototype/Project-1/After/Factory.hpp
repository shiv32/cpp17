/**
 * @file Factory.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

class Stooge;

class Factory
{
public:
    static Stooge *make_stooge(int choice);

private:
    static Stooge *s_prototypes[4];
};
