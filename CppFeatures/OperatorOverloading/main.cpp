#include "Integer.h"
#include <memory>

class IntPtr // smart pointer class
{
	Integer *m_p;

public:
	IntPtr(Integer *p) : m_p(p)
	{
	}

	~IntPtr()
	{
		delete m_p;
	}

	Integer *operator->()
	{
		return m_p;
	}

	Integer &operator*()
	{
		return *m_p;
	}
};

class Product
{
	Integer m_Id;
	int x;

public:                         // memeber initializer list
	Product(const Integer &id) : m_Id(id), x(id.GetValue())
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
		// m_Id = id;  //call Integer& Integer::operator=(const Integer&)
	}

	~Product()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	const Integer &GetInteger() const
	{
		return m_Id;
	}

	operator Integer() // type conversion operator
	{
		return m_Id;
	}
};

void CreateInteger()
{
	Integer *p = new Integer;
	p->SetValue(3);
	std::cout << p->GetValue() << std::endl;
	delete p;
}

void CreateInteger2()
{
	IntPtr p = new Integer; // RAII Concept, bind Interger class to local object of class IntPtr
							// here p is like smart pointer

	p->SetValue(4); // operator-> called

	//(*p).SetValue(4); // operator* called

	std::cout << p->GetValue() << std::endl;
}

void Process(std::unique_ptr<Integer> ptr)
{
	std::cout << ptr->GetValue() << std::endl;
}

void Process2(std::shared_ptr<Integer> ptr)
{
	std::cout << ptr->GetValue() << std::endl;
}

void CreateInteger3()
{
	// std::unique_ptr<Integer> p(new Integer);
	std::unique_ptr<Integer> p = std::make_unique<Integer>(); // prefrred

	// auto p2(p); //compiler error copy constructor

	// IntPtr p = new Integer; 	 // RAII Concept, bind Interger class to local object of class IntPtr
	//  here p is like smart pointer

	p->SetValue(4); // operator-> called

	//(*p).SetValue(4); // operator* called

	Process(std::move(p));

	// std::cout << p->GetValue() << std::endl;
}

void CreateInteger4()
{
	// std::shared_ptr<Integer> p(new Integer);
	std::shared_ptr<Integer> p = std::make_shared<Integer>(); // prefrred

	// IntPtr p = new Integer;   // RAII Concept, bind Interger class to local object of class IntPtr
	//  here p is like smart pointer

	p->SetValue(4); // operator-> called

	//(*p).SetValue(4); // operator* called

	Process2(p);

	// std::cout << p->GetValue() << std::endl;
}

// void print(Integer a)
// {

// }

