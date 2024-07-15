#include "Integer.h"

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux

	//------------------------------- (Basic) ------------------------------------------------
	Integer a(1), b(3);

	Integer sum = a + b;

	// or

	// Integer sum = a.operator+(b);

	//++sum;

	// std::cout << sum.GetValue() << std::endl;

	std::cout << (sum++).GetValue() << std::endl;

	std::cout << sum.GetValue() << std::endl;

	if (a == b) // if (a.operator==(b))
	{
		std::cout << "same" << std::endl;
	}
	else
	{
		std::cout << "not same" << std::endl;
	}

	//---------------------------------- (Assignment operator) ---------------------------------------------

	Integer c;

	// c = a;
	// or
	c.operator=(a); // call copy assignment operator

	std::cout << "c.GetValue() : " << c.GetValue() << std::endl;

	Integer d;

	// d = std::move(c);
	//  or
	d.operator=(std::move(c)); // call move assignment operator

	std::cout << "d.GetValue() : " << d.GetValue() << std::endl;

	//----------------------------------- (Global overloads) -----------------------------------------------

	Integer sum1 = a + 5;  //a.operator+(5)
	std::cout<<"sum1.GetValue() : "<< sum1.GetValue() << std::endl;

	Integer sum2 = 5 + a; // overlaod + global with premitive type will call
	std::cout<<"sum2.GetValue() : "<< sum2.GetValue() << std::endl;


	//std::cout<<"1. sum1.GetValue() << call : "<< sum1<< std::endl;
                       //or
	operator<<(std::cout,"2. sum1.GetValue() << call : ").operator<<(std::endl);;
	operator<<(std::cout,sum1).operator<<(std::endl);
	

	//std::cout<<"1. sum2.GetValue() << call : "<< sum2<< std::endl;
                          //or
	operator<<(std::cout,"2. sum2.GetValue() << call : ").operator<<(std::endl);
	operator<<(std::cout,sum2).operator<<(std::endl);

	//std::cin>>a;
	    //or
    operator>>(std::cin,a);

	std::cout<<"overload >>  : "<<std::endl<<a<<std::endl;

	std::cout<<"function call operator() : "; a();
	
	//--------------------------------------------------------------------


	return 0;
}