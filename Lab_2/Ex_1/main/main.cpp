#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "NumberList.h"

int main()
{
	NumberList v;
	v.Init();

	for (int i = 0; i <= 24; i+=2)
	{
		if (!v.Add(i))
		{
			std::cout << "Error!\nCan't add more numbers\n\n";
			break;
		}
	}
	v.Sort();
	v.Print();
	return 0;
}