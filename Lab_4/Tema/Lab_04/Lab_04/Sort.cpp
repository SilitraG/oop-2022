#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdarg.h>
#include <ostream>

Sort::Sort(unsigned num_count, int min, int max)
{
	num = new int[num_count];
	this->num_count = num_count;
	for (unsigned i = 0; i < num_count; i++)
	{
		num[i] = rand() % max + min;
	}
}

Sort::Sort(int* vector, unsigned num_count)
{
	num = new int[num_count];
	this->num_count = num_count;
	for (unsigned i = 0; i < num_count; i++)
	{
		num[i] = vector[i];
	}
}

Sort::Sort(unsigned num_count, ...)
{
	va_list args;
	va_start(args, num_count);
	num = new int[num_count];
	this->num_count = num_count;
	for (unsigned i = 0; i < num_count; i++)
	{
		num[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char* num_string)
{
	int cnt = 1;
	for (int i = 0; i < strlen(num_string); i++)
		if (num_string[i] == ',')
			++cnt;
	num_count = cnt;
	num = new int[cnt];
	unsigned index = 0;
	char* sir = new char[(strlen(num_string) + 1) * sizeof(char)];
	strcpy(sir, num_string);
	char* p = strtok(sir, ",");
	while (p != nullptr)
	{
		int numar = atoi(p);
		num[index] = numar;
		index++;
		p = strtok(nullptr, ",");
	}
	delete[] sir;
}

void Sort::InsertSort(bool ascendent)
{
	for (unsigned i = 1; i < num_count; i++)
	{
		int j = i - 1;
		int aux = num[i];
		while (j >= 0 && num[j] < aux)
		{
			num[j + 1] = num[j];
			j--;
		}
		if (num[j + 1] != aux)
		{
			num[j + 1] = aux;
		}
	}
}

int Sort::partitionare(int p, int q)
{
	int x = num[p];
	int i = p + 1;
	int j = q;
	while (i <= j)
	{
		if (num[i] >= x)
		{
			i++;
		}
		if (num[j] <= x)
		{
			j--;
		}
		if (i < j && num[i] < x && num[j] > x)
		{
			int aux = num[i];
			num[i] = num[j];
			num[j] = aux;
			i++;
			j--;
		}
	}
	int k = i - 1;
	num[p] = num[k];
	num[k] = x;
	return k;
}

void Sort::quicksort(int p, int q)
{
	int k;
	if (p < q)
	{
		k = partitionare(p, q);
		quicksort(p, k - 1);
		quicksort(k + 1, q);
	}
}

void Sort::QuickSort(bool ascendent)
{
	quicksort(0, num_count - 1);
}

void Sort::BubbleSort(bool ascendent)
{
	unsigned ultim = num_count - 1;
	while (ultim > 0)
	{
		unsigned n = ultim - 1;
		ultim = 0;
		for (unsigned i = 0; i <= n; i++)
		{
			if (num[i] < num[i + 1])
			{
				int aux = num[i];
				num[i] = num[i + 1];
				num[i + 1] = aux;
				ultim = i;
			}
		}
	}
}

void Sort::Print()
{
	if (num_count == 0)
	{
		printf("Nu exista elemente in vector");
	}
	for (unsigned i = 0; i < num_count; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}

int Sort::GetElementsCount()
{
	return num_count;
}

int Sort::GetElementFromIndex(int index)
{
	return num[index];
}
