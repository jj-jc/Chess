#pragma once
#include "Vector.h"
class Peon {
public:
	bool color;
	Peon();
	Peon(int x, int y);
	~Peon();
	Vector posicion;
	void Movimiento(int x, int y);
	void Morir();
};