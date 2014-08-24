#include "MainAreaCell.h"

mainAreaCell::mainAreaCell() : triangles(0)
{

}

mainAreaCell::mainAreaCell(int x, int y) : triangles(0), x(x), y(y)
{

}

bool mainAreaCell::isFit(triangle t)
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
	if (this->isFit(t))
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
	
	int i;
	for (i = 0; i < triangles.size(); i++)
	{
		triangles.at(i).draw(this->x * triangle::triangleSize, this->y * triangle::triangleSize);
	}
}

bool mainAreaCell::removeTriangle(int id)
{
	if (id < triangles.size)
	{
		triangles.erase(triangles.begin() + id);
		return true;
	}
	else {
		return false;
	}
}