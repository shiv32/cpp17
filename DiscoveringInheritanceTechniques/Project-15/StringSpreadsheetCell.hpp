#pragma once

#include <optional>
#include "SpreadsheetCell.hpp"

class StringSpreadsheetCell : public SpreadsheetCell
{
public:
    virtual void set(std::string_view inString) override;
    virtual std::string getString() const override;

private:
    std::optional<std::string> mValue;
};