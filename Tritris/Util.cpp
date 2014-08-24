#include <stdio.h>
#include <Windows.h>
#include "Triangle.h"
#include "MainAreaCell.h"
#include "Util.h"

int initOpenGL()
{
	//Init projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeigth, 0, 1.0, -1.0);

	//Init model matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Set bakcground to black
	glClearColor(0.f, 0.f, 0.f, 1.f);

	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();

	glutDisplayFunc(render);
	glutTimerFunc(1000 / 60, mainLoop, 0);

	//Check for error
	GLenum error = glGetError();
	
	if (error != GL_NO_ERROR)
	{
		MessageBox(NULL, "Failed to initialize openGL", "Error", MB_OK | MB_ICONERROR);
		return -1;
	}

	return 0;
}

void mainLoop(int val)
{
	render();
	glutTimerFunc(1000 / 60, &mainLoop, 0);
}

void render()
{
	triangle t1, t2;
	t1.setOrientation(rightUp);
	t2.setOrientation(rightDown);
	t1.setColor(green);
	t2.setColor(blue);

	mainAreaCell mac(10, 5);
	mac.addTriangle(t2);
	if (!mac.addTriangle(t1))
		MessageBox(NULL, "ERROR", "ERROR", MB_OK);

	mac.draw();
	

	glutSwapBuffers();
}