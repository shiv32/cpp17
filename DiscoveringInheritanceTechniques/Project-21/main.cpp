/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief Inherited Constructors
            Use of the using keyword to explicitly include the base class
            definition of a method within a derived class.

            This works perfectly fine for normal class methods,
            but it also works for constructors, allowing you to inherit constructors 
            from your base classes.

                eg.
                    class Base
                    {
                        public:
                        virtual ~Base() = default;
                        Base() = default;
                        Base(std::string_view str);
                    };

                    class Derived : public Base
                    {
                        public:
                        Derived(int i);
                    };

                You cannot construct Derived objects using the constructor accepting a
                string_view defined in the Base class.

                    Base base("Hello"); // OK, calls string_view Base ctor
                    Derived derived1(1); // OK, calls integer Derived ctor
                    Derived derived2("Hello"); // Error, Derived does not inherit string_view ctor

                If you would like the ability to construct Derived objects using the string_view-based Base 
                constructor, you can explicitly inherit the Base constructors in the Derived class as follows:

                    class Derived : public Base
                    {
                        public:
                        using Base::Base;
                        Derived(int i);
                    }
                
                The using statement inherits all constructors from the parent class except the default constructor,
                so now you can construct Derived objects in the following two ways:

                    Derived derived1(1); // OK, calls integer Derived ctor
                    Derived derived2("Hello"); // OK, calls inherited string_view Base ctor

                The Derived class can define a constructor with the same parameter list as one of the inherited
                constructors in the Base class. 
                In this case, as with any override, the constructor of the Derived class takes precedence over 
                the inherited constructor.

                    eg. 
                        class Base
                        {
                            public:
                            virtual ~Base() = default;
                            Base() = default;
                            Base(std::string_view str);
                            Base(float f);
                        };

                        class Derived : public Base
                        {
                            public:
                            using Base::Base;
                            Derived(float f); // Overrides inherited float Base ctor
                        };

                        Objects of Derived can be created as follows:

                            Derived derived1("Hello"); // OK, calls inherited string_view Base ctor
                            Derived derived2(1.23f); // OK, calls float Derived ctor

                A few restrictions apply to inheriting constructors from a base class with the using clause.

                When you inherit a constructor from a base class, you inherit all of them, except the default constructor.
                It is not possible to inherit only a subset of the constructors of a base class.

                A second restriction is related to multiple inheritance. 
                It’s not possible to inherit constructors from one of the base classes
                if another base class has a constructor with the same parameter list, because this leads to ambiguity.
                To resolve this, the Derived class needs to explicitly define the conflicting constructors.

                eg. 
                    class Base1
                    {
                        public:
                        virtual ~Base1() = default;
                        Base1() = default;
                        Base1(float f);
                    };

                    class Base2
                    {
                        public:
                        virtual ~Base2() = default;
                        Base2() = default;
                        Base2(std::string_view str);
                        Base2(float f);
                    };

                    class Derived : public Base1, public Base2
                    {
                        public:
                        using Base1::Base1;
                        using Base2::Base2;
                        Derived(char c);
                    };

                    The first using clause in Derived inherits all constructors from Base1. 
                    This means that Derived gets the following constructor:
                    
                    Derived(float f); // Inherited from Base1

                    With the second using clause in Derived, you are trying to inherit all constructors from
                    Base2. 
                    this causes a compilation error because this means that Derived gets a second
                    Derived(float f) constructor. 
                    The problem is solved by explicitly declaring conflicting constructors in the Derived class.

                        class Derived : public Base1, public Base2
                        {
                            public:
                            using Base1::Base1;
                            using Base2::Base2;
                            Derived(char c);
                            Derived(float f);
                        };

                    If you want, this explicitly declared constructor in the Derived class accepting
                    a float parameter can still forward the call to both the Base1 and Base2 constructors
                    in its ctor initializer as follows:

                        Derived::Derived(float f) : Base1(f), Base2(f) {}

                    When using inherited constructors, make sure that all member variables are properly initialized. 


                     eg. 
                        This example does not properly initialize the mInt data member in all cases, which is a serious error.

                        class Base
                        {
                            public:
                            virtual ~Base() = default;
                            Base(std::string_view str) : mStr(str) {}
                            private:
                            std::string mStr;
                        };

                        class Derived : public Base
                        {
                            public:
                            using Base::Base;
                            Derived(int i) : Base(""), mInt(i) {}
                            private:
                            int mInt;
                        };

                        You can create a Derived object as follows:
                        
                            Derived s1(2);

                        This calls the Derived(int i) constructor, which initializes the mInt data member of the Derived
                        class and calls the Base constructor with an empty string to initialize the mStr data member.

                        Because the Base constructor is inherited in the Derived class, you can also construct a Derived
                        object as follows:

                            Derived s2("Hello World");

                        This calls the inherited Base constructor in the Derived class.
                        However, this inherited Base constructor only initializes mStr of the Base class,
                        and does not initialize mInt of the Derived class,
                        leaving it in an uninitialized state. This is not recommended!

                        The solution in this case is to use in-class member initializers.

                        The following code uses an in-class member initializer to initialize mInt to 0. 

                        The Derived(int i) constructor can still change this and initialize mInt to the
                        constructor parameter i.

                            class Derived : public Base
                            {
                                public:
                                using Base::Base;
                                Derived(int i) : Base(""), mInt(i) {}
                                private:
                                int mInt = 0;
                            };


 * @version 0.1
 * @date 2024-09-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    return 0;
}