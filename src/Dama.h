#pragma once

#include "Vector.h"
#include "Math.h"
#include "Pieza.h"
#include "Alfil.h"
#include "Torre.h"

class Dama:public Torre, public Alfil {
public:
	Dama();
	Dama(int x, int y);
	~Dama();
	
	bool PuedoMoverDama(int x, int y);

	void dibujarDama();
	void dibujarDamaconposicion();
	virtual bool moverPieza(int x, int y);
};