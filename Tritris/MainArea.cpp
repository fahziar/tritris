#include "MainArea.h"
#include "include.h"

mainArea::mainArea(int nbCol, int nbRow) :nbCol(nbCol), nbRow(nbRow), cells(nbCol * nbRow)
{
	int col, row;
	for (col = 0; col < nbCol; col++)
	{
		for (row = 0; row < nbRow; row++)
		{
			cells.at(getAt(col, row)).setX(col);
			cells.at(getAt(col, row)).setY(row);
		}
	}
}

void mainArea::draw()
{
	int i, j;

	for (i = 0; i < nbCol; i++)
	{
		for (j = 0; j < nbRow; j++)
		{
			this->cells.at(getAt(i,j)).draw();
		}
	}
}

int mainArea::getAt(int col, int row)
{
	return (row * nbCol) + col;
}

bool mainArea::moveAllTriangleDownward(int colSource, int rowSource)
{
	//cek apakah cell dibawahanya fit
	if (cells.at(getAt(colSource, rowSource)).getNbTriangle() == 2)
	{
		if (!cells.at(getAt(colSource, rowSource + 1)).isEmpty())
		{
			return false;
		}
	}
	else if (cells.at(getAt(colSource, rowSource)).getNbTriangle() == 1)
	{
		if (!cells.at(getAt(colSource, rowSource + 1)).isFitFromAbove(cells.at(getAt(colSource, rowSource)).getTriangle(0)))
		{
			return false;
		}
	}

	//Pindahin semua ke bawah
	int i, nbTriangle;
	nbTriangle = cells.at(getAt(colSource, rowSource)).getNbTriangle();
	for (i = 0; i < nbTriangle; i++)
	{
		triangle temp = cells.at(getAt(colSource, rowSource)).getTriangle(0);
		cells.at(getAt(colSource, rowSource)).removeTriangle(0);
		cells.at(getAt(colSource, rowSource + 1)).addTriangle(temp);
	}

	return true;
}

void mainArea::setTriangle(int x, int y, triangle t)
{
	cells.at(getAt(x, y)).addTriangle(t);
}

triangle mainArea::removeTriangle(int x, int y)
{
	triangle out = cells.at(getAt(x, y)).getTriangle(0);
	cells.at(getAt(x, y)).removeTriangle(0);
	return out;
}

bool mainArea::isLineFullOfTriangle(int row)
{
	int i = 0;
	bool full = true;

	while ((full) && (i < this->nbCol))
	{
		if (cells.at(getAt(i, row)).getNbTriangle() < 2)
		{
			full = false;
		}
		i++;
	}

	return full;
}

void mainArea::removeAllTrianglesInRow(int row)
{
	//Remove all triangles
	int i;
	for (i = getAt(0, row); i < getAt(0, row + 1); i++)
	{
		int j;
		int nbTriangle = cells.at(i).getNbTriangle();
		for (j = 0; j < nbTriangle ; j++)
		{
			cells.at(i).removeTriangle(0);
		}
	}

	//Geser semua segitiga yang ada di atas row ke bawah
	for (i = row - 1; i >= 0; i--)
	{
		int j;
		for (j = 0; j < nbCol; j++)
			moveAllTriangleDownward(j, i);
	}

}

int mainArea::getNbCol()
{
	return this->nbCol;
}

int mainArea::getNbRow()
{
	return this->nbRow;
}

mainAreaCell mainArea::getCell(int x, int y)
{
	return this->cells.at(getAt(x, y));
}

void mainArea::drawMainArea()
{
	const int width = 5;
	
	//bikin border kiri
	glColor3f(0.49f, 0.49f, 0.49f);
	glBegin(GL_QUADS);
	glVertex2f(-5.f, -5.f);
	glVertex2f(-5.f, (triangle::triangleSize * nbRow) + 5.f);
	glVertex2f(0.f, (triangle::triangleSize * nbRow) + 5.f);
	glVertex2f(0.f, -5.f);
	glEnd();

	//bikin border kanan
	glBegin(GL_QUADS);
	glVertex2f((triangle::triangleSize * nbCol), -5.f);
	glVertex2f((triangle::triangleSize * nbCol), (triangle::triangleSize * nbRow) + 5.f);
	glVertex2f((triangle::triangleSize * nbCol) + 5.f, (triangle::triangleSize * nbRow) + 5.f);
	glVertex2f((triangle::triangleSize * nbCol) + 5.f, -5.f);
	glEnd();

	//bikin border bawah

}