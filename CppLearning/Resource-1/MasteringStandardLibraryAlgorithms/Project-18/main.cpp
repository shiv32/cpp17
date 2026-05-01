/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 *
 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <algorithm>
#include <functional>

namespace mmove
{
    class MyClass
    {
    public:
        MyClass() = default;
        MyClass(const MyClass &src) = default;
        MyClass(std::string_view str) : mStr(str) {}
        virtual ~MyClass() = default;

        // Move assignment operator
        MyClass &operator=(MyClass &&rhs) noexcept
        {
            if (this == &rhs)
                return *this;

            mStr = std::move(rhs.mStr);
            std::cout << "Move operator= (mStr=" << mStr << ")" << std::endl;
            return *this;
        }

        void setString(std::string_view str) { mStr = str; }
        std::string_view getString() const { return mStr; }

    private:
        std::string mStr;
    };

    void example1()
    {
        std::vector<MyClass> vecSrc{MyClass("a"), MyClass("b"), MyClass("c")};
        std::vector<MyClass> vecDst(vecSrc.size());

        move(begin(vecSrc), end(vecSrc), begin(vecDst));

        for (const auto &c : vecDst)
        {
            std::cout << c.getString() << " ";
        }
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    mmove::example1();
    
    return 0;
}