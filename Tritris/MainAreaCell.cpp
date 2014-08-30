#include "MainAreaCell.h"

mainAreaCell::mainAreaCell() : triangles(0)
{

}

mainAreaCell::mainAreaCell(int x, int y) : triangles(0), x(x), y(y)
{

}

bool mainAreaCell::isFitFromAbove(triangle t)
{
	if (triangles.size() == 2)
	{
		return false;
	}

	if (triangles.empty())
	{
		return true;
	}

	if ((triangles.at(0).getOrientation() == leftDown) && (t.getOrientation() == rightUp))
	{
		return true;
	}

	if ((triangles.at(0).getOrientation() == rightDown) && (t.getOrientation() == leftUp))
	{
		return true;
	}

	if ((triangles.at(0).getOrientation() == leftUp) || (triangles.at(0).getOrientation() == rightUp))
	{
		return false;
	}

	return false;
}

bool mainAreaCell::addTriangle(triangle t) 
{
	if (this->isFitFromAbove(t))
	{
		triangles.push_back(t);
		return true;
	}
	else {
		return false;
	}
}

void mainAreaCell::draw()
{
	
	unsigned int i;
	for (i = 0; i < triangles.size(); i++)
	{
		triangles.at(i).draw(this->x * triangle::triangleSize, this->y * triangle::triangleSize);
	}
}

bool mainAreaCell::removeTriangle(int id)
{
	if (id < (int) triangles.size())
	{
		triangles.erase(triangles.begin() + id);
		return true;
	}
	else {
		return false;
	}
}

bool mainAreaCell::isEmpty() const
{
	return triangles.empty();
}

void mainAreaCell::setX(int x)
{
	this->x = x;
}

void mainAreaCell::setY(int y)
{
	this->y = y;
}

int mainAreaCell::getNbTriangle() const
{
	return triangles.size();
}

triangle mainAreaCell::getTriangle(int id) const
{
	return triangles.at(id);
}