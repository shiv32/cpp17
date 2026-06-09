#include <iostream>
#include <vector>
#include <utility> //as_const

using namespace std;

namespace project1
{
    class FunctionObject
    {
    public:
        int operator()(int param);             // Function call operator int
        void operator()(std::string_view str); // Function call operator string_view
        int doSquare(int param);               // Normal method
    };

    // Implementation of overloaded function call operator
    int FunctionObject::operator()(int param)
    {
        return doSquare(param);
    }

    void FunctionObject::operator()(std::string_view str)
    {
        cout << str << "\n";
    }

    // Implementation of normal method
    int FunctionObject::doSquare(int param)
    {
        return param * param;
    }

    void test1()
    {
        int x = 3, xSquared, xSquaredAgain;

        FunctionObject square;

        xSquared = square(x); // Call the function call operator int
        cout << xSquared << "\n";

        xSquaredAgain = square.doSquare(x); // Call the normal method
        cout << xSquaredAgain << "\n";

        square("test"); // Call the function call operator string_view
    }
}

namespace project2
{
    // The function call operator can also be used to provide subscripting for multi-dimensional arrays.
    class Matrix
    {
    public:
        Matrix(std::size_t rows, std::size_t cols) : rows_(rows), cols_(cols), data_(rows * cols)
        {
        }

        int &operator()(std::size_t row, std::size_t col)
        {
            // return data_[row * cols_ + col];
            //or
            // A legitimate use of const_cast is to avoid duplicating code
            return const_cast<int &>(as_const(*this)(row, col));
        }

        const int &operator()(std::size_t row, std::size_t col) const
        {
            return data_[row * cols_ + col];
        }

    private:
        std::size_t rows_;
        std::size_t cols_;
        std::vector<int> data_;
    };

    void printMatrix(const Matrix &m)
    {
        std::cout << m(1, 2) << '\n';

        // m(1, 2) = 42; // Error
        // int x = m(1, 2); // OK (read only)
    }

    void test1()
    {
        Matrix m(3, 3);
        m(1, 2) = 42; // OK

        printMatrix(m);
    }
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    // project1::test1();
    project2::test1();

    return 0;
}