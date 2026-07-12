#include <iostream>

namespace example1
{
    class X // is called a class definition; it defines a type called X.
    {
    };

    /*
        struct is a class in which members are by default public.
        simply shorthand for
        class S { public: };
    */
    struct S
    {
    };

    // By default, members of a class are private.
    class Date1
    {
        int d, m, y; // private by default
    public:
        Date1(int dd, int mm, int yy);
        void add_year(int n); // add n years
    };

    // Except for the different name, Date1 and Date2 are equivalent.
    struct Date2
    {
    private:
        int d, m, y;

    public:
        Date2(int dd, int mm, int yy);
        void add_year(int n); // add n years
    };

    /*
        It is not a requirement to declare data first in a class.
        I usually prefer the style used for Date3.
    */
    class Date3
    {
    public:
        Date3(int dd, int mm, int yy);
        void add_year(int n); // add n years
    private:
        int d, m, y;
    };

    // Access specifiers can be used many times in a single class declaration.
    class Date4
    {
    public:
        Date4(int dd, int mm, int yy);

    private:
        int d, m, y;

    public:
        void add_year(int n); // add n years
    };

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}