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
#include "ListaTransformaciones.h"

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

	//lista de las transformaciones de peones

	ListaTransformaciones transfor;

	// Mouse interaction state
	Vector piezaAux;
	bool seleccionValida = false;

	// Keyboard input state
	int entrada[4] = {0,0,0,0};
	int numEntrada = 0;
	bool modoEntrada = false;

	// Visual feedback
	int selX = 0, selY = 0;
	bool haySeleccion = false;

	// Captured pieces
	char capturadasBlancas[16][16];
	int numCapturadasBlancas = 0;
	char capturadasNegras[16][16];
	int numCapturadasNegras = 0;

	// Pawn promotion
	bool promocionPendiente = false;
	int promocionX = 0, promocionY = 0;
	bool promocionColor = 0;

	// Game state
	bool juegoTerminado = false;
	char mensajeFin[64];

	static int vista;
	bool Enroque(int x, int y);
	bool Transformacion();
	void Tecla(unsigned char key);
	void procesarTecla(unsigned char key);
	void Inicializa();
	void initCapturadas();
	void reiniciar();
	
	void Dibuja();
	void dibujarSeleccion();
	void dibujarTurnoInfo();
	void dibujarCapturadas();
	void dibujarEstado();
	void dibujarPromocion();
	inline void MenuB();
	inline void MenuN();
	bool JaqueN();
	bool JaqueB();
	Vector convertirpixelscoordenadas(int xpixel, int ypixel);
	Vector PedirPieza(int x, int y);
	void MoverPieza(Vector, int x, int y);
	void ejecutarMovimiento(int srcX, int srcY, int dstX, int dstY);
	void registrarCaptura(int x, int y);
	void comprobarPromocion();
	void ejecutarPromocion(char tipo);
	void toggleTurno();
	
};

