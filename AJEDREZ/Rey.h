#pragma once
#include "Vector.h"
class Rey {
public:
	bool color;
	bool jaque;
	Rey();
	Rey(int x, int y);
	~Rey();
	Vector posicion;
	void Movimiento(int x, int y);
	void Morir();

};