#pragma once
#include <iostream>

class Integer
{
	int *m_pInt;

public:
	// Default constructor
	Integer();

	// Parameterized constructor
	Integer(int value);
	// explicit Integer(int value);

	// Copy constructor
	Integer(const Integer &obj);

	// Move constructor
	Integer(Integer &&obj);

	int GetValue() const;
	void SetValue(int value);

	// Destructor
	~Integer();

	// pre increment overload ++
	Integer &operator++();

	// post increment overload ++
	Integer operator++(int);

	// comparison
	bool operator==(const Integer &a) const;

	// Copy assignment
	Integer &operator=(const Integer &a);

	// Move assignment
	Integer &operator=(Integer &&a);

	// overlaod +
	Integer operator+(const Integer &b) const;

	// function call operator
	void operator()();

	//type conversion operator funtion
	//operator int();
	explicit operator int();

	// Friend function
	friend void PrintInteger(Integer &a);

	// Friend class
	friend class Printer;
};

// overlaod + global
// Integer operator +(const Integer &a, const Integer &b);

// overlaod + global with premitive type
Integer operator+(int x, const Integer &y);

std::ostream &operator<<(std::ostream &out, const Integer &a);

std::istream &operator>>(std::istream &input, Integer &a);

class Printer
{
public:
	Printer() = default;
	~Printer() = default;
	void displayClassIntegerData(Integer &intObj);
};