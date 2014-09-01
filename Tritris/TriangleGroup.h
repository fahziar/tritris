#ifndef TRIANGLE_GROUP_H
#define TRIANGLE_GROUP_H
#include <vector>
#include "MainArea.h"
#include "MainAreaCell.h"

class triangleGroup
{
	
public:
	triangleGroup(mainArea &m);
	int getNbMember();
	void reset();
	bool moveDownward();
	void moveLeft();
	void moveRight();
	void rotateCW();
	
	enum orientation { normal, nintyDegree, oneHundredEightydegree, TwoHundredSeventydegree };
	enum type {single, square, parareloid, doubleTriangle};
	void setType(type t);
private:
	int col;
	int row;
	mainArea *m;
	type groupType;
	triangleGroup::orientation groupOrientation;
	
};

#endif