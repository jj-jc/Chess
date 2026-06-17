#include "Mundo.h"
#include <iostream>
#include <ETSIDI.h>
#include "CoordinadorAjedrez.h"
using namespace std;
int Mundo::vista;
/*void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
Mundo::Mundo()
{
}

void Mundo::Dibuja()
{
	gluLookAt(8.0, vista, 30.0, // posicion del ojo
			  8.0, 8.0, 0.0,	// hacia que punto mira  (0,0,0)
			  0.0, 1.0, 0.0);	// definimos hacia arriba (eje Y)

	glDisable(GL_LIGHTING);
	tablero.dibujarTablero();
	dibujarSeleccion();
	alfilB1.dibujarAlfilconposicion(), alfilB2.dibujarAlfilconposicion();
	caballoB1.dibujarCaballoconposicion(), caballoB2.dibujarCaballoconposicion();
	damaB.dibujarDamaconposicion();
	peonB1.dibujarPeonconposicion(), peonB2.dibujarPeonconposicion(), peonB3.dibujarPeonconposicion(), peonB4.dibujarPeonconposicion(), peonB5.dibujarPeonconposicion(), peonB6.dibujarPeonconposicion(), peonB7.dibujarPeonconposicion(), peonB8.dibujarPeonconposicion();
	reyB.dibujarReyconposicion();
	torreB1.dibujarTorreconposicion(), torreB2.dibujarTorreconposicion();
	alfilN1.dibujarAlfilconposicion(), alfilN2.dibujarAlfilconposicion();
	caballoN1.dibujarCaballoconposicion(), caballoN2.dibujarCaballoconposicion();
	damaN.dibujarDamaconposicion();
	peonN1.dibujarPeonconposicion(), peonN2.dibujarPeonconposicion(), peonN3.dibujarPeonconposicion(), peonN4.dibujarPeonconposicion(), peonN5.dibujarPeonconposicion(), peonN6.dibujarPeonconposicion(), peonN7.dibujarPeonconposicion(), peonN8.dibujarPeonconposicion();
	reyN.dibujarReyconposicion();
	torreN1.dibujarTorreconposicion(), torreN2.dibujarTorreconposicion();
	glEnd();
	int a = 7, b = -10, c = -2;
	glTranslatef(a, b, c);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);
	glVertex3f(-30, 0, -0.1);
	glTexCoord2d(1, 1);
	glVertex3f(30, 0, -0.1);
	glTexCoord2d(1, 0);
	glVertex3f(30, 60, -0.1);
	glTexCoord2d(0, 0);
	glVertex3f(-30, 60, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glTranslatef(-a, -b, -c);

	dibujarTurnoInfo();

	glTranslatef(-1.2, 0.5, 0.0);
	ETSIDI::setTextColor(200, 200, 200);
	ETSIDI::setFont("fuentes/HarryPotter.ttf", 35);
	for (char i = '1'; i < '9'; i++)
	{
		ETSIDI::printxy(&i, 2 * (i - 48), -2, 2);
		ETSIDI::printxy(&i, 0, 2 * (i - 48) - 2, 2);
	}

	glTranslatef(1.2, -0.5, 0.0);

	glEnable(GL_LIGHTING);
}
void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 10;
	z_ojo = 20;

	// INICIALIZAMOS LAS MATRICES

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero.posiciones[i][j] = 0;
		}
	}

	// INICIALIZACION DE MATRIX DE PUNTEROS
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			(Tablero::MatrizPuntero[i][j]) = 0;
		}
	}

	// BLANCAS
	alfilB1.setColor(1), alfilB2.setColor(1);
	alfilB1.SetPos(3, 1), alfilB2.SetPos(6, 1);
	tablero.MatrizPuntero[3 - 1][1 - 1] = &alfilB1;
	tablero.MatrizPuntero[6 - 1][1 - 1] = &alfilB2;
	caballoB1.setColor(1), caballoB2.setColor(1);
	caballoB1.SetPos(2, 1);
	caballoB2.SetPos(7, 1);
	tablero.MatrizPuntero[2 - 1][1 - 1] = &caballoB1;
	tablero.MatrizPuntero[7 - 1][1 - 1] = &caballoB2;
	damaB.setColor(1);
	damaB.SetPos(4, 1);
	tablero.MatrizPuntero[4 - 1][1 - 1] = &damaB;
	peonB1.setColor(1), peonB2.setColor(1), peonB3.setColor(1), peonB4.setColor(1), peonB5.setColor(1), peonB6.setColor(1), peonB7.setColor(1), peonB8.setColor(1);
	peonB1.SetPos(1, 2), peonB2.SetPos(2, 2), peonB3.SetPos(3, 2), peonB4.SetPos(4, 2), peonB5.SetPos(5, 2), peonB6.SetPos(6, 2), peonB7.SetPos(7, 2), peonB8.SetPos(8, 2);
	tablero.MatrizPuntero[1 - 1][2 - 1] = &peonB1;
	tablero.MatrizPuntero[2 - 1][2 - 1] = &peonB2;
	tablero.MatrizPuntero[3 - 1][2 - 1] = &peonB3;
	tablero.MatrizPuntero[4 - 1][2 - 1] = &peonB4;
	tablero.MatrizPuntero[5 - 1][2 - 1] = &peonB5;
	tablero.MatrizPuntero[6 - 1][2 - 1] = &peonB6;
	tablero.MatrizPuntero[7 - 1][2 - 1] = &peonB7;
	tablero.MatrizPuntero[8 - 1][2 - 1] = &peonB8;
	reyB.setColor(1);
	reyB.SetPos(5, 1);
	tablero.MatrizPuntero[5 - 1][1 - 1] = &reyB;
	torreB1.setColor(1), torreB2.setColor(1);
	torreB1.SetPos(1, 1), torreB2.SetPos(8, 1);
	tablero.MatrizPuntero[1 - 1][1 - 1] = &torreB1;
	tablero.MatrizPuntero[8 - 1][1 - 1] = &torreB2;

	// NEGRAS
	alfilN1.setColor(0), alfilN2.setColor(0);
	alfilN1.SetPos(3, 8), alfilN2.SetPos(6, 8);
	tablero.MatrizPuntero[3 - 1][8 - 1] = &alfilN1;
	tablero.MatrizPuntero[6 - 1][8 - 1] = &alfilN2;
	caballoN1.setColor(0), caballoN2.setColor(0);
	caballoN1.SetPos(2, 8), caballoN2.SetPos(7, 8);
	tablero.posiciones[6][7] = 2;
	tablero.MatrizPuntero[2 - 1][8 - 1] = &caballoN1;
	tablero.MatrizPuntero[7 - 1][8 - 1] = &caballoN2;
	damaN.setColor(0);
	damaN.SetPos(4, 8);
	tablero.MatrizPuntero[4 - 1][8 - 1] = &damaN;
	peonN1.setColor(0), peonN2.setColor(0), peonN3.setColor(0), peonN4.setColor(0), peonN5.setColor(0), peonN6.setColor(0), peonN7.setColor(0), peonN8.setColor(0);
	peonN1.SetPos(1, 7), peonN2.SetPos(2, 7), peonN3.SetPos(3, 7), peonN4.SetPos(4, 7), peonN5.SetPos(5, 7), peonN6.SetPos(6, 7), peonN7.SetPos(7, 7), peonN8.SetPos(8, 7);
	tablero.MatrizPuntero[1 - 1][7 - 1] = &peonN1;
	tablero.MatrizPuntero[2 - 1][7 - 1] = &peonN2;
	tablero.MatrizPuntero[3 - 1][7 - 1] = &peonN3;
	tablero.MatrizPuntero[4 - 1][7 - 1] = &peonN4;
	tablero.MatrizPuntero[5 - 1][7 - 1] = &peonN5;
	tablero.MatrizPuntero[6 - 1][7 - 1] = &peonN6;
	tablero.MatrizPuntero[7 - 1][7 - 1] = &peonN7;
	tablero.MatrizPuntero[8 - 1][7 - 1] = &peonN8;
	reyN.setColor(0);
	reyN.SetPos(5, 8);
	tablero.MatrizPuntero[5 - 1][8 - 1] = &reyN;
	torreN1.setColor(0), torreN2.setColor(0);
	torreN1.SetPos(1, 8), torreN2.SetPos(8, 8);
	tablero.MatrizPuntero[1 - 1][8 - 1] = &torreN1;
	tablero.MatrizPuntero[8 - 1][8 - 1] = &torreN2;
}
bool Mundo::Enroque(int x, int y)
{
	if ((reyB.enroque == 0))
	{
		if (torreB1.enroque == 0)
		{
			if ((x == 3) && (y == 1) && (torreB1.Colision_Torre(4, 1) == 0))
			{
				torreB1.SetPos(4, 1);
				reyB.SetPos(3, 1);
				return 1;
			}
		}
		if (torreB2.enroque == 0)
		{
			if ((x == 7) && (y == 1) && (torreB2.Colision_Torre(6, 1) == 0))
			{
				torreB2.SetPos(6, 1);
				reyB.SetPos(7, 1);
				return 1;
			}
		}
	}

	if ((reyN.enroque == 0))
	{
		if (torreN1.enroque == 0)
		{
			if ((x == 3) && (y == 8) && (torreN1.Colision_Torre(4, 8) == 0))
			{
				torreN1.SetPos(4, 8);
				reyN.SetPos(3, 8);
				return 1;
			}
		}
		if (torreN2.enroque == 0)
		{
			if ((x == 7) && (y == 8) && (torreN2.Colision_Torre(6, 8) == 0))
			{
				torreN2.SetPos(6, 8);
				reyN.SetPos(7, 8);
				return 1;
			}
		}
	}
	return 0;
}
bool Mundo::Transformacion()
{
	char eleccion;

	cout << "Escoja la pieza que desea transformar" << endl
		 << "D-Dama\nT-Torre\nA-alfil\nC-Caballo" << endl;

	cin >> eleccion;

	if (eleccion == 'D')
	{
		transfor += new Dama;
		return 1;
	}
	if (eleccion == 'T')
	{
		transfor += new Torre;
		return 1;
	}
	if (eleccion == 'A')
	{
		transfor += new Alfil;
		return 1;
	}
	if (eleccion == 'C')
	{
		transfor += new Caballo;
		return 1;
	}
	else
		return false;
}
void Mundo::Tecla(unsigned char key)
{
	modoEntrada = true;
	procesarTecla(key);
}
void Mundo::procesarTecla(unsigned char key)
{
	if (key == 27)
	{
		modoEntrada = false;
		numEntrada = 0;
		return;
	}
	if (key == 8 || key == 127)
	{
		if (numEntrada > 0) numEntrada--;
		return;
	}

	bool esColumna = (numEntrada % 2 == 0);
	int val = -1;

	if (key >= 'a' && key <= 'h') val = key - 'a' + 1;
	else if (key >= 'A' && key <= 'H') val = key - 'A' + 1;
	else if (key >= '1' && key <= '8') val = key - '0';

	if (esColumna && val >= 1 && val <= 8)
	{
		if (numEntrada < 4) entrada[numEntrada++] = val;
	}
	else if (!esColumna && val >= 1 && val <= 8)
	{
		if (numEntrada < 4) entrada[numEntrada++] = val;
	}

	if (numEntrada == 4)
	{
		int srcX = entrada[0], srcY = entrada[1];
		int dstX = entrada[2], dstY = entrada[3];
		Pieza *pieza = tablero.MatrizPuntero[srcX - 1][srcY - 1];

		bool valido = false;
		if (pieza != 0)
		{
			bool esBlanca = pieza->getColor();
			bool turnoBlancas = (CoordinadorAjedrez::quien == 1);
			if (esBlanca == turnoBlancas) valido = true;
		}

		if (valido)
			ejecutarMovimiento(srcX, srcY, dstX, dstY);

		modoEntrada = false;
		numEntrada = 0;
	}
}
inline void Mundo::MenuB()
{
}
inline void Mundo::MenuN()
{
}

bool Mundo::JaqueN()
{
	return (alfilB1.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || alfilB2.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || caballoB1.PuedoMoverCaballo(reyN.getPos().x, reyN.getPos().y) || caballoB2.PuedoMoverCaballo(reyN.getPos().x, reyN.getPos().y) || torreB1.PuedoMoverTorre(reyN.getPos().x, reyN.getPos().y) || torreB2.PuedoMoverTorre(reyN.getPos().x, reyN.getPos().y) || damaB.PuedoMoverDama(reyN.getPos().x, reyN.getPos().y) ||
			peonB1.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || peonB2.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || peonB3.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || peonB4.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || peonB5.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || peonB6.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || peonB7.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y) || peonB8.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y));
}
bool Mundo::JaqueB()
{
	return (alfilN1.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || alfilN2.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || caballoN1.PuedoMoverCaballo(reyB.getPos().x, reyB.getPos().y) || caballoN2.PuedoMoverCaballo(reyB.getPos().x, reyB.getPos().y) || torreN1.PuedoMoverTorre(reyB.getPos().x, reyB.getPos().y) || torreN2.PuedoMoverTorre(reyB.getPos().x, reyB.getPos().y) || damaN.PuedoMoverDama(reyB.getPos().x, reyB.getPos().y) ||
			peonN1.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || peonN2.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || peonN3.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || peonN4.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || peonN5.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || peonN6.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || peonN7.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y) || peonN8.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y));
}
Vector Mundo::PedirPieza(int x, int y)
{
	Vector coordenadaspos;
	coordenadaspos.x = 0;
	coordenadaspos.y = 0;

	coordenadaspos = convertirpixelscoordenadas(x, y);

	if (coordenadaspos.x < 1 || coordenadaspos.x > 8 || coordenadaspos.y < 1 || coordenadaspos.y > 8)
	{
		seleccionValida = false;
		return coordenadaspos;
	}

	Pieza *p = tablero.MatrizPuntero[coordenadaspos.x - 1][coordenadaspos.y - 1];
	if (p == 0)
	{
		seleccionValida = false;
		return coordenadaspos;
	}

	bool esBlanca = p->getColor();
	bool turnoBlancas = (CoordinadorAjedrez::quien == 1);
	if (esBlanca != turnoBlancas)
	{
		seleccionValida = false;
		return coordenadaspos;
	}

	seleccionValida = true;
	haySeleccion = true;
	selX = coordenadaspos.x;
	selY = coordenadaspos.y;

	return coordenadaspos;
}
void Mundo::MoverPieza(Vector posicionPieza, int x, int y)
{
	if (!seleccionValida) return;

	Vector coordenadas;
	coordenadas.x = 0;
	coordenadas.y = 0;
	coordenadas = convertirpixelscoordenadas(x, y);

	if (coordenadas.x < 1 || coordenadas.x > 8 || coordenadas.y < 1 || coordenadas.y > 8) return;
	if (posicionPieza.x < 1 || posicionPieza.x > 8 || posicionPieza.y < 1 || posicionPieza.y > 8) return;

	Pieza *pieza = tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1];
	if (pieza == 0) return;

	bool exito = false;
	if (strcmp(pieza->getNombre(), "Rey") == 0)
	{
		exito = pieza->moverPieza(coordenadas.x, coordenadas.y);
		if (!exito)
		{
			exito = Enroque(coordenadas.x, coordenadas.y);
		}
	}
	else
	{
		exito = pieza->moverPieza(coordenadas.x, coordenadas.y);
	}

	if (exito)
	{
		if (JaqueN()) reyN.jaque = 1;
		else reyN.jaque = 0;
		if (JaqueB()) reyB.jaque = 1;
		else reyB.jaque = 0;
		toggleTurno();
	}

	haySeleccion = false;
	seleccionValida = false;
}
Vector Mundo::convertirpixelscoordenadas(int xpixel, int ypixel)
{
	Vector coordenadas;
	coordenadas.x = 0;
	coordenadas.y = 0;

	extern GLdouble g_modelview[16], g_projection[16];
	extern GLint g_viewport[4];

	GLdouble winX = (GLdouble)xpixel;
	GLdouble winY = (GLdouble)g_viewport[3] - (GLdouble)ypixel;

	GLdouble nearX, nearY, nearZ, farX, farY, farZ;
	gluUnProject(winX, winY, 0.0, g_modelview, g_projection, g_viewport, &nearX, &nearY, &nearZ);
	gluUnProject(winX, winY, 1.0, g_modelview, g_projection, g_viewport, &farX, &farY, &farZ);

	double t = -nearZ / (farZ - nearZ);
	double worldX = nearX + t * (farX - nearX);
	double worldY = nearY + t * (farY - nearY);

	int ix = (int)(worldX / Tablero::Ancho_Cuadrado);
	int iy = (int)(worldY / Tablero::Ancho_Cuadrado);

	if (ix >= 0 && ix < 8) coordenadas.x = ix + 1;
	if (iy >= 0 && iy < 8) coordenadas.y = iy + 1;

	return coordenadas;
}
void Mundo::ejecutarMovimiento(int srcX, int srcY, int dstX, int dstY)
{
	if (srcX < 1 || srcX > 8 || srcY < 1 || srcY > 8 || dstX < 1 || dstX > 8 || dstY < 1 || dstY > 8) return;
	Pieza *pieza = tablero.MatrizPuntero[srcX - 1][srcY - 1];
	if (pieza == 0) return;
	bool exito = false;
	if (strcmp(pieza->getNombre(), "Rey") == 0)
	{
		exito = pieza->moverPieza(dstX, dstY);
		if (!exito) exito = Enroque(dstX, dstY);
	}
	else
	{
		exito = pieza->moverPieza(dstX, dstY);
	}
	if (exito)
	{
		if (JaqueN()) reyN.jaque = 1;
		else reyN.jaque = 0;
		if (JaqueB()) reyB.jaque = 1;
		else reyB.jaque = 0;
		toggleTurno();
	}
}
void Mundo::toggleTurno()
{
	if (CoordinadorAjedrez::quien == 1) CoordinadorAjedrez::quien = 0;
	else CoordinadorAjedrez::quien = 1;
}
void Mundo::dibujarSeleccion()
{
	if (!haySeleccion) return;
	float xpos = (selX - 1) * Tablero::Ancho_Cuadrado;
	float ypos = (selY - 1) * Tablero::Ancho_Cuadrado;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0f, 1.0f, 0.0f, 0.3f);
	glBegin(GL_POLYGON);
	glVertex3f(xpos, ypos, 0.05f);
	glVertex3f(xpos + Tablero::Ancho_Cuadrado, ypos, 0.05f);
	glVertex3f(xpos + Tablero::Ancho_Cuadrado, ypos + Tablero::Ancho_Cuadrado, 0.05f);
	glVertex3f(xpos, ypos + Tablero::Ancho_Cuadrado, 0.05f);
	glEnd();
	glDisable(GL_BLEND);
}
void Mundo::dibujarTurnoInfo()
{
	if (modoEntrada)
	{
		char buf[32];
		const char *cols = "abcdefgh";
		buf[0] = '\0';
		for (int i = 0; i < numEntrada; i++)
		{
			if (i % 2 == 0)
				sprintf(buf + strlen(buf), "%c ", cols[entrada[i] - 1]);
			else
				sprintf(buf + strlen(buf), "%d ", entrada[i]);
		}
		if (numEntrada < 4)
		{
			char expected = (numEntrada % 2 == 0) ? '?' : '?';
			sprintf(buf + strlen(buf), "_");
		}
		ETSIDI::setTextColor(255, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("ENTRADA:", -10, 32, 2);
		ETSIDI::printxy(buf, 0, 32, 2);
	}

	const char *turnoStr = (CoordinadorAjedrez::quien == 1) ? "TURNO BLANCAS" : "TURNO NEGRAS";
	ETSIDI::setTextColor(255, 255, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	glTranslatef(10.0, -5.0, 0.0);
	ETSIDI::printxy("TURNO:", 7, 32, 2);
	ETSIDI::printxy(turnoStr, 7, 29, 2);
	glTranslatef(-10.0, 5.0, 0.0);
}
