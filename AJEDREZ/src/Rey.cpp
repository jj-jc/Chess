#include <stdlib.h>
#include <string>
#include "Rey.h"
#include "Tablero.h"
Rey::Rey() {
	strcpy(nombre, "Rey");
}
Rey::Rey(int x, int y) {
	posicion.x = x;
	posicion.y = y;
}
Rey::~Rey() {

}

bool Rey::moverPieza(int x, int y) {
	if (PuedoMoverRey(x, y)) {
		SetPos(x, y);
		return 1;
	}
	return 0;
}
bool Rey::PuedoMoverRey(int x, int y) {
	int difx = x - posicion.x;
	int dify = y - posicion.y;
	if (abs(difx) == 1 && (abs(dify) == 0) || ((abs(difx) == 0) && (abs(dify) == 1))) {
		if (PuedoMoverTorre(x, y)) {
			enroque = 1;
			return 1;
		}
		
	}
	if (abs(difx) == 1 && abs(dify) == 1) {
		//	Movimiento_Alfil(x, y);
		if (PuedoMoverAlfil(x, y)) {
			enroque = 1;
			return 1;
		}

		

	}
	if (abs(difx > 1) || (abs(dify > 1))) {
		return 0;  //LAS COORDENADAS ESTAN FUERA DEL RANGO
				   //Coordenadas Inválidas

	}
}

void Rey::dibujarRey() {
	int v1;
	v1 = rand() % 255;
	glPushMatrix();
	glScalef(1.0, 1.25, 1.0);
	glColor3ub(165 * (int)Rey::Color+50, 165 * (int)Rey::Color+50, 165 * (int)Rey::Color+50);
	Base(6.0);
	glPushMatrix();
	glTranslatef(0.0, 7.0, 0.0);
	Cilindro(2.0, 1.0);
	glTranslatef(0.0, 1.0, 0.0);
	Cilindro(2.5, 1.0);
	glTranslatef(0.0, 1.0, 0.0);
	glColor3ub(255 , 255 - 255 * (jaque)*(v1), 255 - 255 * (jaque)*(v1)); //CABEZA DEL REY
	Esfera(2.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.5, 10.0, -0.25);
	Box(1.0, 2.5, 0.5);
	glTranslatef(-0.25, 1.0, 0.0);
	Box(1.5, 1.0, 0.5);
	glPopMatrix();
	glPopMatrix();
}
void Rey::dibujarReyconposicion() {
	glTranslatef(Tablero::Ancho_Cuadrado * (posicion.x) - 1, Tablero::Ancho_Cuadrado * (posicion.y) - 1, 0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glColor3ub(215, 220, 215);
	dibujarRey();
	glScalef(5, 5, 5);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-(Tablero::Ancho_Cuadrado * (posicion.x) - 1), -(Tablero::Ancho_Cuadrado * (posicion.y) - 1), 0);

}

