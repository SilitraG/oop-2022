#include "Global_functions.h"
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

int name_check(const char* string_1, const char* string_2)
{
	if (strcmp(string_1,string_2) == 0)
		return 0;
	else
		if (strcmp(string_1, string_2) > 0)
			return 1;
	return -1;
}

int math_grade_check(float grade_1, float grade_2)
{
	if (grade_1 == grade_2)
		return 0;
	else
		if (grade_1 > grade_2)
			return 1;
	return -1;
}

int english_grade_check(float grade_1, float grade_2)
{
	if (grade_1 == grade_2)
		return 0;
	else
		if (grade_1 > grade_2)
			return 1;
	return -1;
}

int history_grade_check(float grade_1, float grade_2)
{
	if (grade_1 == grade_2)
		return 0;
	else
		if (grade_1 > grade_2)
			return 1;
	return -1;
}

int average_check(double average_1, double average_2)
{
	if (average_1 == average_2)
		return 0;
	else
		if (average_1 > average_2)
			return 1;
	return -1;
}
