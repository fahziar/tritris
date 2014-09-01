#include <cstdio>
#include <ctime>
#include "TriangleGroup.h"

triangleGroup::triangleGroup(mainArea & m) : groupOrientation(normal), row(0), col(0)
{
	this->m = &m;
}

void triangleGroup::setType(type t)
{
	groupOrientation = normal;
	if (t == triangleGroup::type::single)
	{
		groupType = single;
		triangle t;
		t.setOrientation(orientationEnum::leftDown);
		m->setTriangle(col, row, t);
	}
	else if (t == triangleGroup::type::square)
	{
		groupType = square;
		triangle t1, t2;
		t1.setOrientation(leftDown);
		t2.setOrientation(rightUp);
		m->setTriangle(col, row, t1);
		m->setTriangle(col, row, t2);
	}
	else if (t == triangleGroup::type::doubleTriangle)
	{
		groupType = doubleTriangle;
		triangle t1, t2;
		t1.setOrientation(rightDown);
		t2.setOrientation(leftDown);
		m->setTriangle(col, row, t1);
		m->setTriangle(col + 1, row, t2);
	}
	else if (t == triangleGroup::type::parareloid)
	{
		groupType = parareloid;
		triangle t1, t2, t3, t4;
		t1.setOrientation(rightDown);
		t2.setOrientation(leftDown);
		t3.setOrientation(rightUp);
		t4.setOrientation(leftDown);
		m->setTriangle(col, row, t1);
		m->setTriangle(col + 1, row, t2);
		m->setTriangle(col + 1, row, t3);
		m->setTriangle(col + 2, row, t4);
	}
}

void triangleGroup::reset()
{
	
	srand((unsigned int)time(0));
	int randomNumber = (rand() % 2) + 1;

	this->row = 0;

	if (randomNumber == 1)
	{
		this->col = m->getNbCol() / 2;
		setType(single);
	}
	else if (randomNumber == 2)
	{
		this->col = m->getNbCol() / 2;
		setType(square);
	}
	else if (randomNumber == 3)
	{
		this->col = (m->getNbCol() / 2);
		setType(doubleTriangle);
	}
	else {
		this->col = (m->getNbCol() / 2) - 1;
		setType(parareloid);
	}
}

int triangleGroup::getNbMember()
{
	return 0;
}


void triangleGroup::rotateCW()
{
	if (this->groupType == single)
	{
		triangle t = m->removeTriangle(this->col, this->row);
		t.rotate();
		m->setTriangle(this->col, this->row, t);
		if (groupOrientation == normal)
		{
			groupOrientation = nintyDegree;
		}
		else if (groupOrientation == nintyDegree)
		{
			groupOrientation = oneHundredEightydegree;
		}
		else if (groupOrientation == oneHundredEightydegree)
		{
			groupOrientation = TwoHundredSeventydegree;
		}
		else if (groupOrientation == TwoHundredSeventydegree)
		{
			groupOrientation = normal;
		}
	}
	else if (this->groupType == doubleTriangle)
	{
		if ((groupOrientation == normal) && (row < m->getNbRow() - 1))
		{
			triangle t1 = m->removeTriangle(this->col, this->row);
			t1.rotate();
			m->setTriangle(col, row, t1);
			triangle t2 = m->removeTriangle(col + 1, row);
			t2.rotate();
			m->setTriangle(col, row + 1, t2);
			groupOrientation = nintyDegree;
		}
		else if ((groupOrientation == nintyDegree) && (col > 0))
		{
			triangle t1 = m->removeTriangle(this->col, this->row);
			t1.rotate();
			m->setTriangle(col, row, t1);
			triangle t2 = m->removeTriangle(col, row + 1);
			t2.rotate();
			m->setTriangle(col - 1, row, t2);
			groupOrientation = oneHundredEightydegree;
		}
		else if ((groupOrientation == oneHundredEightydegree) && (row > 0))
		{
			triangle t1 = m->removeTriangle(this->col, this->row);
			t1.rotate();
			m->setTriangle(col, row, t1);
			triangle t2 = m->removeTriangle(col, row + 1);
			t2.rotate();
			m->setTriangle(col, row - 1, t2);
			groupOrientation = TwoHundredSeventydegree;
		}
		else if ((groupOrientation == TwoHundredSeventydegree) && (col < m->getNbCol() - 1))
		{
			triangle t1 = m->removeTriangle(this->col, this->row);
			t1.rotate();
			m->setTriangle(col, row, t1);
			triangle t2 = m->removeTriangle(col, row + 1);
			t2.rotate();
			m->setTriangle(col + 1, row, t2);
			groupOrientation = normal;
		}
	}
}

