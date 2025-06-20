#pragma once

#include <iostream>

class SpreadsheetApplication
{

public:
    SpreadsheetApplication() = default;
    std::string DefaultSheetName();
    std::string ConstDefaultSheetName() const;
};