void print(const Integer &a)
{
}

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux

	//------------------------------- (Basic) ------------------------------------------------
	/*
	Integer a(1), b(3);

	Integer sum = a + b;

	// or

	// Integer sum = a.operator+(b);

	//++sum;

	// std::cout << sum.GetValue() << std::endl;

	//std::cout << (sum++).GetValue() << std::endl;

	//std::cout << sum.GetValue() << std::endl;

	if (a == b) // if (a.operator==(b))
	{
		std::cout << "same" << std::endl;
	}
	else
	{
		std::cout << "not same" << std::endl;
	}
	*/

	//---------------------------------- (Assignment operator) ---------------------------------------------

	/*
	Integer a(1);
	Integer c;

	 c = a;
	// or
	//c.operator=(a); // call copy assignment operator

	std::cout << "c.GetValue() : " << c.GetValue() << std::endl;

	Integer d;

	 d = std::move(c);
	//  or
	//d.operator=(std::move(c)); // call move assignment operator

	std::cout << "d.GetValue() : " << d.GetValue() << std::endl;
	 */

	//----------------------------------- (Global overloads) -----------------------------------------------

	// Integer a(17);

	// Integer sum1 = a + 5;
	// // or
	// // Integer sum1 = a.operator+(5);

	// std::cout << "sum1.GetValue() : " << sum1.GetValue() << std::endl;

	// Integer sum2 = 5 + a; // overlaod + global with premitive type will call
	// std::cout << "sum2.GetValue() : " << sum2.GetValue() << std::endl;

	// // std::cout<<"1. sum1.GetValue() << call : "<< sum1<< std::endl;
	// // // or
	// operator<<(std::cout, "2. sum1.GetValue() << call : ");
	// operator<<(std::cout, sum1).operator<<(std::endl);

	// // // std::cout<<"1. sum2.GetValue() << call : "<< sum2<< std::endl;
	// // // or
	// operator<<(std::cout, "2. sum2.GetValue() << call : ");
	// operator<<(std::cout, sum2).operator<<(std::endl);

	// //  // std::cin>>a;
	// //  // or
	// // operator>>(std::cin, a);

	// // std::cout << "overload >>  : " << a << std::endl;

	//  std::cout << "function call operator() : "<< std::endl;
	//  a();

	//-----------------------------------(Friend Keyword)---------------------------------
	// Integer a(17);

	// PrintInteger(a); // Friend function of Integer class

	// Printer pr; // Friend class of Integer class
	// pr.displayClassIntegerData(a);

	//------------------------------------(Smart Pointer Basics)-----------------------------

	// CreateInteger();
	// CreateInteger2();

	//------------------------------------(Smart Pointer in C++ 11)-----------------------------
	// CreateInteger3();
	// CreateInteger4();

	//------------------------------------(Type conversions Basics)-----------------------------
	// C++ casting operator work at compile time

	// int a1 = 5, b1 = 2;

	// float f = a1 / b1;

	// std::cout << f << std::endl;

	// f = (float)a1 / b1; // c style cast

	// std::cout << f << std::endl;

	// f = static_cast<float>(a1) / b1; // c++ style cast
	// 								 // static_cast -> check cast is valid or not

	// std::cout << f << std::endl;

	// char *p = &a1; //compiler error

	// char *p = (char *)&a1; // c style cast

	// char *p2 = static_cast<char *>(&a1);  //compiler error

	// char *p2 = reinterpret_cast<char *>(&a1); // reinterpret_cast -> allow casting between different types

	// const int x = 1;

	// int *p3 = &x;  //compiler error

	// int *p3 = (int *)&x; // c style cast discard qualifiers (eg. const)

	// int *p4 = reinterpret_cast<int *>(&x);  //c++ style cast dosnt discard qualifiers (eg. const)

	// int *p4 = const_cast<int *>(&x); // c++ style cast

	//----------------------------------(Type conversions primitive to user type)------------------------
	/*
	Constructors are used by compiler implicitly to convert one type (primitive) into another (user type).
	If you want to prevent compiler to use constructors implicitly, make constructor with "explicit" keyword.
	*/

	// Integer a2{5}; // explicit call parameterize ctor

	// Initialization
	// Integer a3 = 5;  //implicit call parameterize ctor

	// Integer a4 = "abc";

	// print(5);

	// Assignment
	// a2 = 7;

	//----------------------------------(Type conversions user to primitive type)------------------------
	// Integer a2{5}; // explicit call parameterize ctor

	// int x2 = a2; // implicitly call type conversion operator funtion {operator int();}
	// std::cout << "x2 : " << x2 << std::endl;

	// int x3 = static_cast<int>(a2); // explicitly call type conversion operator funtion {explicit operator int();}
	// std::cout<<"x3 : "<<x3<<std::endl;

	//----------------------------------(Type conversions user defined to user defined)------------------------

	// Product p1{5};

	// Integer id = p1; // without type conversion operator {operator Integer()} not working

	// Integer id = p1.GetInteger();

	// Integer id = p1; // with type conversion operator {operator Integer()}, implicitly call

	// id = p1; //with type conversion operator {operator Integer()}, implicitly call
	// or
	// id = p1.operator Integer();

	// Product pr1{10};
	// Integer id2{10};

	// if (id2 == pr1.GetInteger())
	// {
	// 	std::cout << "########## Id matches with the product" << std::endl;
	// }

	// if (id2 == pr1) // with type conversion operator {operator Integer()}, implicitly call
	// {
	// 	std::cout << "@@@@@@@@@@ Id matches with the product" << std::endl;
	// }

	//--------------(Initialization vs Assignment & Member Initialization list)--------------------

	/*
	// Initialization
	Integer a4{5};

	// Assignment
	a4 = 6; // a4 = Integer(6)

	std::cout<<"a4 : "<<a4<<std::endl;
	*/

	/*
	Integer a5;

	// Assignment
	a5 = 6;  //a5 = Integer(6)

	std::cout<<"a5 : "<<a5<<std::endl;
	*/

	Product pr1(5);

	return 0;
}