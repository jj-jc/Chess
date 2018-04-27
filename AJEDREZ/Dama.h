#pragma once
#include "Vector.h"
class Dama {
public:
	bool color;
	Dama();
	Dama(int x, int y);
	~Dama();
	Vector posicion;
	void Movimiento(int x, int y);
	void Morir();
};