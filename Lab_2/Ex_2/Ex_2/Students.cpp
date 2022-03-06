#include "Students.h"

void Students::set_name(const char* string)
{
	name = string;
}

const char* Students::get_name()
{
	return name;
}

void Students::set_math_grade(float grade)
{
	math_grade = grade;
}

float Students::get_math_grade()
{
	return math_grade;
}

void Students::set_english_grade(float grade)
{
	english_grade = grade;
}

float Students::get_english_grade()
{
	return english_grade;
}

void Students::set_history_grade(float grade)
{
	history_grade = grade;
}

float Students::get_history_grade()
{
	return history_grade;
}

double Students::average()
{
	return (math_grade + english_grade + history_grade);
}
