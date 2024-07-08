#include "Integer.h"

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux

	Integer a(1), b(3);

	Integer sum = a + b;

	std::cout << sum.GetValue() << std::endl;

	return 0;
}