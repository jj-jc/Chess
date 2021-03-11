#include <string>
#include "Caballo.h"
#include "Tablero.h"


Caballo::Caballo() {
	strcpy(nombre, "Caballo");

}
Caballo::Caballo(int x, int y) {
	posicion.x = x;
	posicion.y = y;
}
Caballo::~Caballo() {

}
bool Caballo::moverPieza(int x, int y) {
	if (PuedoMoverCaballo(x, y)) {
		SetPos(x, y);
		return 1;
	}
	return 0;
}

bool Caballo::Colision_Caballo(int x, int y) {
	if ((Tablero::posiciones[x-1][y-1] == 1)|| (Tablero::posiciones[x - 1][y - 1] ==2)) {
		if ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[posicion.x-1][posicion.y-1])) {
				
			return false; //HAY COLISION CON UNA PIEZA CONTRARIA
		}
		else {
			return true; //se ha producido colision
		}
	}
	else {
		return false; //no se ha producido colision
	}
}
void Caballo::dibujarCaballo()
{
	glColor3ub(165 * (int)Caballo::Color+50, 165 * (int)Caballo::Color+50, 165 * (int)Caballo::Color+50);
	Base(6.0);
	glPushMatrix();
	glTranslatef(-2.0, 4.5, -1.5);
	glColor3ub(20, 200, 30);    //cabeza deL caballo
	Box(3.5, 2.0, 3.0);
	glTranslatef(-2.0, 2.5, 0.0);
	Box(6.0, 3.5, 3.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 8.5, -1.5);
	Esfera(1.0);
	glTranslatef(0.0, 0.0, 3.0);
	Esfera(1.0);
	glPopMatrix();
}
void Caballo::dibujarCaballoconposicion() {
	glTranslatef(2 * (posicion.x) - 1, 2 * (posicion.y) - 1, 0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glColor3ub(215, 220, 215);
	dibujarCaballo();
	glScalef(5, 5, 5);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-(2 * (posicion.x) - 1), -(2 * (posicion.y) - 1), 0);

}
bool Caballo::PuedoMoverCaballo(int x, int y) {
	int difx = x - posicion.x;
	int dify = y - posicion.y;
	if (((abs(difx) == 2) && abs(dify) == 1) || ((abs(difx) == 1) && (abs(dify) == 2))) {			//Las coordenadas son válidas

		if (Colision_Caballo(x, y) == true) {
			//hay colision, coordenada no valida, introduzca otra
			return 0;
		}

		else {

			
			return 1;
		}
	}

	else {
		//Poner de nuevo las coordenadas
		return 0;
	}
}