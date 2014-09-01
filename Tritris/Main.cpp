#include "Util.h"

int main(int argc, char * argv[])
{
	glutInit(&argc, argv);

	glutInitContextVersion(2, 1);

	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(windowWidth, windowHeigth);
	glutCreateWindow("Tritris");

	initOpenGL();
	initMainGame();
	glutMainLoop();
	return 0;
}