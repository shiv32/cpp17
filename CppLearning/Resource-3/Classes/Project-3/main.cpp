#include <iostream>

namespace example1
{
    struct Date // representation
    {
        int d, m, y;

        void init(int dd, int mm, int yy); // initialize
        void add_year(int n);              // add n years
        void add_month(int n);             // add n months
        void add_day(int n);               // add n days
    };

    void Date::init(int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    }

    void Date::add_day(int n)
    {
        d = d + n;
    }

    Date my_birthday;

    void test()
    {
        Date d1 = my_birthday; // initialization by copy
        Date d2{my_birthday};  // initialization by copy
    }

    void f(Date &d)
    {
        d = my_birthday; // class objects can by default be copied by assignment
    }
}

namespace example2
{
    class Date
    {
        int d, m, y;

    public:
        void init(int dd, int mm, int yy); // initialize
        void add_year(int n);              // add n years
        void add_month(int n);             // add n months
        void add_day(int n);               // add n days
    };

    void Date::init(int dd, int mm, int yy)
    {
        d = dd;
        m = mm;
        y = yy;
    }

    void Date::add_year(int n)
    {
        y += n;
    }

    void timewarp(Date &d)
    {
        // d.y -= 200; //error Date::y is private
    }

    void test()
    {
        Date dx;
        // dx.m = 3; //error m is private
        dx.init(25, 3, 2011); // ok
    }

}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}