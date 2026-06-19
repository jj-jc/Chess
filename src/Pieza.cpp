#include <iostream>
#include "Pieza.h"
#include "Tablero.h"

using namespace std;

void Pieza::ImprimeNombre()
{
	cout << nombre;
}
Pieza::~Pieza()
{
}
void Pieza::capturar()
{
	posicion.x = 0;
	posicion.y = 0;
}
void Pieza::SetPos(int x, int y)
{
	if (x < 1 || x > 8 || y < 1 || y > 8) return;

	Pieza *ocupante = Tablero::MatrizPuntero[x - 1][y - 1];
	if (ocupante != 0)
	{
		ocupante->capturar();
		Tablero::posiciones[x - 1][y - 1] = 0;
	}

	if (posicion.x >= 1 && posicion.x <= 8 && posicion.y >= 1 && posicion.y <= 8)
	{
		Tablero::posiciones[posicion.x - 1][posicion.y - 1] = 0;
		Tablero::MatrizPuntero[posicion.x - 1][posicion.y - 1] = 0;
	}

	Tablero::MatrizPuntero[x - 1][y - 1] = this;
	posicion.x = x;
	posicion.y = y;

	Tablero::posiciones[x - 1][y - 1] = (getColor() == 1) ? 1 : 2;
}

// FUNCIONES PARA DIBUJAR
// Construye una caja
void Pieza::Box(GLfloat x, GLfloat y, GLfloat z)
{
	/* Caras transversales */
	glBegin(GL_QUAD_STRIP);
	{
		glNormal3f(0.0, 0.0, -1.0); /* Vertical hacia atras */
		glVertex3f(x, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(x, y, 0);
		glVertex3f(0, y, 0);
		glNormal3f(0.0, 1.0, 0.0); /* Superior, horizontal */
		glVertex3f(x, y, z);
		glVertex3f(0, y, z);
		glNormal3f(0.0, 0.0, 1.0); /*Vertical delantera*/
		glVertex3f(x, 0, z);
		glVertex3f(0, 0, z);
		glNormal3f(0.0, -1.0, 0.0); /*Inferior */
		glVertex3f(x, 0, 0);
		glVertex3f(0, 0, 0);
	}
	glEnd();

	/* Costados */
	glBegin(GL_QUADS);
	{
		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(x, 0, 0);
		glVertex3f(x, y, 0);
		glVertex3f(x, y, z);
		glVertex3f(x, 0, z);
	}
	glEnd();

	glBegin(GL_QUADS);
	{
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, z);
		glVertex3f(0, y, z);
		glVertex3f(0, y, 0);
	}
	glEnd();
}
// Construye un Disco
void Pieza::Disco(GLfloat radio)
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluDisk(qobj, 0.0, radio, 10, 10);
	gluDeleteQuadric(qobj);
}
// Construye unCilindro
void Pieza::Cilindro(GLfloat radio, GLfloat altura)
{
	GLUquadricObj *qobj;
	// cilindro
	glPushMatrix();
	glTranslatef(0.0, altura - 1, 0.0);
	glPushMatrix();
	qobj = gluNewQuadric();
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -1.0);
	gluCylinder(qobj, radio, radio, altura, 10, 10);
	gluDeleteQuadric(qobj);
	glPopMatrix();
	glPopMatrix();
	// tapa superior
	glPushMatrix();
	glTranslatef(0.0, altura, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	Disco(radio);
	glPopMatrix();
	// tapa inferior
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	Disco(radio);
	glPopMatrix();
}
// Construye una Esfera
void Pieza::Esfera(GLfloat radio)
{
	GLUquadricObj *qobj;
	qobj = gluNewQuadric();
	gluSphere(qobj, radio, 10, 10);
	gluDeleteQuadric(qobj);
}
// Construye la Base de las piezas
void Pieza::Base(int altura)
{

	Cilindro(3.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	Cilindro(1.0, altura);
	glPopMatrix();
}
