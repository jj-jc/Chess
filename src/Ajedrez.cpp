#include <stdio.h>
#include <iostream>
#include "glut.h"
#include "Pieza.h"
#include "Tablero.h"
#include "ETSIDI.h"
#include "CoordinadorAjedrez.h"

using namespace std;
CoordinadorAjedrez coordinador;

GLdouble g_modelview[16], g_projection[16];
GLint g_viewport[4];

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void ControlRaton(int button, int state, int x, int y);
int main(int argc, char *argv[])
{

	glutInit(&argc, argv);
	glutInitWindowSize(1400, 1000);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(ControlRaton);

	coordinador.mundo.Inicializa();

	glutMainLoop();

	return 0;
}
void ControlRaton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if (coordinador.mundo.pulsaciones % 2 == 1)
		{
			coordinador.mundo.MoverPieza(coordinador.mundo.piezaAux, x, y);
		}
		else
		{
			coordinador.mundo.piezaAux = coordinador.mundo.PedirPieza(x, y);
			if (coordinador.mundo.seleccionValida)
				coordinador.mundo.pulsaciones++;
		}
	}

	glutMouseFunc(ControlRaton);
}

void OnDraw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	coordinador.dibuja();

	glGetDoublev(GL_MODELVIEW_MATRIX, g_modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, g_projection);
	glGetIntegerv(GL_VIEWPORT, g_viewport);

	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	coordinador.tecla(key);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
