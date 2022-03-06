#include "Global_functions.h"
#include "Students.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Students student_1, student_2;
	while (1)
	{
		student_1.set_name("Luca");
		student_1.set_math_grade(3.14);
		student_1.set_english_grade(4.44);
		student_1.set_history_grade(7.12);

		student_2.set_name("Petru");
		student_2.set_math_grade(8.59);
		student_2.set_english_grade(1.30);
		student_2.set_history_grade(6.45);

		break;
	}

	///GLOBAL FUNCTIONS EXAMPLE

	if (name_check(student_1.get_name(), student_2.get_name()) == 0)
	{
		if (math_grade_check(student_1.get_math_grade(), student_2.get_math_grade()) == 0)
		{
			if (english_grade_check(student_1.get_english_grade(), student_2.get_english_grade()) == 0)
			{
				if (history_grade_check(student_1.get_history_grade(), student_2.get_history_grade()) == 0)
				{
					if (average_check(student_1.average(), student_2.average()) == 0)
					{
						return 0;
					}
					else
					{
						if (average_check(student_1.average(), student_2.average()) > 0)
							return 1;
						return -1;
					}
				}
				else
				{
					if (history_grade_check(student_1.get_history_grade(), student_2.get_history_grade()) > 0)
						return 1;
					return -1;
				}
			}
			else
			{
				if (english_grade_check(student_1.get_english_grade(), student_2.get_english_grade()) > 0)
					return 1;
				return -1;
			}
		}
		else
		{
			if (math_grade_check(student_1.get_math_grade(), student_2.get_math_grade()) > 0)
				return 1;
			return -1;
		}
	}
	else
	{
		if (name_check(student_1.get_name(), student_2.get_name()) > 0)
			return 1;
		return -1;
	}
}