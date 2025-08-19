#pragma once
#include <vector>

class Numbers
{
	std::vector<int> m_Numbers{} ;
public:
	void Add(int value) ;
	void Update(std::size_t index, int newValue) ;
	void Remove(std::size_t index) ;
	void RemoveAll() ;
	void Insert(std::size_t index, int newValue) ;
	int GetAt(std::size_t index)const ;
	std::size_t Size()const ;
	bool Empty()const ;
};

