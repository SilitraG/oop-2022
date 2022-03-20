#include "Sort.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Sort v1 = { "3,8,2,1,9,6" };
	Sort v2 = { 10, 1, 100 };
	int vector[] = {8, 4, 6, 1, 9, 5, 20, 15};
	Sort v3 = { vector, 8 };
	Sort v4 = { 10, 8, 1, 4, 3, 9, 6, 2, 7, 5, 10 };

	v1.QuickSort();
	v1.Print();

	v2.InsertSort();
	v2.Print();

	v3.BubbleSort();
	v3.Print();

	v4.InsertSort();
	for(unsigned i = 0; i < v4.GetElementsCount(); i++)
	{
		printf("%d ", v4.GetElementFromIndex(i));
	}
}