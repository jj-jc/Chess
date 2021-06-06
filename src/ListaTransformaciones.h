#pragma once
#include "Pieza.h"
#define MAX 16
class ListaTransformaciones:public Pieza {

public:
	ListaTransformaciones();
	~ListaTransformaciones();
	Pieza *transformaciones[MAX];
	int num;
	bool operator += (Pieza *mipieza);
	virtual bool moverPieza(int x, int y) { return 1; }

};

