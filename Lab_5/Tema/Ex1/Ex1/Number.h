#pragma once
#include <iostream>
class Number
{
	// add data members
	int base;
	char* value;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int value);
	Number();
	Number(const Number& num);
	Number(Number&& num);	
	~Number();
	// add operators and copy/move constructor

	friend Number operator+(const Number& num1, const Number& num2);
	friend Number operator-(const Number& num1, const Number& num2);

	char operator[](unsigned index);

	friend bool operator>(const Number& num1, const Number& num2);
	friend bool operator<(const Number& num1, const Number& num2);
	friend bool operator>=(const Number& num1, const Number& num2);
	friend bool operator<=(const Number& num1, const Number& num2);
	friend bool operator==(const Number& num1, const Number& num2);
	friend bool operator!=(const Number& num1, const Number& num2);
	friend Number& operator+=(Number& num1, const Number& num2);

	Number& operator=(int number);
	Number& operator=(const Number& num);
	Number& operator=(const char* value);

	Number& operator--();
	Number operator--(int);

	int From_char_to_int() const;
	void From_int_to_char(int value);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};




