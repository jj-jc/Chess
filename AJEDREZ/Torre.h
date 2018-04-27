#pragma once
#include "Vector.h"
class Torre {
public:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Torre();
	Torre(int x, int y);
	~Torre();
	Vector posicion;
	void Movimiento(int x, int y);
	void Morir();
};