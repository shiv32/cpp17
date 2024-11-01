#pragma once

template <typename T>
class SpreadsheetCell
{
public:
    SpreadsheetCell(const T &t) : mContent(t)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    const T &getContent() const { return mContent; }

private:
    T mContent;
};

//user-defined deduction guide
SpreadsheetCell(const char *) -> SpreadsheetCell<std::string>;