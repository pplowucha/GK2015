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


void RenderScene(void)  {
	// Wyczyszczenie okna aktualnym kolorem czyszczcym   
	glClear(GL_COLOR_BUFFER_BIT);
	// Aktualny kolor rysujcy - czerwony  
	//           R     G     B  
	glColor3f(1.0f, 0.0f, 0.0f);
	// Narysowanie 14 kata wype³nionego aktualnym kolorem  

	glBegin(GL_POLYGON);
	glVertex3f(-100.0f, 0.0f, 0.0f);
	glVertex3f(-80.0f, 10.0f, 0.0f);
	glVertex3f(-60.0f, 30.0f, 0.0f);
	glVertex3f(-40.0f, 60.0f, 0.0f);
	glVertex3f(-30.0f, 100.0f, 0.0f);
	glVertex3f(-40.0f, 140.0f, 0.0f);
	glVertex3f(-60.0f, 170.0f, 0.0f);
	glVertex3f(-80.0f, 190.0f, 0.0f);
	glVertex3f(-100.0f, 200.0f, 0.0f);
	glVertex3f(-130.0f, 190.0f, 0.0f);
	glVertex3f(-160.0f, 160.0f, 0.0f);
	glVertex3f(-170.0f, 110.0f, 0.0f);
	glVertex3f(-160.0f, 60.0f, 0.0f);
	glVertex3f(-120.0f, 10.0f, 0.0f);
	glEnd();
	// Wys³anie polece do wykonania     
	glFlush();



}
///////////////////////////////////////////////////////////
// Konfiguracja stanu renderowania  
void SetupRC(void)     {
	// Ustalenie niebieskiego koloru czyszczcego     
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
///////////////////////////////////////////////////////////
// Wywo³ywana przez bibliotek GLUT w przypadku zmiany rozmiaru okna
void ChangeSize(int w, int h)  {
	GLfloat aspectRatio;
	// Zabezpieczenie przed dzieleniem przez zero  
	if (h == 0)   h = 1;
	// Ustawienie wielkoœci widoku na równ¹ wielkoœci okna     
	glViewport(0, 0, w, h);
	// Ustalenie uk³adu wspó³rzêdnych  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Wyznaczenie przestrzeni ograniczaj¹cej (lewy, prawy, dolny, górny, bliski, odleg³y)  
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)    glOrtho(-200.0, 200.0, -200 / aspectRatio, 200.0 / aspectRatio, 2.0, -2.0);
	else    glOrtho(-200.0 * aspectRatio, 200.0 * aspectRatio, -200.0, 200.0, 2.0, -2.0);
	glMatrixMode(GL_MODELVIEW);  glLoadIdentity();
}
///////////////////////////////////////////////////////////
// G³ówny punkt wejcia programu
int main(int argc, char* argv[])     {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("GLRect");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
	return 0;
}
