#pragma once

#include "Vector.h"
#include "Pieza.h"
#include "Math.h"


class Caballo:public Pieza {
public:
	Caballo();
	Caballo(int x, int y);
	~Caballo();
	bool Colision_Caballo(int x, int y);
	void dibujarCaballo();
	void dibujarCaballoconposicion();
	bool PuedoMoverCaballo(int x, int y);
	virtual bool moverPieza(int x, int y);
};
