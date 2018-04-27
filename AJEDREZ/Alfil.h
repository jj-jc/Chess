#pragma once
#include "Vector.h"
class Alfil {
public:
	bool color;
	Alfil();
	Alfil(int x, int y);
	~Alfil();
	Vector posicion;
	void Movimiento(int x, int y);
	void Morir();
};
