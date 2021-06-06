#include <string>
#include <iostream>
#include "Peon.h"
#include "Tablero.h"
#include "Mundo.h"
using namespace std;
Peon::Peon(int x, int y) {
	SetPos(x, y);
	
}
Peon::~Peon() {
}
Peon::Peon() {
	setNombre("Peon");
	
}
bool Peon::moverPieza(int x, int y) {
	int a, b;
	if (getColor() == 1) {
		a = 1;
		b = 2;
	}
	else {
		a = -1;
		b = 7;
	}

	int difx = x - getPos().x;
	int dify = y - getPos().y;
	//Comprobamos si las coordenadas elegidas cumplen con el alcance del peón,si es así ejecutamos la función mover
	 //añadir para posicion 7 para las negras
	
		if ((((dify == 1*a) || ((dify == 2*a) && (getPos().y == b)))) && (difx == 0)) { //añadir para posicion 7 para las negras
			if (Tablero::posiciones[getPos().x - 1][getPos().y + (dify) - 1] != 0) {
				return 0;
			}    //ESTE IF ES PARA QUE UN PEON NO PUEDA COMERSE A UNA PIEZA QUE TIENE DELANTE
			Torre::moverPieza(x, y);
			//IMPLEMENTAR FUNCION 
			/*
			if (posicion.y == 8||posicion.y==1) {
				Transformar();
			}
			*/
			return 1;
		}
		
		else if ((dify == 1*a) && (abs(difx) == 1)) {
			if (((Tablero::posiciones[getPos().x - 1][getPos().y - 1] == 1) && (Tablero::posiciones[x - 1][y - 1] == 2)) || (((Tablero::posiciones[getPos().x - 1][getPos().y - 1] == 2) && (Tablero::posiciones[x - 1][y - 1]) == 1))) {
				return Alfil::moverPieza(x, y);
			}
			return 0;
		}
		else {
			return 0; //Coordenadas Inválidas
		}
}
bool Peon::PuedoMoverPeon(int x, int y) {
	int a, b;
	if (getColor() == 1) {
		a = 1;
		b = 2;
	}
	else {
		a = -1;
		b = 7;
	}

	int difx = x - getPos().x;
	int dify = y - getPos().y;
	//Comprobamos si las coordenadas elegidas cumplen con el alcance del peón,si es así ejecutamos la función mover
	//añadir para posicion 7 para las negras

	if ((((dify == 1 * a) || ((dify == 2 * a) && (getPos().y == b)))) && (difx == 0)) { //añadir para posicion 7 para las negras
		if (Tablero::posiciones[getPos().x - 1][getPos().y + (dify)-1] != 0) {
			return 0;
		}    //ESTE IF ES PARA QUE UN PEON NO PUEDA COMERSE A UNA PIEZA QUE TIENE DELANTE
		return PuedoMoverTorre(x, y);
		
	}
	/*
	else if (posicion.x == 8) {
		//Transformar();
		return 1;
	}
	*/
	
	else if ((dify == 1 * a) && (abs(difx) == 1)) {
		
		return PuedoMoverAlfil(x, y);
	}
	
	else {
		return 0; //Coordenadas Inválidas
	}

}
bool Peon::transformarse() {
	if ((getPos().y == 8) || (getPos().y == 1)) {
		//ES NECESARIO QUE SEA STATIC O QUE SE GESTIONE EN MUNDO, EN EL MENU POR EJEMPLO
		//Mundo::Transformacion();

		return 1;
	}
}



void Peon::dibujarPeon()
{
	glPushMatrix();
	glScalef(1.0, 0.9, 1.0);
	glColor3ub(165 * (int)Peon::getColor()+50, 165 * (int)Peon::getColor()+50, 165 * (int)Peon::getColor()+50);
	Base(6.0);
	glPushMatrix();
	glTranslatef(0.0, 7.0, 0.0);
	Cilindro(2.0, 0.5);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, 9.0, 0.0);
	glColor3ub(150, 150, 150);  //CABEZA DEL PEON
	Esfera(2.0);
	glPopMatrix();
	glPopMatrix();
}
void Peon::dibujarPeonconposicion() {
	glTranslatef(Tablero::Ancho_Cuadrado * (getPos().x) - 1, Tablero::Ancho_Cuadrado * (getPos().y) - 1, 0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glColor3ub(215, 220, 215);
	dibujarPeon();
	glScalef(5, 5, 5);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-(Tablero::Ancho_Cuadrado * (getPos().x) - 1), -(Tablero::Ancho_Cuadrado * (getPos().y) - 1), 0);

}
/*
void Peon::Transformar() {
	
	char pieza[10];
	cout << "Ha llegado un peon a la ultima fila, elija la pieza en la que quiera convertirla: Dama, Torre, Caballo, Alfil" << endl;
	cin >> pieza;
	
	if ((strcmp(pieza, "Dama")==0)|| (strcmp(pieza, "dama")==0)  ) {
		Dama dama;
		dama.Color = 1;
		dama.SetPos(5, 5);
		
		dama.SetPos(this->posicion.x,this-> posicion.y);
		dama.dibujarDamaconposicion();
		
	}
	else if ((strcmp(pieza, "Caballo") == 0) || (strcmp(pieza, "caballo")==0)){
		Caballo caballo;
		caballo.SetPos(this->posicion.x, this->posicion.y);
		caballo.dibujarCaballoconposicion();
	}
	else if ((strcmp(pieza, "Torre") == 0) || (strcmp(pieza, "torre")==0)) {
		Torre torre;
		torre.SetPos(this->posicion.x, this->posicion.y);
		torre.dibujarTorreconposicion();


	}
	else if ((strcmp(pieza, "Alfil") == 0) || (strcmp(pieza, "alfil")==0)) {
		Alfil alfil;
		alfil.SetPos(this->posicion.x, this->posicion.y);
		alfil.dibujarAlfilconposicion();
	}
	
	SetPos(10,10);
	
	
}
*/


