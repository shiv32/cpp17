/**
 * @file Stooge.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-12-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

class Stooge
{
public:
    virtual Stooge *clone() = 0;
    virtual void slap_stick() = 0;
};