void triangleGroup::moveLeft()
{
	if (col <= 0)
	{
		return;
	}

	if (m->getCell(col - 1, row).isEmpty())
	{
		if (groupType == single)
		{
			triangle t = m->removeTriangle(col, row);
			m->setTriangle(col - 1, row, t);
		}
		else if (groupType == doubleTriangle)
		{
			if (groupOrientation == normal)
			{
				triangle t1 = m->removeTriangle(col, row);
				triangle t2 = m->removeTriangle(col + 1, row);
				m->setTriangle(col-1, row, t1);
				m->setTriangle(col, row, t2);
			}
			else if (groupOrientation == nintyDegree)
			{
				triangle t1 = m->removeTriangle(col, row);
				triangle t2 = m->removeTriangle(col, row);
				m->setTriangle(col - 1, row, t1);
				m->setTriangle(col - 1, row, t2);
			}
			else if (groupOrientation == oneHundredEightydegree)
			{
				triangle t1 = m->removeTriangle(col - 1, row);
				triangle t2 = m->removeTriangle(col, row);
				m->setTriangle(col - 2, row, t1);
				m->setTriangle(col - 1, row, t2);
			}
			else if (groupOrientation == TwoHundredSeventydegree)
			{
				triangle t1 = m->removeTriangle(col, row);
				triangle t2 = m->removeTriangle(col, row - 1);
				m->setTriangle(col - 1, row, t1);
				m->setTriangle(col - 1, row -1, t2);
			}
		}
		else if (groupType == square)
		{
			triangle t1 = m->removeTriangle(col, row);
			triangle t2 = m->removeTriangle(col, row);
			m->setTriangle(col - 1, row, t1);
			m->setTriangle(col - 1, row, t2);
		}
		col = col - 1;
	}
}

void triangleGroup::moveRight()
{
	if ((col == m->getNbCol() - 1) || ((col == m->getNbCol() - 2) && (groupType == doubleTriangle)))
	{
		return;
	}

	//Cek kolom disebelahnya
	if ((groupType == doubleTriangle) && (groupOrientation == normal))
	{
		if (!m->getCell(col + 2, row).isEmpty()) return;
	}
	else {
		if (!m->getCell(col + 1, row).isEmpty()) return;
	}

	{
		if (groupType == single)
		{
			triangle t = m->removeTriangle(col, row);
			m->setTriangle(col + 1, row, t);
		}
		else if (groupType == doubleTriangle)
		{
			if (groupOrientation == normal)
			{
				triangle t1 = m->removeTriangle(col, row);
				triangle t2 = m->removeTriangle(col + 1, row);
				m->setTriangle(col + 1, row, t1);
				m->setTriangle(col + 2, row, t2);
			}
			else if (groupOrientation == nintyDegree)
			{
				triangle t1 = m->removeTriangle(col, row);
				triangle t2 = m->removeTriangle(col, row + 1);
				m->setTriangle(col + 1, row, t1);
				m->setTriangle(col + 1, row + 1, t2);
			}
			else if (groupOrientation == oneHundredEightydegree)
			{
				triangle t1 = m->removeTriangle(col - 1, row);
				triangle t2 = m->removeTriangle(col, row);
				m->setTriangle(col, row, t1);
				m->setTriangle(col + 1, row, t2);
			}
			else if (groupOrientation == TwoHundredSeventydegree)
			{
				triangle t1 = m->removeTriangle(col, row);
				triangle t2 = m->removeTriangle(col, row - 1);
				m->setTriangle(col + 1, row, t1);
				m->setTriangle(col + 1, row - 1, t2);
			}
		}
		else if (groupType == square)
		{
			triangle t1 = m->removeTriangle(col, row);
			triangle t2 = m->removeTriangle(col, row);
			m->setTriangle(col + 1, row, t1);
			m->setTriangle(col + 1, row, t2);
		}
		col = col + 1;
	}
}

