#include "Tablero.h"

float Tablero::Ancho_Cuadrado = 2;
float Tablero::z = 0;
int Tablero::posiciones[8][8];
int Tablero::jaqueB[8][8];
Pieza *Tablero::MatrizPuntero[8][8]; 
bool TURNO=1; //BLANCAS

Tablero::Tablero() {
	//BLANCAS
}

void Tablero::Prueba() {

	
	
}

void Tablero::dibujarCuadradoBlanco() {
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, Tablero::z);
	glVertex3f(Tablero::Ancho_Cuadrado, 0.0f, Tablero::z);
	glVertex3f(Tablero::Ancho_Cuadrado, Tablero::Ancho_Cuadrado, Tablero::z);
	glVertex3f(0.0f, Tablero::Ancho_Cuadrado, Tablero::z);
	glEnd();
	
	glColor3ub(10, 100, 100);
	glBegin(GL_POLYGON);
	glVertex3f(-15 * Tablero::Ancho_Cuadrado, -15 * Tablero::Ancho_Cuadrado, Tablero::z-5);
	glVertex3f(-15 *Tablero::Ancho_Cuadrado, 15 * Tablero::Ancho_Cuadrado, Tablero::z-5);
	glVertex3f(15 * Tablero::Ancho_Cuadrado, 15 * Tablero::Ancho_Cuadrado, Tablero::z - 5);
	glVertex3f(15 *Tablero::Ancho_Cuadrado, -15 *Tablero::Ancho_Cuadrado, Tablero::z-5);


	
	glEnd();
	
}

void Tablero::dibujarCuadradoNegro() {
	glColor3ub(150, 180, 130);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, Tablero::z);
	glVertex3f(Tablero::Ancho_Cuadrado, 0.0f, Tablero::z);
	glVertex3f(Tablero::Ancho_Cuadrado, Tablero::Ancho_Cuadrado, Tablero::z);
	glVertex3f(0.0f, Tablero::Ancho_Cuadrado, Tablero::z);
	glEnd();
}

void Tablero::dibujarTablero() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			glTranslatef(i*Tablero::Ancho_Cuadrado, j*Tablero::Ancho_Cuadrado, 0);
			if ((i + j) % 2 == 0) dibujarCuadradoNegro();
			else dibujarCuadradoBlanco();
			glTranslatef(-i * Tablero::Ancho_Cuadrado, -j * Tablero::Ancho_Cuadrado, 0);
		}
	}
}

