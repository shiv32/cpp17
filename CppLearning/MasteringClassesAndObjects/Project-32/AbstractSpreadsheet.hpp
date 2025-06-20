/**
 * @file AbstractSpreadsheet.hpp
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
#include <stdexcept>
#include "SpreadsheetCell.hpp"
#include <memory>
#include <vector>
#include <algorithm>

class AbstractSpreadsheet
{
public:
    virtual void setCellAt(size_t x, size_t y, const std::shared_ptr<SpreadsheetCell> &cell) = 0;
    virtual std::shared_ptr<SpreadsheetCell> &getCellAt(size_t x, size_t y) = 0;
    virtual const std::shared_ptr<SpreadsheetCell> &getCellAt(size_t x, size_t y) const = 0;
    virtual size_t getWidth() const = 0;
    virtual size_t getHeight() const = 0;
};