bool triangleGroup::moveDownward()
{
	if (row == m->getNbRow() - 1)
	{
		return false;
	}
	bool out = false;
	if ((groupType == single) && (m->getCell(col,row).getNbTriangle() < 2))
	{
		triangle t = m->removeTriangle(col, row);
		if (m->getCell(col, row + 1).isFitFromAbove(t))
		{
			m->setTriangle(col, row + 1, t);
			row = row + 1;
			out = true;
		}
		else {
			m->setTriangle(col, row, t);
		}
		
	}
	else if (groupType == square)
	{
		if (m->getCell(col, row + 1).isEmpty())
		{
			triangle t1 = m->removeTriangle(col, row);
			triangle t2 = m->removeTriangle(col, row);
			m->setTriangle(col, row + 1, t1);
			m->setTriangle(col, row + 1, t2);
			row = row + 1;
			out = true;
		}
	}
	else if (groupType == doubleTriangle)
	{
		if ((groupOrientation == normal))
		{
			triangle t1 = m->removeTriangle(col, row);
			triangle t2 = m->removeTriangle(col + 1, row);
			if ((m->getCell(col, row + 1).isFitFromAbove(t1)) && (m->getCell(col + 1, row + 1).isFitFromAbove(t2)))
			{
				m->setTriangle(col, row + 1, t1);
				m->setTriangle(col + 1, row + 1, t2);
				row = row + 1;
				out = true;
			}
			else {
				m->setTriangle(col, row, t1);
				m->setTriangle(col + 1, row, t2);
			}
		}
		else if (groupOrientation == nintyDegree)
		{
			if (row == m->getNbRow() - 2)
			{
				return false;
			}

			triangle t1 = m->removeTriangle(col, row);
			triangle t2 = m->removeTriangle(col, row + 1);
			if (m->getCell(col, row + 2).isFitFromAbove(t2))
			{
				m->setTriangle(col, row + 1, t1);
				m->setTriangle(col, row + 2, t2);
				row = row + 1;
				out = true;
			}
			else {
				m->setTriangle(col, row, t1);
				m->setTriangle(col, row + 1, t2);
			}
		}
		else if (groupOrientation == oneHundredEightydegree)
		{
			triangle t1 = m->removeTriangle(col, row);
			triangle t2 = m->removeTriangle(col - 1, row);
			if ((m->getCell(col, row + 1).isFitFromAbove(t1)) && (m->getCell(col - 1, row + 1).isFitFromAbove(t2)))
			{
				m->setTriangle(col, row + 1, t1);
				m->setTriangle(col - 1, row + 1, t2);
				row = row + 1;
				out = true;
			}
			else {
				m->setTriangle(col, row, t1);
				m->setTriangle(col - 1, row, t2);
			}
		}
		else if (groupOrientation == TwoHundredSeventydegree)
		{
			triangle t1 = m->removeTriangle(col, row);
			triangle t2 = m->removeTriangle(col, row - 1);
			if (m->getCell(col, row + 1).isFitFromAbove(t1))
			{
				m->setTriangle(col, row + 1, t1);
				m->setTriangle(col, row, t2);
				row = row + 1;
				out = true;
			}
			else {
				m->setTriangle(col, row, t1);
				m->setTriangle(col, row - 1, t2);
			}
		}
	}

	return out;
}