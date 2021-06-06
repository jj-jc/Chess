#pragma once
#include "Vector.h"
#include "Pieza.h"
#include "Alfil.h"
#include "Torre.h"


class Rey:public Torre, public Alfil {
public:
	Rey();
	Rey(int x, int y);
	~Rey();
	bool jaque;  
	bool enroque = 0;   //SI EL ENROQUE ES 0 SE PUEDE ENROCAR
	
	bool PuedoMoverRey(int x, int y);
	void dibujarRey();
	void dibujarReyconposicion();
	virtual bool moverPieza(int x, int y);

	//CAMBIOS 

	
};