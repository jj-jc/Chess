#include "CoordinadorAjedrez.h"
#include "ETSIDI.h"
bool CoordinadorAjedrez::quien=1;





CoordinadorAjedrez::CoordinadorAjedrez()
{
	estado =INICIO;
	turno = BLANCA;
}


CoordinadorAjedrez::~CoordinadorAjedrez()
{
}

void CoordinadorAjedrez::dibuja()
{
	if (estado == INICIO)
	{
		gluLookAt(0, 0, 80, // posicion del ojo
			0, 0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glTranslatef(0, -10.0, 0.0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/AjedrezHarryPotter.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);
		glVertex3f(-15, -15, -0.1); //
		glTexCoord2d(1, 1);
		glVertex3f(15, -15, -0.1);
		glTexCoord2d(1, 0);
		glVertex3f(15, 15, -0.1);
		glTexCoord2d(0, 0);
		glVertex3f(-15, 15, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(0, 10.0, 0.0);
		glTranslatef(-15.0, -5.0, 0.0);
		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuentes/HarryPotter.ttf", 40);
		ETSIDI::printxy("A J E D R E Z", 7, 30);
		ETSIDI::setTextColor(0, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("P U L S E     L A     T E C L A     --E--     P A R A    E M P E Z A R ", -5, 20);
		ETSIDI::printxy("P U L S E     L A     T E C L A     --P--     P A R A    P A U S A R ", -5, 15);
		ETSIDI::setTextColor(255, 0, 0);
		ETSIDI::setFont("fuentes/HarryPotter.ttf", 18);
		ETSIDI::printxy("A L E J A N D R O    G O N Z A L E Z  y   J U A N     J O S E     J U R A D O ", -5, 25, 2);


	}
	else if (estado == JUEGO) {
		mundo.Dibuja();
	}
	else if (estado == PAUSA) {
		gluLookAt(0, 0, 80, // posicion del ojo
			0, 0, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Pausa.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);
		glVertex3f(-30, -30, -0.1); //
		glTexCoord2d(1, 1);
		glVertex3f(30, -30, -0.1);
		glTexCoord2d(1, 0);
		glVertex3f(30, 30, -0.1);
		glTexCoord2d(0, 0);
		glVertex3f(-30, 30, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glTranslatef(-10.0, -10.0, 0.0);
		ETSIDI::setTextColor(255, 0, 0);
		ETSIDI::setFont("fuentes/HarryPotter.ttf", 25);
		ETSIDI::printxy("P U L S E     L A     T E C L A     -E-     P A R A    C O N T I N U A R  ", -18, -10);
		ETSIDI::setTextColor(255, 0, 150);
		ETSIDI::setFont("fuentes/HarryPotter.ttf", 18);
		ETSIDI::printxy("A L E J A N D R O    G O N Z A L E Z // J U A N     J O S E     J U R A D O ", -10, 30, 2);
		ETSIDI::setTextColor(0, 0, 0);
		ETSIDI::setFont("fuentes/HarryPotter.ttf", 45);
	}
}
void CoordinadorAjedrez::tecla(unsigned char key)
{
	/*
	if(((mundo.reyB.jaque)==1)|| ((mundo.reyN.jaque) == 1)){
			estado = JAQUE;
	}
	*/
	if (estado == INICIO)
	{
		if ((key == 'e') || (key == 'E')) {
			estado = JUEGO;
		}
	}
	else if (estado == JUEGO)
	{
		if ((key == 'p') || (key == 'P')) {
			estado = PAUSA;
		}
		else {
			mundo.Tecla(key);
			mundo.Dibuja();
		}
		
	}
	else if (estado == PAUSA) {

		if ((key == 'e') || (key == 'E')) {
			estado = JUEGO;
		}
	}
	
	


	
}
