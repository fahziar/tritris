#ifndef UTIL_H
#define UTIL_H
#include "include.h"

const int windowWidth = 400;
const int windowHeigth = 660;

int initOpenGL();
/* Inisiasi window dan openGL context*/

void mainLoop(int val);

void render();

void initMainGame();

void handleKeys(unsigned char key, int x, int y);
#endif