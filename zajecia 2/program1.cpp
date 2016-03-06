// czternastokat

#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "math.h"

// Definiujemy stałą o wartości liczby PI
#define GL_PI 3.1415f
// Wielkość obrotów
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
// Wywoływana w celu przerysowania sceny
void RenderScene(void)
{
	GLfloat x, y, z, angle; // Zmienne przechowujące współrzędne i kąty
	GLfloat sizes[2]; // Do zapisania dopuszczalnego zakresu wielkości
	GLfloat step; // Zapamiętuje obsługiwany przyrost rozmiaru
	GLfloat curSize; // Zapamęituje aktualny rozmiar
	// Wyczyszczenie okna aktualnym kolorem czyszczącym
	glClear(GL_COLOR_BUFFER_BIT);
	// Zapisanie stanu macierzy i wykonanie obrotu
	glPushMatrix();
	glRotatef(xRot, 0.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	// Pobranie dopuszczalnych rozmiarów punktów
	glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);
	// Ustalenie początkowego rozmiaru punktu
	curSize = sizes[0];
	// Ustalenie pocztkowej współrzędnej z
	z = -50.0f;
	// Obracamy się w kółko trzy razy
	for (angle = 0.0f; angle <= (2.0f*3.1415f)*14.0f; angle += 0.2f)
	{
		// Wyliczenie wartości x i y na kole
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);
		// Zdefiniowanie rozmiaru punktu przed utworzeniem obiektu podstawowego
		glPointSize(curSize);
		// Rysowanie punktu
		glBegin(GL_POINTS);
		glVertex3f(x, y, z);
		glEnd();
		// Powiększenie współrzędnej z i rozmiaru punktu
		z += 0.4f;
		curSize += step/2;
	}
	// Odtworzenie macierzy przekształceń
	glPopMatrix();
	// Wykonanie poleceń rysowania
	glutSwapBuffers();
}
// Ta funkcja wykonuje wszystkie konieczne inicjalizacje kontekstu renderowania
void SetupRC()
{
	// Czarne tło
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Będziemy rysować kolorem zielonym
	glColor3f(0.0f, 1.0f, 0.0f);
}
void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
		xRot -= 5.0f;
	if (key == GLUT_KEY_DOWN)
		xRot += 5.0f;
	if (key == GLUT_KEY_LEFT)
		yRot -= 5.0f;
	if (key == GLUT_KEY_RIGHT)
		yRot += 5.0f;
	if (key > 356.0f)
		xRot = 0.0f;
	if (key < -1.0f)
		xRot = 355.0f;
	if (key > 356.0f)
		yRot = 0.0f;
	if (key < -1.0f)
		yRot = 355.0f;
	// Odświeżenie zawartości okna
	glutPostRedisplay();
}
void ChangeSize(int w, int h)
{
	GLfloat nRange = 100.0f;
	// Zabezpieczenie przed dzieleniem przez zero
	if (h == 0)
		h = 1;
	// Ustalenie wymiarów widoku na zgodnych z wymiarami okna
	glViewport(0, 0, w, h);
	// Ponowne ustawienie stosu macierzy rzutowania
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Utworzenie przestrzeni ograniczającej (lewo, prawo, dół, góra, blisko, daleko)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);
	// Ponowne ustawienie stosu macierzy rzutowania
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Menu(int value)
{
	switch (value)
	{
		//

	case 'red':
		glColor3f(1.0f, 0.0f, 0.0f);
		break;

	case 'gr':
		glColor3f(0.0f, 1.0f, 0.0f);
		
		break;

		//
	case 'blue':
		
		glColor3f(0.0f,0.0f, 1.0f);
		break;

	case 'wh':
		glColor3f(1.0f, 1.0f, 1.0f);

		break;

	case 'br':
		glColor3f(0.6f, 0.4f, 0.12f);

		break;

	



		// wyjęcie
	case 'exit':
		exit(0);
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 800);
	glutCreateWindow("Points Size Example");




	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(SpecialKeys);
	glutDisplayFunc(RenderScene);




	SetupRC();

	// utworzenie podmenu - Prymitywy
	int MenuPrimitive = glutCreateMenu(Menu);
	glutAddMenuEntry("Kolor czerwony.", 'red');
	glutAddMenuEntry("Kolor zielony.", 'gr');
	glutAddMenuEntry("Kolor niebieski.", 'blue');
	glutAddMenuEntry("Kolor bialy.", 'wh');
	glutAddMenuEntry("Kolor brazowy.", 'br');
	glutAddMenuEntry("Wyjscie", 'exit');

	// określenie przycisku myszki obsługującego menu podręczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}
