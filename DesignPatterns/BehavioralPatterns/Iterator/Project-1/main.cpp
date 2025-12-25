#include "ConcreteAggregate.h"
#include <iostream>

int main()
{
	system("clear && printf '\e[3J'"); // clean the terminal before output in linux

	ConcreteAggregate list{};

	list.Push(1);
	list.Push(2);
	list.Push(3);
	list.Push(4);
	list.Push(5);
	//list.Push(6) ; //assert fail

	auto iter{list.CreateIterator()};

	iter->First();

	while (!iter->IsDone())
	{
		std::cout << iter->CurrentItem() << ' ';
		iter->Next();
	}

	delete iter;
}
