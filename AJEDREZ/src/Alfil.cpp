#pragma once
#include <string>
#include "Alfil.h"
#include "Tablero.h"

Alfil::Alfil() {
	strcpy(nombre, "Alfil");
}
Alfil::Alfil(int x, int y) {
	posicion.x = x;
	posicion.y = y;
}
Alfil::~Alfil() {

}
bool Alfil::moverPieza(int x, int y) {
	if (PuedoMoverAlfil(x, y)) {
		SetPos(x, y);
		return 1;
	}
	return 0;



}
bool Alfil::PuedoMoverAlfil(int x, int y) {
	int difx = x - posicion.x;
	int dify = y - posicion.y;
	//Ahora comprobamos si la resta de ambas coordenadas es la misma																										
	if (abs(difx) == abs(dify)) {
		//Si se cumple la condición anterior las coordenadas son válidas para un alfil.
		//tenemos que llamar a la funcion colision

		//DE MOMENTO NO CONTEMPLAMOS COLISIONES

		if (Colision_Alfil(x, y) == true) {
			//hay colision, coordenada no valida, introduzca otra
			return 0;
		}


		else {

			return 1;
		}
	}
	else {
		//repetir coordenadas
		return 0;
	}
}



bool Alfil::Colision_Alfil(int x, int y)
{
	int difx = x - posicion.x;
	int dify = y - posicion.y;
	//nos calculamos el maximo de iteraciones para ver las posibles colisiones de la pieza
	//se contemplan todos los posibles casos del movimiento del alfil
	//SE COMPRUEBAN TODAS LAS CASILLAS 
	if ((difx > 0) && (dify > 0)) {
		for (int i = 1; i < difx + 1; i++) {
			if ((Tablero::posiciones[posicion.x + i - 1][posicion.y + i - 1] == 1) || (Tablero::posiciones[posicion.x + i - 1][posicion.y + i - 1] == 2)) {
				if ((i == difx) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[posicion.x - 1][posicion.y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}
	if ((difx > 0) && (dify < 0)) {
		for (int i = 1; i < difx + 1; i++) {
			if ((Tablero::posiciones[posicion.x + i - 1][posicion.y - i - 1] == 1) || (Tablero::posiciones[posicion.x + i - 1][posicion.y - i - 1] == 2)) {
				if ((i == difx) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[posicion.x - 1][posicion.y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}
	if ((difx < 0) && (dify > 0)) {
		for (int i = 1; i < abs(difx) + 1; i++) {
			if ((Tablero::posiciones[posicion.x - i - 1][posicion.y + i - 1] == 1) || (Tablero::posiciones[posicion.x - i - 1][posicion.y + i - 1] == 2)) {
				if ((i == dify) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[posicion.x - 1][posicion.y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}
	if ((difx < 0) && (dify < 0)) {
		for (int i = 1; i < abs(difx) + 1; i++) {
			if ((Tablero::posiciones[posicion.x - i - 1][posicion.y - i - 1] == 1) || (Tablero::posiciones[posicion.x - i - 1][posicion.y - i - 1] == 2)) {
				if ((i == abs(dify)) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[posicion.x - 1][posicion.y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}

	return false; // no hay colision
}
 /*En un futuro se utilizara esta estructura para el alcancce:
 for(int i=1;i<8;i++){														//Con este for nos recorremos el tablero.
		if (((posicion.x == x + i) && (posicion.y == y + i)) || ((posicion.x == x - i) && (posicion.y == y - i))|| ((posicion.x == x + i) && (posicion.y == y - i)) || ((posicion.x == x - i) && (posicion.y == y + i))) {
			//Si se cumple la condición anterior las coordenadas son válidasm para un alfil.
			//(x+i)&&(y+i)==ocupada
			if (/*tablero.posiciones[x+i][y+i] =! 0) {
			//HAY QUE ESCRIBIR POR PANTALLA QUE NO SE PUEDE MOVERE

		//	return;
			}
 */
void Alfil::dibujarAlfil()
{
	glColor3ub(165 * (int)Alfil::Color+50, 165 * (int)Alfil::Color+50, 165 * (int)Alfil::Color+50);
	Base(6.0);
	glPushMatrix();
	glTranslatef(0.0, 7.0, 0.0);
	glScalef(1.0, 1.25, 1.0);
	glColor3ub(255, 255, 30);    //cabeza del alfil
	Esfera(2.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 9.5, 0.0);
	Esfera(1.0);
	glPopMatrix();
}
void Alfil::dibujarAlfilconposicion() {
	glTranslatef(Tablero::Ancho_Cuadrado * (posicion.x) - 1, Tablero::Ancho_Cuadrado * (posicion.y) - 1, 0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glColor3ub(215, 220, 215);
	dibujarAlfil();
	glScalef(5, 5, 5);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-(Tablero::Ancho_Cuadrado * (posicion.x) - 1), -(Tablero::Ancho_Cuadrado * (posicion.y) - 1), 0);

}
 
 