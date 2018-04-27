#pragma once
#include "Vector.h"
class Caballo {
public:
	bool color;
	Caballo();
	Caballo(int x, int y);
	~Caballo();
	Vector posicion;
	void Movimiento(int x, int y);
	void Morir();
};