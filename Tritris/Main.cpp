#include "Util.h"

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);

	glutInitContextVersion(2, 1);

	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeigth);
	glutCreateWindow("Tritris");

	initOpenGL();
	glutMainLoop();
	return 0;
}