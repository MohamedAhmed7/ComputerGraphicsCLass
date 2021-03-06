
#include "pch.h"
#include <iostream>
#include <GL\glut.h>
#include <GL\gl.h>
#include <math.h>
#include <time.h>
#define windowWidth 900
#define windowHeight 600
#define pi acos(-1)
int N = 10;
using namespace std;

void delay(float secs)
{
	float end = clock() / CLOCKS_PER_SEC + secs;
	while ((clock() / CLOCKS_PER_SEC) < end);
}

void init(void)
{

	glClearColor(1.0, 1.0, 1.0, 0.0); //specifies clearvalues for the color buffers(R, G, B, Alpha)
	glMatrixMode(GL_PROJECTION); // sets thecurrent matrix mode
	//gluOrtho2D(0.0, 800.0, 0.0, 550.0);
}

void drawPolygon(int numOfSides) {
	float x, y;

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int i = numOfSides; i > 0; --i) {
		x = (cos((2 * pi*(i / (numOfSides * 1.0))) + (2 * pi*(1 / (numOfSides*1.0))) / 2));
		y = (sin((2 * pi*(i / (numOfSides * 1.0))) + (2 * pi*(1 / (numOfSides*1.0))) / 2));
		glVertex2f(y, x);
	}
	glEnd();


}

void drawScreen() {
	for (int i = 5; i <= N; ++i) {
		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-1.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);
		glVertex2f(1.0f, -1.0f);
		glVertex2f(-1.0f, -1.0f);
		glEnd();
		drawPolygon(i);
		glutSwapBuffers();
		delay(1.0);
		//cout << "here clear happens!\n";
		//glClear(GL_COLOR_BUFFER_BIT);

	}
	return;
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(windowWidth, windowHeight); // width and height
	glutCreateWindow("Assignment 1");
	//cin >> N;
	init();

	glutDisplayFunc(drawScreen);
	glutMainLoop();

}
