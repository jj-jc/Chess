#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "Tablero.h"
#include "glut.h"
#include <math.h>
#include "Pieza.h"
#include "Peon.h"
#include "Alfil.h"
#include "Caballo.h"
#include "Rey.h"
#include "Torre.h"
#include "Dama.h"
#include "Vector.h"

class Mundo
{

public: 
	Mundo();
	
	float x_ojo = 8.0;
	float y_ojo = -8.0;
	float z_ojo = 30.0;
	
	
	Tablero tablero;
	Alfil alfilB1, alfilB2;
	Caballo caballoB1, caballoB2;
	Dama damaB;
	Peon peonB1, peonB2, peonB3, peonB4, peonB5, peonB6, peonB7, peonB8;
	Rey reyB;
	Torre torreB1, torreB2;
	//NEGRAS
	Alfil alfilN1, alfilN2;
	Caballo caballoN1, caballoN2;
	Dama damaN;
	Peon peonN1, peonN2, peonN3, peonN4, peonN5, peonN6, peonN7, peonN8;
	Rey reyN;
	Torre torreN1, torreN2;
	int pulsaciones = 0;
	//void Menu();
	bool Enroque(int x, int y);
	void Tecla(unsigned char key);
	void Inicializa();
	//void RotarOjo();
	
	void Dibuja();
	inline void MenuB();
	inline void MenuN();
	bool JaqueN();
	bool JaqueB();
	Vector convertirpixelscoordenadas(int xpixel, int ypixel);
	Vector PedirPieza(int x, int y);
	void MoverPieza(Vector, int x, int y);
	
};



