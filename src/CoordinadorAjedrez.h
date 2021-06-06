#pragma once
#include "Mundo.h"
class CoordinadorAjedrez
{
public:
	CoordinadorAjedrez();
	~CoordinadorAjedrez();
	//void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	
	void dibuja();
	Mundo mundo;
	 enum Estado { INICIO, JUEGO,PAUSA,JAQUE};
	 enum Turno{BLANCA, NEGRA};
	 Estado estado;
	 Turno turno; 
	 static bool quien;
};

