#include <cstdlib>
#include <cstdio>
#include "Math.h"

int main()
{
	Math math;
	printf("Add of 2 int nums: %d\n", math.Add(10, 20));
	printf("Add of 3 int nums: %d\n", math.Add(10, 20, 30));
	printf("Add of 2 double nums: %g\n", math.Add(10.13, 20.14));
	printf("Add of 3 double nums: %g\n", math.Add(10.13, 20.14, 30.33));
	printf("Mul of 2 nums: %d\n", math.Mul(10, 20));
	printf("Mul of 3 int nums: %d\n", math.Mul(10, 20, 3));
	printf("Mul of 2 double nums: %g\n", math.Mul(1.13, 20.14));
	printf("Mul of 3 double nums: %g\n", math.Mul(1.13, 20.14, 3.33));
	printf("Add of 'count' int nums: %d\n", math.Add(5, 10, 20, 30, 40, 50));
	printf("Add of 2 string: %s\n", math.Add("ion", "ion"));
	return 0;
}