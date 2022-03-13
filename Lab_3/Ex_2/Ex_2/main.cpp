#include <cstring>
#include <cstdlib>
#include <cstdio>
#include "Canvas.h"

int main()
{
	Canvas canvas(70, 20);
	canvas.SetPoint(0, 0, 200);
	canvas.DrawLine(2, 10, 8, 21, 124);
	canvas.DrawRect(1, 25, 15, 55, 61);
	canvas.FillRect(3, 28, 13, 52, 61);
	canvas.DrawCircle(6, 10, 5, 61);
	canvas.FillCircle(6, 10, 2, 61);
	canvas.Print();
	return 0;
}