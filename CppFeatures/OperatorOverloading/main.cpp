#include "Integer.h"

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux

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

	return 0;
}