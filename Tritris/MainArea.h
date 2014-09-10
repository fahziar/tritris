#ifndef MAIN_AREA_H
#define MAIN_AREA_H
#include <vector>
#include "MainAreaCell.h"
#include "Triangle.h"

//Kelas untuk main area
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

	//getter
	mainAreaCell getCell(int x, int y);
	//setter triangle, menambahkan triangle pada cell
	void setTriangle(int x, int y, triangle t);
	//menghapus triangle dan mengembalikan segitiga yang dihapus
	triangle removeTriangle(int x, int y);

	//mengecek apakah baris sudah penuh dengan segitiga
	bool isLineFullOfTriangle(int row);
	//Menghapus semua segitiga pada baris
	void removeAllTrianglesInRow(int row);

	int getNbRow();
	int getNbCol();

	void drawMainArea();
};

#endif