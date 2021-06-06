#pragma once
#include "glut.h"
#include "Pieza.h"


class Tablero {
	public:
		static float Ancho_Cuadrado;
		static float z;
		static int posiciones[8][8];
		static int jaqueB[8][8];
		static bool TURNO;
		static Pieza * MatrizPuntero[8][8];
		void Prueba();
		Tablero();
		void dibujarTablero();
		void dibujarCuadradoNegro();
		void dibujarCuadradoBlanco();
		
	

};
