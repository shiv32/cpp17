#pragma once
#include <format>
#include <iostream>
#include <iterator>
#include "Numbers.hpp"
#include "Menu.hpp"

class NumbersInput : public BaseHandler
{
	Numbers m_Numbers{};

public:
	void RunIterationTask() override
	{
		OnDisplay(-1);
	}

	void OnEvent(int choice) override
	{
		switch (choice)
		{
		case 1: OnGenerateRandom(choice); break;
		case 2: OnAdd(choice); break;
		case 3: OnUpdate(choice); break;
		case 4: OnInsert(choice); break;
		case 5: OnRemove(choice); break;
		case 6: OnRemoveAll(choice); break;
		default:break;
		}
	}

	bool IsValidIndex(int index)
	{
		return (index < 0 || index >= m_Numbers.Size());
	}
	void OnAdd(int choice)
	{
		int x{};
		std::cout << "Enter the number to add:";
		std::cin >> x;
		m_Numbers.Add(x);
		std::cout << std::format("{} added to the list\n", x);
	}
	void OnGenerateRandom(int choice)
	{
		int count{};
		std::cout << "How many random m_Numbers to generate? ";
		std::cin >> count;
		m_Numbers.RemoveAll();
		for (int i = 0; i < count; ++i)
		{
			m_Numbers.Add(rand() % 100);
		}
		std::cout << "Generated " << count << " random m_Numbers.\n";
	}
	void OnUpdate(int choice)
	{
		if (m_Numbers.Empty())
		{
			std::cout << "No m_Numbers to update\n";
			return;
		}
		std::cout << "Enter the index of the number to update:";
		int index{};
		std::cin >> index;
		if (!IsValidIndex(index))
		{
			std::cout << "Invalid index!\n";
			return;
		}
		std::cout << "Enter new value:";
		int newValue{};
		std::cin >> newValue;
		auto oldValue = m_Numbers.GetAt(index);
		m_Numbers.Insert(index, newValue);
		std::cout << std::format("Updated index {} from {} to {}\n", index, oldValue, newValue);
	}
	void OnInsert(int choice)
	{
		int index{};
		std::cout << "Enter index to insert at: ";
		std::cin >> index;
		if (index < 0 || index > m_Numbers.Size())
		{
			std::cout << "Invalid index!\n";
			return;
		}
		int x{};
		std::cout << "Enter a number to insert: ";
		std::cin >> x;
		m_Numbers.Insert(index, x);
		std::cout << std::format("Inserted {} at index {}.\n", x, index);
	}
	void OnRemove(int choice)
	{
		if (m_Numbers.Empty())
		{
			std::cout << "No m_Numbers to remove.\n";
			return;
		}
		int x{};
		std::cout << "Enter the index : ";
		std::cin >> x;
		if (x < 0 || x >= m_Numbers.Size())
		{
			std::cout << "Invalid index!\n";
			return;
		}
		int removedValue = m_Numbers.GetAt(x);
		m_Numbers.Remove(x);
		std::cout << "Removed " << removedValue << " from the list.\n";
	}
	void OnRemoveAll(int choice)
	{
		if (m_Numbers.Empty())
		{
			std::cout << "No m_Numbers to remove.\n";
			return;
		}
		m_Numbers.RemoveAll();
		std::cout << "Removed all numbers from the list.\n";
	}
	void OnDisplay(int choice)
	{
		if (m_Numbers.Empty())
		{
			std::cout << "No numbers to display.\n";
			return;
		}
		std::cout << "Numbers in the list: ";
		for (int i = 0; i < m_Numbers.Size(); ++i)
		{
			std::cout << m_Numbers.GetAt(i) << " ";
		}
		std::cout << "\n";
	}

	bool OnExit() override
	{
		if (m_Numbers.Empty())
		{
			return true;
		}
		std::cout << "List is not empty!\n";
		return false;
	}
};
