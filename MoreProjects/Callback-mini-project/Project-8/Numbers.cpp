#include "Numbers.hpp"
#include <cassert>

void Numbers::Add(int value) {
	m_Numbers.push_back(value) ;
}

void Numbers::Update(std::size_t index, int newValue) {
	assert(index < m_Numbers.size()) ;
	m_Numbers[index] = newValue ;
}

void Numbers::Remove(std::size_t index) {
	assert(index < m_Numbers.size()) ;
	m_Numbers.erase(m_Numbers.begin() + index) ;
}

void Numbers::RemoveAll() {
	m_Numbers.clear() ;
}

void Numbers::Insert(std::size_t index, int newValue) {
	assert(index < m_Numbers.size()) ;
	m_Numbers.insert(m_Numbers.begin() + index, newValue) ;
}

int Numbers::GetAt(std::size_t index) const {
	return m_Numbers[index];
}

std::size_t Numbers::Size() const {
	return m_Numbers.size();
}

bool Numbers::Empty() const {
	return m_Numbers.empty();
}
