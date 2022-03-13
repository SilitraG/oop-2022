#include "Canvas.h"
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	Clear();
}

/// Credits for DrawCircle
/// https://stackoverflow.com/questions/46183003/c-creating-an-outline-of-a-circle-using-multiple-lines

void Canvas::DrawCircle(int x, int y, int ray, char ch) 
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			int circle_x, circle_y;
			circle_x = j - x;
			circle_y = y - i;
			int sum = circle_x * circle_x + circle_y * circle_y;
			if ((ray * ray) - 3 < sum && sum < (ray * ray) + 3)
			{
				SetPoint(i, j, ch);
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int circle_x, circle_y;
			circle_x = j - x;
			circle_y = y - i;
			int sum = circle_x * circle_x + circle_y * circle_y;
			if (sum <= ray * ray)
			{
				SetPoint(i, j, ch);
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, top, left, bottom, ch);
	DrawLine(left, bottom, right, bottom, ch);
	DrawLine(left, top, right, top, ch);
	DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		for (int j = top; j <= bottom; j++)
		{
			SetPoint(i, j, ch);
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	picture[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int x, y;
	if (y1 == y2)
	{
		y = y1;
		if (x1 > x2)
		{
			int aux = y1;	y1 = y2;	y2 = aux;
			aux = x1;	x1 = x2;	x2 = aux;
		}
		for (x = x1; x <= x2; x++)
		{
			SetPoint(x, y, ch);
		}
	}
	else
	{
		if (y1 > y2)
		{
			int aux = y1;	y1 = y2;	y2 = aux;
			aux = x1;	x1 = x2;	x2 = aux;
		}
		for (y = y1; y <= y2; y++)
		{
			x = (x1 - x2) * (y - y2) / (y1 - y2) + x2;
			SetPoint(x, y, ch);
		}
	}
	
}

void Canvas::Print()
{
	for (unsigned i = 0; i < height; i++)
	{
		for (unsigned j = 0; j < width; j++)
		{
			printf("%c", picture[i][j]);
		}
		printf("\n");
	}
}

void Canvas::Clear()
{
	memset(picture, ' ', sizeof(picture));
}
