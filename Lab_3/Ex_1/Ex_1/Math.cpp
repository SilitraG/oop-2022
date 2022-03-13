#include "Math.h"
#include <cstring>
#include <stdarg.h>
#include <cstdio>
#include <cstdlib>

int Math::Add(int nr_1, int nr_2)
{
	return nr_1 + nr_2;
}

int Math::Add(int nr_1, int nr_2, int nr_3)
{
	return nr_1 + nr_2 + nr_3;
}

double Math::Add(double nr_1, double nr_2)
{
	return nr_1 + nr_2;
}

double Math::Add(double nr_1, double nr_2, double nr_3)
{
	return nr_1 + nr_2 + nr_3;
}

int Math::Mul(int nr_1, int nr_2)
{
	return nr_1 * nr_2;
}

int Math::Mul(int nr_1, int nr_2, int nr_3)
{
	return nr_1 * nr_2 * nr_3;
}

double Math::Mul(double nr_1, double nr_2)
{
	return nr_1 * nr_2;;
}

double Math::Mul(double nr_1, double nr_2, double nr_3)
{
	return nr_1 * nr_2 * nr_3;
}

int Math::Add(int count, ...)
{
	int s, nr;
	va_list args;

	va_start(args, count);
	if (!count)
		return 0;
	s = va_arg(args, int);
	for (int i = 1; i < count; i++)
	{
		nr = va_arg(args, int);
		s += nr;
	}
	va_end(args);

	return s;
}

char* Math::Add(const char* string_1, const char* string_2)
{
	if(!string_1 || !string_2)
		return nullptr;

	int size_1 = strlen(string_1);
	int size_2 = strlen(string_2);
	char* new_string = (char*) malloc(size_1 + size_2 + 1);

	for (int i = 0; i < size_1; i++)
	{
		new_string[i] = string_1[i];

	}
	for (int i = 0; i <= size_2; i++)
	{
		new_string[size_1 + i] = string_1[i];
	}

	return new_string;
}
