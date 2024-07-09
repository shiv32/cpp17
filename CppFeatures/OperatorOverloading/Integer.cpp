#include "Integer.h"

Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value)
{
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer &obj)
{
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer &&obj)
{
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const
{
	return *m_pInt;
}

void Integer::SetValue(int value)
{
	*m_pInt = value;
}

Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer &Integer::operator++()
{
	++(*m_pInt);
	return *this;
}

Integer Integer::operator++(int)
{
	Integer temp(*this);
	++(*m_pInt);
	return temp;
}

bool Integer::operator==(const Integer &a) const
{
	return *m_pInt == *a.m_pInt;
}

Integer &Integer::operator=(const Integer &a)
{
	if (this != &a)
	{
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}

Integer &Integer::operator=(Integer &&a)
{
	if (this != &a)
	{
		delete m_pInt;
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}

Integer Integer::operator+(const Integer &b) const
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	Integer temp;
	*temp.m_pInt = *m_pInt + *b.m_pInt;
	return temp;
}

void Integer::operator()()
{
	std::cout << *m_pInt << std::endl;
}

// Integer operator+(const Integer &a, const Integer &b)
// {
// 	std::cout << __PRETTY_FUNCTION__ << std::endl;

// 	Integer temp;
// 	temp.SetValue(a.GetValue() + b.GetValue());
// 	return temp;
// }

Integer operator+(int x, const Integer &y)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;

	Integer temp;
	temp.SetValue(x + y.GetValue());
	return temp;
}

std::ostream &operator<<(std::ostream &out, const Integer &a)
{
	out << a.GetValue();
	return out;
}

std::istream &operator>>(std::istream &input, Integer &a)
{
	int x;
	input >> x;
	a.SetValue(x);
	return input;
}
