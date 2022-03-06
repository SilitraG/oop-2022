#pragma once
#include <iostream>

class Students
{
	const char* name;
	float math_grade;
	float english_grade;
	float history_grade;

public:
	void set_name(const char* string);
	const char* get_name();
	void set_math_grade(float grade);
	float get_math_grade();
	void set_english_grade(float grade);
	float get_english_grade();
	void set_history_grade(float grade);
	float get_history_grade();
	double average();
};