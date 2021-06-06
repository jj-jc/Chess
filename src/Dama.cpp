#include <string>
#include "Dama.h"
#include "Tablero.h"
Dama::Dama(int x, int y) {
	SetPos(x, y);
	
}
Dama::Dama() {
	setNombre("Dama");
}
Dama::~Dama() {

}
bool Dama::moverPieza(int x, int y) {
	if (PuedoMoverDama(x,y)){
		SetPos(x, y);
		return 1;
	}
	return 0;
}
bool Dama::PuedoMoverDama(int x, int y) {
	if (PuedoMoverAlfil(x, y) || PuedoMoverTorre(x, y)) {
		return 1;
	}
	return 0;
}
void Dama::dibujarDama() {
	glPushMatrix();
	glScalef(1.0, 1.25, 1.0);
	glColor3ub(165 * (int)Dama::getColor()+50, 165 * (int)Dama::getColor()+50,165*(int)Dama::getColor()+50);
	Base(6.0);
	glPushMatrix();
	glTranslatef(0.0, 7.0, 0.0);
	glColor3ub(55, 215, 185); //CABEZA DE LA DAMA
	Cilindro(2.0, 2.0);
	glTranslatef(0.0, 1.0, 0.0);
	Cilindro(2.5, 0.5);
	Esfera(2.0);
	glTranslatef(0.0, 1.5, 0.0);
	Esfera(1.0);
	glPopMatrix();
	glPopMatrix();
}
void Dama::dibujarDamaconposicion() {
	glTranslatef(2*(getPos().x)-1, 2 * (getPos().y) - 1, 0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glScalef(0.2, 0.2, 0.2);
	glColor3ub(215, 220, 215);
	dibujarDama();
	glScalef(5, 5, 5);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-(2 * (getPos().x) - 1), -(2 * (getPos().y) - 1), 0);
	
}
