#ifndef MAIN_AREA_CELL_H
#define MAIN_AREA_CELL_H
#include <vector>
#include "Triangle.h"

class mainAreaCell
{
private:
	std::vector <triangle> triangles;
	int x, y;

public:
	mainAreaCell();
	mainAreaCell(int x, int y);

	void setX(int x);
	void setY(int y);

	bool isFitFromAbove(triangle t);
	
	bool addTriangle(triangle t);
	void addTrianlge(triangle t, int id);
	triangle getTriangle(int id) const;
	bool removeTriangle(int id);
	
	void draw();
	bool isEmpty() const;
	int getNbTriangle() const;
};

#endif