#include <cstdio>
#include "include.h"
#include "Triangle.h"

triangle::triangle()
{
	int random = (rand() % 4) + 1;

	switch (random)
	{
	case 1:
		this->color = green;
		break;
	case 2:
		this->color = blue;
		break;
	case 3:
		this->color = red;
		break;
	default:
		this->color = yellow;
	}
} 

triangleColor triangle::getColor()
{
	return this->color;
}

void triangle::setColor(triangleColor color)
{
	this->color = color;
}

orientationEnum triangle::getOrientation()
{
	return this->orientation;
}

void triangle::setOrientation(orientationEnum orientation)
{
	this->orientation = orientation;
}

void triangle::rotate()
{
	if (orientation == leftDown)
	{
		orientation = leftUp;
	}
	else if (orientation == leftUp)
	{
		orientation = rightUp;
	}
	else if (orientation == rightUp)
	{
		orientation = rightDown;
	}
	else {
		orientation = leftDown;
	}
}

void triangle::draw(int x, int y)
{
	if (color == green)
	{
		glColor3f(0.016f, 0.703f, 0.016f);

	}
	else if (color == red)
	{
		glColor3f(0.901f, 0.f, 0.035f);
	}
	else if (color == blue)
	{
		glColor3f(0.2f, 0.2f, 1.f);
	}
	else if (color == yellow)
	{
		//glColor3f(1.f, 1.f, 0.1294f);
		glColor3f(0.95f, 0.87f, 0.f);
	}

	glBegin(GL_TRIANGLES);
	if (orientation == leftDown)
	{
		glVertex2f(x, y + triangle::triangleSize);
		glVertex2f(x, y);
		glVertex2f(x + triangle::triangleSize, y + triangle::triangleSize);
	}
	else if (orientation == leftUp)
	{
		glVertex2f(x + triangle::triangleSize, y);
		glVertex2f(x , y);
		glVertex2f(x, y + triangle::triangleSize);
	}
	else if (orientation == rightUp)
	{
		glVertex2f(x + triangle::triangleSize, y);
		glVertex2f(x, y);
		glVertex2f(x + triangle::triangleSize, y + triangle::triangleSize);
	}
	else {
		glVertex2f(x + triangle::triangleSize, y + triangle::triangleSize);
		glVertex2f(x, y + triangle::triangleSize);
		glVertex2f(x + triangle::triangleSize, y);
	}
	glEnd();
}