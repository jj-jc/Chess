#include <string>
#include "Torre.h"
#include "Tablero.h"
Torre::Torre() {
	setNombre("Torre");
	//strcpy(nombre, "Torre");
}
Torre::Torre(int x, int y) {
	SetPos(x, y);

}
Torre::~Torre() {

}

bool Torre::moverPieza(int x, int y) {
	if (PuedoMoverTorre(x, y)) {
		SetPos(x, y);
		return 1;
	}
	return 0;
}
bool Torre::PuedoMoverTorre(int x, int y) {
	int difx = x - getPos().x;
	int dify = y - getPos().y;


	if (((difx != 0) && (dify == 0)) || ((difx == 0) && (dify != 0))) {
		//Si se cumple la condición anterior las coordenadas son válidas para una torre.

		if (Colision_Torre(x, y) == true) {
			//hay colision, coordenada no valida, introduzca otra
			return 0;
		}

		else
		{

			return 1;
		}
	}
	else {
		//Repetir las coordenadas
		return 0;
	}
}
bool Torre::Colision_Torre(int x, int y) {
	int difx = x - getPos().x;
	int dify = y - getPos().y;
	//nos calculamos el maximo de iteraciones para ver las posibles colisiones de la pieza
	//se contemplan todos los posibles casos del movimiento de la torre
	if ((difx > 0) && (dify == 0)) {
		for (int i = 1; i < difx + 1; i++) {
			if ((Tablero::posiciones[getPos().x + i - 1][getPos().y - 1] == 1) || (Tablero::posiciones[getPos().x + i - 1][getPos().y - 1] == 2)) {  //POSTERIORMENTE TENDREMOS QUE DISTINGUIR ENTRE TABLERO BLANCO Y TABLERO NEGRO
				if ((i == difx) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[getPos().x - 1][getPos().y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}
	if ((difx < 0) && (dify == 0)) {
		for (int i = 1; i < abs(difx) + 1; i++) {
			if ((Tablero::posiciones[getPos().x - i - 1][getPos().y - 1] == 1) || (Tablero::posiciones[getPos().x - i - 1][getPos().y - 1] == 2)) {  //POSTERIORMENTE TENDREMOS QUE DISTINGUIR ENTRE TABLERO BLANCO Y TABLERO NEGRO
				if ((i == abs(difx)) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[getPos().x - 1][getPos().y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}
	if ((difx == 0) && (dify > 0)) {
		for (int i = 1; i < dify + 1; i++) {
			if ((Tablero::posiciones[getPos().x - 1][getPos().y + i - 1] == 1) || (Tablero::posiciones[getPos().x - 1][getPos().y + i - 1] == 2)) {  //POSTERIORMENTE TENDREMOS QUE DISTINGUIR ENTRE TABLERO BLANCO Y TABLERO NEGRO
				if ((i == dify) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[getPos().x - 1][getPos().y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}
	if ((difx == 0) && (dify < 0)) {
		for (int i = 1; i < abs(dify) + 1; i++) {
			if ((Tablero::posiciones[getPos().x - 1][getPos().y - i - 1] == 1) || (Tablero::posiciones[getPos().x - 1][getPos().y - i - 1] == 2)) {  //POSTERIORMENTE TENDREMOS QUE DISTINGUIR ENTRE TABLERO BLANCO Y TABLERO NEGRO
				if ((i == abs(dify)) && ((Tablero::posiciones[x - 1][y - 1]) != (Tablero::posiciones[getPos().x - 1][getPos().y - 1]))) {

					return false;
				}
				return true; //existe colision
			}
		}
	}
	return false; // no hay colision
}

void Torre::dibujarTorre()
{
	glColor3ub(165 * (int)Torre::getColor()+50, 165 * (int)Torre::getColor()+50, 165 * (int)Torre::getColor()+50);
	Base(6.0);
	glPushMatrix();
	glTranslatef(-2.0, 7.0, -2.0);
	glColor3ub(100, 100, 215);    //cabeza de la torre
	Box(4.0, 2.0, 4.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 9.0, -2.0);
	Box(1.0, 1.0, 1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 9.0, 1.0);
	Box(1.0, 1.0, 1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0, 9.0, 1.0);
	Box(1.0, 1.0, 1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0, 9.0, -2.0);
	Box(1.0, 1.0, 1.0);
	glPopMatrix();
}
void Torre::dibujarTorreconposicion() {
	glTranslatef(Tablero::Ancho_Cuadrado * (getPos().x) - 1, Tablero::Ancho_Cuadrado * (getPos().y) - 1, 0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glColor3ub(215, 220, 215);
	dibujarTorre();
	glScalef(5, 5, 5);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-(Tablero::Ancho_Cuadrado * (getPos().x) - 1), -(Tablero::Ancho_Cuadrado * (getPos().y) - 1), 0);
}




