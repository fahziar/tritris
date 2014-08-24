#ifndef TRIANGLE_H
#define TRIANGLE_H

enum triangleColor {red, green, blue, yellow};
enum orientationEnum {leftDown, leftUp, rightDown, rightUp};

class triangle
{
private:
	triangleColor color;
	orientationEnum orientation;
public:
	triangle();

	triangleColor getColor();
	void setColor(triangleColor color);
	
	void draw(int x, int y);

	void rotate();

	void setOrientation(orientationEnum orientation);
	orientationEnum getOrientation();

	static int triangleSize;
};

#endif