#ifndef MAIN_AREA_H
#define MAIN_AREA_H
#include <vector>
#include "MainAreaCell.h"
#include "Triangle.h"

class mainArea
{
private:
	int nbRow, nbCol;
	std::vector <mainAreaCell> cells;
	int getAt(int col, int row);
public:
	mainArea(int nbCol, int nbRow);

	void draw();
	bool moveAllTriangleDownward(int colSource, int rowSource);
	mainAreaCell getCell(int x, int y);
	void setTriangle(int x, int y, triangle t);
	triangle removeTriangle(int x, int y);

	bool isLineFullOfTriangle(int row);
	void removeAllTrianglesInRow(int row);

	int getNbRow();
	int getNbCol();

	void drawMainArea();
};

#endif