#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <string.h>

Number::Number(const char* value, int base)
{
	this->base = base;
	this->value = new char[strlen(value) + 1];
	for (unsigned index = 0; index <= strlen(value); index++)
	{
		this->value[index] = value[index];
	}
}

Number::Number(int value)
{
	base = 10;
	int aux = value, length = 0, inv = 0;
	while (aux)
	{
		inv = inv * 10 + aux % 10;
		aux /= 10;
		length++;
	}
	this->value = new char[length + 1];
	unsigned index = 0;
	while (inv)
	{
		this->value[index] = (char)(inv % 10 + 48);
		index++;
		inv /= 10;
	}
	this->value[index] = 0;
}

Number::Number()
{
	base = 0;
	value = nullptr;
}

Number::Number(const Number& num)
{
	this->base = num.base;
	this->value = new char[strlen(num.value) + 1];
	for (unsigned index = 0; index <= strlen(num.value); index++)
	{
		this->value[index] = num.value[index];
	}
}

Number::Number(Number&& num)
{
	char* aux = num.value;
	num.value = nullptr;
	this->value = aux;
	this->base = num.base;
}

Number::~Number()
{
	delete value;
}

char Number::operator[](unsigned index)
{
	return value[index];
}

Number& Number::operator=(int number)
{
	base = 10;
	From_int_to_char(number);
	return *this;
}

Number& Number::operator=(const Number& num)
{
	base = num.base;
	strcpy(value, num.value);
	return *this;
}

Number& Number::operator=(const char* value)
{
	strcpy(this->value, value);
	return *this;
}

Number& Number::operator--()
{
	value[strlen(value) - 1] = 0;
	return *this;
}

Number Number::operator--(int)
{
	strcpy(value, value + 1);
	return *this;
}

Number operator+(const Number& num1, const Number& num2)
{
	Number rez;
	if (num1.base > num2.base)
		rez.base = num1.base;
	else
		rez.base = num2.base;
	int number_1 = num1.From_char_to_int();
	int number_2 = num2.From_char_to_int();

	rez.From_int_to_char(number_1 + number_2);

	return rez;
}

Number operator-(const Number& num1, const Number& num2)
{
	Number rez;
	if (num1.base > num2.base)
		rez.base = num1.base;
	else
		rez.base = num2.base;
	int number_1 = num1.From_char_to_int();
	int number_2 = num2.From_char_to_int();

	rez.From_int_to_char(number_1 - number_2);
	return rez;
}

bool operator>(const Number& num1, const Number& num2)
{
	int number_1 = num1.From_char_to_int();
	int number_2 = num2.From_char_to_int();
	return (number_1 > number_2);
}

bool operator<(const Number& num1, const Number& num2)
{
	int number_1 = num1.From_char_to_int();
	int number_2 = num2.From_char_to_int();
	return (number_1 < number_2);
}

bool operator>=(const Number& num1, const Number& num2)
{
	return !(num1 < num2);
}

bool operator<=(const Number& num1, const Number& num2)
{
	return !(num1 > num2);
}

bool operator==(const Number& num1, const Number& num2)
{
	return !(num1 < num2) && !(num1 > num2);
}

bool operator!=(const Number& num1, const Number& num2)
{
	return !(num1 == num2);
}

Number& operator+=(Number& num1, const Number& num2)
{
	Number rez;
	rez = num1 + num2;
	return rez;
}

int Number::From_char_to_int() const
{
	int numar = 0;
	for (int index = strlen(value) - 1; index >= 0; index--)
	{
		if (value[index] >= '0' && value[index] <= '9')
			numar += (int)(value[index] - 48) * pow(base, (strlen(value) - 1 - index));
		else
			numar += (int)(value[index] - 55) * pow(base, (strlen(value) - 1 - index));
	}
	return numar;
}

void Number::From_int_to_char(int value)
{
	int aux = value, cnt = 0;
	while (aux)
	{
		aux /= 10;
		cnt++;
	}

		this->value = new char[cnt*10];
	this->value[0] = '\0';
	int poz = 1;
	while (value)
	{
		int rest = value % base;
		value /= base;
		if (rest < 10)
			rest += 48;
		else
			rest += 55;
		strcpy(this->value + 1, this->value);
		this->value[poz] = '\0';
		poz++;
		this->value[0] = (char)rest;
	}
	
}

void Number::SwitchBase(int newBase)
{
	if (newBase != base)
	{
		int number = From_char_to_int();
		value = nullptr;
		delete value;
		base = newBase;
		From_int_to_char(number);
	}
	
}

void Number::Print()
{
	printf("%s\n", value);
}

int Number::GetDigitsCount()
{
	return strlen(value);
}

int Number::GetBase()
{
	return base;
}

