/**
 * @file SpreadsheetApplication.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <iostream>

class SpreadsheetApplication
{

public:
    SpreadsheetApplication() = default;
    std::string DefaultSheetName();
    std::string ConstDefaultSheetName() const;
};