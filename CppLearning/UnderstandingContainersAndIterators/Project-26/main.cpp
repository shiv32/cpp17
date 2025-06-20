/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief priority_queue Example: An Error Correlator
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <stack>

// Sample Error class with just a priority and a string error description.
class Error final
{
public:
    Error(int priority, std::string_view errorString)
        : mPriority(priority), mErrorString(errorString)
    {
    }

    int getPriority() const { return mPriority; }
    std::string_view getErrorString() const { return mErrorString; }

private:
    int mPriority;
    std::string mErrorString;
};

bool operator<(const Error &lhs, const Error &rhs);
std::ostream &operator<<(std::ostream &os, const Error &err);

// Simple ErrorCorrelator class that returns highest priority errors first.
class ErrorCorrelator final
{
public:
    // Add an error to be correlated.
    void addError(const Error &error);

    // Retrieve the next error to be processed.
    Error getError();

private:
    std::stack<Error> mErrors;
};

//----  definitions-------------

bool operator<(const Error &lhs, const Error &rhs)
{
    return (lhs.getPriority() < rhs.getPriority());
}

std::ostream &operator<<(std::ostream &os, const Error &err)
{
    os << err.getErrorString() << " (priority " << err.getPriority() << ")";
    return os;
}

void ErrorCorrelator::addError(const Error &error)
{
    mErrors.push(error);
}

Error ErrorCorrelator::getError()
{
    // If there are no more errors, throw an exception.
    if (mErrors.empty())
    {
        throw std::out_of_range("No more errors.");
    }

    // Save the top element.
    Error top = mErrors.top();

    // Remove the top element.
    mErrors.pop();

    // Return the saved element.
    return top;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    ErrorCorrelator ec;
    ec.addError(Error(3, "Unable to read file"));
    ec.addError(Error(1, "Incorrect entry from user"));
    ec.addError(Error(10, "Unable to allocate memory!"));

    while (true)
    {
        try
        {
            Error e = ec.getError();
            std::cout << e << std::endl;
        }
        catch (const std::out_of_range &)
        {
            std::cout << "Finished processing errors" << std::endl;
            break;
        }
    }

    return 0;
}