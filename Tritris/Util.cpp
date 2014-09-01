#include <stdio.h>
#include <Windows.h>
#include <cstdio>
#include "Triangle.h"
#include "TriangleGroup.h"
#include "MainArea.h"
#include "MainAreaCell.h"
#include "Util.h"

mainArea * areaUtama;
triangleGroup * groupSegitiga;
int score;
bool gameOver;

int timeCounter;

void initMainGame()
{
	areaUtama = new mainArea(10, 25);
	groupSegitiga = new triangleGroup(*areaUtama);
	glutKeyboardFunc(handleKeys);
	groupSegitiga->reset();
	score = 0;
	timeCounter = 0;
	gameOver = false;
}

void handleKeys(unsigned char key, int x, int y)
{
	if (gameOver)
	{
		return;
	}
	if (key == 'a')
	{
		groupSegitiga->moveLeft();
	}
	else if (key == 'd')
	{
		groupSegitiga->moveRight();
	}
	else if (key == 'w')
	{
		groupSegitiga->rotateCW();
	}
	else if (key == 's')
	{
		groupSegitiga->moveDownward();
	}
}
int initOpenGL()
{
	//Init projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-20, windowWidth - 20, windowHeigth - 20 , -20, 1.0, -1.0);

	//Init model matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Set bakcground to black
	glClearColor(0.98f, 0.98f, 0.98f, 1.f);

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

	//tiap dua detik turunin groupnya
	timeCounter++;

	if (timeCounter == 10)
	{
		timeCounter = 0;
		if (!groupSegitiga->moveDownward())
		{
			//cek apakah ada baris yang full
			int i;
			for (i = 0; i < areaUtama->getNbRow(); i++)
			{
				if (areaUtama->isLineFullOfTriangle(i))
				{
					//hapus semua semua segitiga pada baris
					areaUtama->removeAllTrianglesInRow(i);
					
					//Pindahin semua segitiga ke bawah
					int j;
					for (j = i - 1; j >= 0; j--)
					{
						int k;
						for (k = 0; k < areaUtama->getNbCol(); k++)
						{
							areaUtama->moveAllTriangleDownward(k, j);
						}
					}

					//tambahin scorenya
					score += 100;

				}
			}

			//cek apakah sudah pol
			i = 0;
			while ((i < areaUtama->getNbCol()) && (!gameOver))
			{
				if (!areaUtama->getCell(i, 0).isEmpty())
				{
					gameOver = true;
					MessageBox(NULL, "The game is over", "Game over", MB_OK);
				}
				i++;
			}
			if (!gameOver)
				groupSegitiga->reset();
		}
	}
	glutTimerFunc(1000 / 60, &mainLoop, 0);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	areaUtama->drawMainArea();
	std::string message;
	char temp[1000];
	_itoa_s(score, temp, 10);
	message = "Score: ";
	message.append(temp);

	/*
	triangle t1, t2;
	t1.setOrientation(rightUp);
	t2.setOrientation(leftDown);
	t1.setColor(green);
	t2.setColor(blue);
	*/

	//mainArea ma(5, 2);
	//if (!mac.addTriangle(t1))
	//	MessageBox(NULL, "ERROR", "ERROR", MB_OK);
	/*
	ma.setTriangle(0, 0, t2);
	ma.setTriangle(0, 0, t1);

	ma.moveAllTriangleDownward(0, 0);
	ma.setTriangle(1, 1, t2);
	ma.setTriangle(1, 1, t1);
	ma.setTriangle(2, 1, t2);
	ma.setTriangle(2, 1, t1);
	ma.setTriangle(3, 1, t2);
	ma.setTriangle(3, 1, t1);
	ma.setTriangle(4, 1, t2);
	ma.setTriangle(4, 1, t1);
	ma.setTriangle(4, 0, t2);
	ma.setTriangle(4, 0, t1);
	
	*/
	/*
	triangleGroup tg(ma);
	tg.setType(triangleGroup::doubleTriangle);
	tg.rotateCW();
	tg.moveRight();
	tg.rotateCW();
	tg.moveRight();
	tg.moveRight();
	tg.moveDownward();
	tg.moveDownward();
		
	if (ma.isLineFullOfTriangle(1))
	{
		//MessageBox(NULL, "Baris dua penuh sama segitiga", "INFO", MB_OK);
		ma.removeAllTrianglesInRow(1);
	}
	*/
	areaUtama->draw();
	
	glutSwapBuffers();
}