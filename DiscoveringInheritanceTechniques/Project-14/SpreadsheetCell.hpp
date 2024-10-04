/**
 * @file SpreadsheetCell.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma Once

#include <string>

class SpreadsheetCell
{
public:
    virtual ~SpreadsheetCell() = default;
    virtual void set(std::string_view inString) = 0;
    virtual std::string getString() const = 0;
};
