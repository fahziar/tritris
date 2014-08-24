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
	bool isFit(triangle t);
	bool addTriangle(triangle t);
	bool removeTriangle(int id);
	void draw();
};

#endif