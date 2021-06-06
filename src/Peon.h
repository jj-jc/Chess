#pragma once
#include "Vector.h"
#include "Alfil.h"
#include "Torre.h"

class Peon :public Alfil, public Torre {
public:
	Peon();
	Peon(int x, int y);
	~Peon();
	//bool Mover_Peon(int x, int y);
	bool PuedoMoverPeon(int x, int y);
	void dibujarPeon();
	void dibujarPeonconposicion();
	bool transformarse();
	virtual bool moverPieza(int x, int y);
	//EStos son los cambios


};