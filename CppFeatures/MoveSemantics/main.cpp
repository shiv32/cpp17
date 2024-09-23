#include <iostream>
#include "Integer.h"

/*

Table -->

cc : copy ctor
ca : copy assignment
mc : move ctor
ma : move assigmnet
dtor : destructor

custom			cc			ca			mc			ma			dtor

cc			custom			default		delete		delete		default

ca			default			custom		delete		delete		default

mc			delete			delete		custom		delete		default

ma			delete			delete		delete		custom		default

dtor		default			default		delete		delete		custom

none		default			default		default		default		default

*/

class Number
{
	Integer m_Value{};

public:
	Number() = default;
	Number(int value) : m_Value{value}
	{
	}

	// Number(const Number &n) : m_Value{n.m_Value}  //due to copy ctor move operation will be deleted
	// {
	// }

	// ~Number() //due to dtor move operation will be deleted
	// {
	// }

	// Number(Number &&n):m_Value{std::move(n.m_Value)}  //due to move ctor copy operation/move assignment will be deleted
	// {
	// }

	// custom implementations
	Number(Number &&n) = default;
	Number(const Number &n) = default;
	Number &operator=(Number &&) = default;
	Number &operator=(const Number &) = default;
};

Number CreateNumber(int num)
{
	Number n{num};

	return n;
}

Integer Add(const Integer &a, const Integer &b)
{
	Integer temp;

	temp.SetValue(a.GetValue() + b.GetValue());

	return temp;
}

Integer Add2(int a, int b)
{
	// Integer temp(a + b);
	// return temp; //Named return value optimization

	return Integer(a + b); // Return value optimization (always preffer this)
}

/*
return r-value
*/
int Add(int x, int y)
{
	return x + y;
}

/*
return l-value
*/
int &Transform(int &x)
{
	x *= x;
	return x;
}

void print1(Integer val)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void print2(int a)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void print(int &x)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void print(const int &x)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void print(int &&x)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux

	//----------------------------------(L-valu, R-value, R-value reference)-----------------------------------------------

	/*
	x,y,z --> l-values
	5,10,8 --> r-values
	*/
	// int x = 5;
	// int y = 10;
	// int z = 8;

	/*
	 expression returns r-value
	*/
	// int result = (x + y) * z;

	/*
	 expression reteun l-value
	*/
	// ++x = 6;

	/*
	r-value refernces
	*/
	// int &&r1 = 20;		  // r-value reference
	// int &&r2 = Add(6, 7); // Add retuen by value(temporary)
	// int &&r3 = 8 + 2;	  // expression return a temporary

	// int &&r4 = x  //error

	/*
	l-value reference
	*/
	// int &ref = x;
	// int &ref2 = Transform(x);
	// const int &ref3 = 3;

	//--------------------------------------------------------
	// int x = 5;

	// print(x);

	// print(30);

	//----------------------------(move semantics basic and implementation)-------------------------
	/*
		Disable Copy Elision -->
		g++ -fno-elide-constructors *.cpp -o test
		g++ -fno-elide-constructors *.cpp -o test && ./test && rm test

		Note: cmake may behave differently for same flag "-fno-elide-constructors".
			  Chekc CMakeLists.txt file.
	*/
	Integer a(1), b(3);

	a.SetValue(Add(a, b).GetValue());

	//-------------------------(rule of 5 & 0)----------------------
	// Number n1{1};
	// Number n1;

	// auto n2{n1};

	// n2 = n1;

	// auto n3{CreateNumber(3)};

	// n3 = CreateNumber(3);

	//--------------------------(copy elision)------------------------
	/*
		Disable Copy Elision -->
		g++ -fno-elide-constructors *.cpp -o test
		g++ -fno-elide-constructors *.cpp -o test && ./test && rm test

		Note: cmake may behave differently for same flag "-fno-elide-constructors".
			  Check CMakeLists.txt file.
	*/

	/*
		Here user defined object a is initialized with primitive type literal 3 using
		assignment operator.
		compiler may expand it as: Integer a = Integer(3);
	*/
	// Integer a = 3;

	// Integer a = Add2(3, 5);

	//-----------------------------(std::move fun)----------------------------------
	// Integer a(1);
	// auto b{a};  //call copy ctor bcoz a is L-value

	// a.SetValue(3);

	// auto b{static_cast<Integer&&>(a)};  //call move ctor for L-value; type cast L-value(a) to R-value
	// or
	// auto b{std::move(a)}; // call move ctor for L-value; it type cast L-value(a) to R-value

	// print1(a);  //copy the resource and resoure will be released when main fun complete
	// print1(std::move(a)); // move the resource and resoure will be released when print1 fun complete

	// std::cout<<a.GetValue()<<std::endl; //program will crash bcoz a resource has been moved & now its conain null

	// a.SetValue(5);

	// std::cout << a.GetValue() << std::endl; // program will crash bcoz a resource has been moved & now its conain null

	// print1(a); //if we remove copy ctor then it will not work;eg. file stream class object we cant copy

	// std::move uses with primitive type is redunded.
	// std::move with primitive type will call copy not move fun
	// print2(std::move(2));

	return 0;
}