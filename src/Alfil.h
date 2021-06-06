#pragma once
#include "Vector.h"
#include "Pieza.h"



class Alfil: virtual public Pieza {

public:
	Alfil();
	Alfil(int x, int y);
	~Alfil();
	void dibujarAlfil();
	void dibujarAlfilconposicion();
	//bool Mover_Alfil(int x, int y);

	bool PuedoMoverAlfil(int x, int y);
	bool Colision_Alfil(int x, int y);
	virtual bool moverPieza(int x, int y);
	
};


