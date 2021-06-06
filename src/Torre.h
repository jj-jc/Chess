#pragma once
#include "Vector.h"
#include "Pieza.h"

class Torre:virtual public Pieza {
public:
	Torre();
	Torre(int x, int y);
	~Torre();
	bool enroque = 0; //0-> se puede enrocar
	void dibujarTorre();
	void dibujarTorreconposicion();
	
	//bool Mover_Torre(int x, int y);
	bool PuedoMoverTorre(int x, int y);
	bool Colision_Torre(int x, int y);
	virtual bool moverPieza(int x, int y);
	
};