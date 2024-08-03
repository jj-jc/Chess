#include <stdio.h>
#include <iostream>
#include "glut.h"
#include "Pieza.h"
#include "Tablero.h"
#include "ETSIDI.h"
#include "CoordinadorAjedrez.h"

using namespace std;
Vector Aux;
CoordinadorAjedrez coordinador;

// los callback, funciones que seran llamadas automaticamente por la glut
// cuando sucedan eventos
// NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);										// esta funcion sera llamada para dibujar
void OnTimer(int value);								// esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y);	// cuando se pulse una tecla
void ControlRaton(int button, int state, int x, int y); // cuando se pulse el raton
int main(int argc, char *argv[])
{

	// Inicializar el gestor de ventanas GLUT
	// y crear la ventana

	glutInit(&argc, argv);
	glutInitWindowSize(1400, 1000);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	// habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	// Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0); // le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(ControlRaton);

	coordinador.mundo.Inicializa();

	// pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
void ControlRaton(int button, int state, int x, int y)
{

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if (coordinador.mundo.pulsaciones % 2 == 1)
		{

			coordinador.mundo.MoverPieza(Aux, x, y);
		}
		else
		{

			printf("HOLA");
			Aux = coordinador.mundo.PedirPieza(x, y);

			cout << Aux.x << Aux.y;
		}
		coordinador.mundo.pulsaciones++;
	}

	glutMouseFunc(ControlRaton);
}

void OnDraw(void)
{
	// Borrado de la pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	coordinador.dibuja();

	// no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	// poner aqui el c�digo de teclado
	// mundo.Tecla(key);
	coordinador.tecla(key);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	// poner aqui el c�digo de animacion

	// no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
