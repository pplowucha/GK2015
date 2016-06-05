// z8p1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"


/*
* (c) Copyright 2016, Vasyl Martsenyuk
* Email: marceniuk@yahoo.com
*/


#include <GL/glut.h>
int which = 1;
enum
{
	PRZYPADEK1,     //  (Ostrosłup SUB Kula) OR (Torus AND Kula)
	PRZYPADEK2,     // (Ostrosłup SUB Czworościan) OR (Kula AND Torus)
	PRZYPADEK3,     //(Ostrosłup SUB Kula) OR(Dwudziestościan AND Kula)
	EXIT            // wyjście
};


void display()
{
	if (which == 2 || which == 3)
	{
		glFlush();
		return;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// włączenie bufora szablonowego
	glEnable(GL_STENCIL_TEST);


	// rysujemy sześcian i uzupełniamy bufor szablonowy
	// jedynkami w tym miejscu gdzie narysujemy sześcian

	glStencilFunc(GL_ALWAYS, 1, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	/*glutSolidCube(2.5);*/
	glutSolidTorus(0.5, 2, 100, 100);


	// uzupełniamy bufor szablonowy dwójkami w tych miejscach
	// gdzie kula pokrywa sześcian
	glStencilFunc(GL_ALWAYS, 2, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	/*glutSolidSphere(1.5, 100, 100);*/

	// // czyszczenie bufora koloru i bufora głębokości
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/

	// wyłączenie testu bufora szablonowego i rysejemy czerwoną kulę
	glDisable(GL_STENCIL_TEST);
	glColor3d(1, 0, 0);
	glutSolidSphere(0.5, 100, 100);
	//niebieski torus
	glColor3d(0, 0, 1);
	glutSolidTorus(0.15, 0.6, 80, 100);
	// zielony torus obracany na 90 stopni według niebieskiego
	glColor3d(0, 1, 0);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.15, 0.6, 80, 100);
	glPopMatrix();

	// jeszcze raz pozwalamy test buforu szablonowego
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_EQUAL, 1, 255);
	glColor3d(1, 1, 1);
	/*glutSolidCube(2.5);*/

	// wracamy scenę

	glRotated(0.3, 1, 0, 0);
	glRotated(0.5, 0, 1, 0);
	glRotated(0.7, 0, 0, 1);

	glFlush();

	glutSwapBuffers();
}

void display2()
{
	if (which == 1 || which == 3)
	{
		glFlush();
		return;
	}
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// włączenie bufora szablonowego
	glEnable(GL_STENCIL_TEST);


	// rysujemy sześcian i uzupełniamy bufor szablonowy
	// jedynkami w tym miejscu gdzie narysujemy sześcian

	glStencilFunc(GL_ALWAYS, 1, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	/*glutSolidCube(2.5);*/
	glutSolidSphere(3.5, 100, 100);


	// uzupełniamy bufor szablonowy dwójkami w tych miejscach
	// gdzie kula pokrywa sześcian
	glStencilFunc(GL_ALWAYS, 2, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	/*glutSolidSphere(1.5, 100, 100);*/

	// // czyszczenie bufora koloru i bufora głębokości
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/

	// wyłączenie testu bufora szablonowego i rysejemy czerwoną kulę
	glDisable(GL_STENCIL_TEST);
	glColor3d(1, 0, 0);
	/*glutSolidSphere(0.5, 100, 100);*/
	//niebieski torus
	glColor3d(0, 0, 1);
	/*glutSolidTorus(0.15, 0.6, 80, 100);*/
	// zielony torus obracany na 90 stopni według niebieskiego
	glColor3d(0, 1, 0);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.35, 0.8, 80, 100);
	glPopMatrix();

	// jeszcze raz pozwalamy test buforu szablonowego
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_EQUAL, 1, 255);
	glColor3d(1, 1, 1);
	/*glutSolidCube(2.5);*/

	// wracamy scenę

	glRotated(0.3, 1, 0, 0);
	glRotated(0.5, 0, 1, 0);
	glRotated(0.7, 0, 0, 1);

	glFlush();

	glutSwapBuffers();
}

void display3()
{
	if (which == 1 || which == 2)
	{
		glFlush();
		return;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// włączenie bufora szablonowego
	glEnable(GL_STENCIL_TEST);


	// rysujemy sześcian i uzupełniamy bufor szablonowy
	// jedynkami w tym miejscu gdzie narysujemy sześcian

	glStencilFunc(GL_ALWAYS, 1, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	/*glutSolidCube(2.5);*/
	glutSolidTorus(0.5, 2, 100, 100);


	// uzupełniamy bufor szablonowy dwójkami w tych miejscach
	// gdzie kula pokrywa sześcian
	glStencilFunc(GL_ALWAYS, 2, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	/*glutSolidSphere(1.5, 100, 100);*/

	// // czyszczenie bufora koloru i bufora głębokości
	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/

	// wyłączenie testu bufora szablonowego i rysejemy czerwoną kulę
	glDisable(GL_STENCIL_TEST);
	glColor3d(1, 0, 0);
	glutSolidIcosahedron();
	/*glutSolidSphere(0.5, 100, 100);*/
	//niebieski torus
	glColor3d(0, 0, 1);
	glutSolidCone(10, 20,1,1);
	// zielony torus obracany na 90 stopni według niebieskiego
	glColor3d(0, 1, 0);
	glPushMatrix();
	glRotated(90, 1, 0, 0);
	glutSolidDodecahedron();
	
	glPopMatrix();

	// jeszcze raz pozwalamy test buforu szablonowego
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_EQUAL, 1, 255);
	glColor3d(1, 1, 1);
	/*glutSolidCube(2.5);*/

	// wracamy scenę

	glRotated(0.3, 1, 0, 0);
	glRotated(0.5, 0, 1, 0);
	glRotated(0.7, 0, 0, 1);

	glFlush();

	glutSwapBuffers();
}


void Menu(int value)
{
	switch (value)
	{

	case PRZYPADEK1:
	{
		which = 1;
		display();

		break;
	}
	case PRZYPADEK2:
	{
		which = 2;
		display2();

		break;
	}
	case PRZYPADEK3:
	{
		which = 3;
		display3();
		break;
	}
	 /*wyjście*/
	case EXIT:
		exit(0);

	}
};
void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5, 5, -5, 5, 2, 12);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	if (which == 1)
	{
		display();
	}
	else if (which == 2)
	{
		display2();

	}
	else if (which == 3)
	{
		display3();

	}


}

///////////////////////////////////////////////////////////
// Wywoływana przez bibliotek GLUT w czasie, gdy okno nie
// jest przesuwane ani nie jest zmieniana jego wielkość
void TimerFunction(int value) {

	if (which == 1)
	{
		display();
	}
	else if (which == 2)
	{
		display2();

	}
	else if (which == 3)
	{
		display3();

	}
	// Ponowne rysowanie sceny z nowymi współrzędnymi  
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

int main(int argc, char *argv[])
{

	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);
	float pos[4] = { 3, 3, 3, 1 };
	float dir[3] = { -1, -1, -1 };

	GLfloat mat_specular[] = { 1, 1, 1, 1 };

	glutInitWindowPosition(50, 10);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Stencil buffer");
	glutInitDisplayMode(GL_DOUBLE | GL_RGB | GL_DEPTH);


	if (which == 1)
	{
		glutDisplayFunc(display);
	}
	else if (which == 2)
	{
		glutDisplayFunc(display2);

	}
	else if (which == 3)
	{
		glutDisplayFunc(display3);

	}


	glutReshapeFunc(resize);

	glEnable(GL_DEPTH_TEST);


	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);




	// menu główne
	glutCreateMenu(Menu);

#ifdef WIN32

	glutAddMenuEntry("PRZYPADEK1", PRZYPADEK1);
	glutAddMenuEntry("PRZYPADEK2", PRZYPADEK2);
	glutAddMenuEntry("PRZYPADEK3", PRZYPADEK3);
	glutAddMenuEntry("WYJSCIE", EXIT);
#else

	glutAddMenuEntry("PRZYPADEK1", PRZYPADEK1);
	glutAddMenuEntry("PRZYPADEK2", PRZYPADEK2);
	glutAddMenuEntry("PRZYPADEK3", PRZYPADEK3);
	glutAddMenuEntry("WYJSCIE", EXIT);
#endif

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutTimerFunc(33, TimerFunction, 1);
	glutMainLoop();
	return 0;
}