/**
 * @file Larry.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include "Stooge.hpp"

class Larry : public Stooge
{
public:
    void slap_stick();
    Stooge *clone();
};