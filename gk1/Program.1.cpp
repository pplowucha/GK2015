// glut.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

///////////////////////////////////////////////////////////
// Wywo³ywana w celu przerysowania sceny


// Funkcja wywo³ywana w celu narysowania sceny
void RenderScene(void) {
	// Wyczyszczenie okna aktualnym kolorem czyszcz¹cym
	glClear(GL_COLOR_BUFFER_BIT);
	/// Przekazanie polecenia czyszczenia do wykonania
	glFlush();
}

// Ustalenie stanu rendrowania  
void SetupRC(void) {
	glClearColor(0.60f, 0.38f, 0.10f, 1.0f);
}

// G³ówny punki wejœcia programu  
void main(int argc, char **argv) {
	//this is init function

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Mój pierwszy program w glut");
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
}
