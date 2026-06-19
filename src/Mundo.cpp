#include "Mundo.h"
#include <iostream>
#include <ETSIDI.h>
#include "CoordinadorAjedrez.h"
using namespace std;
int Mundo::vista;

Mundo::Mundo()
{
	mensajeFin[0] = '\0';
	initCapturadas();
}

void Mundo::initCapturadas()
{
	numCapturadasBlancas = 0;
	numCapturadasNegras = 0;
	for (int i = 0; i < 16; i++)
	{
		capturadasBlancas[i][0] = '\0';
		capturadasNegras[i][0] = '\0';
	}
}

void Mundo::reiniciar()
{
	Inicializa();
	haySeleccion = false;
	seleccionValida = false;
	modoEntrada = false;
	numEntrada = 0;
	promocionPendiente = false;
	juegoTerminado = false;
	mensajeFin[0] = '\0';
	initCapturadas();
	CoordinadorAjedrez::quien = 1;
}

void Mundo::Dibuja()
{
	gluLookAt(8.0, vista, 30.0,
			  8.0, 8.0, 0.0,
			  0.0, 1.0, 0.0);

	glDisable(GL_LIGHTING);
	tablero.dibujarTablero();
	if (!promocionPendiente) dibujarSeleccion();
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
	glDisable(GL_TEXTURE_2D);
	glTranslatef(-a, -b, -c);

	glDisable(GL_LIGHTING);
	dibujarTurnoInfo();
	dibujarCapturadas();
	if (promocionPendiente) dibujarPromocion();
	dibujarEstado();

	ETSIDI::setTextColor(200, 200, 200);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
	for (int idx = 0; idx < 8; idx++)
	{
		/* Horizontal labels (A-H): centered on each column, below the board */
		char letter[2] = {(char)('A' + idx), '\0'};
		ETSIDI::printxy(letter, 2 * idx + 1, -2, 0);
		/* Vertical labels (1-8): centered on each row, left of the board */
		char number[2] = {(char)('1' + idx), '\0'};
		ETSIDI::printxy(number, -2, 2 * idx + 1, 0);
	}

	glEnable(GL_LIGHTING);
}
void Mundo::Inicializa()
{
	x_ojo = 0;
	y_ojo = 10;
	z_ojo = 20;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero.posiciones[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			(Tablero::MatrizPuntero[i][j]) = 0;
		}
	}

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
	if (promocionPendiente)
	{
		if (key == 'Q' || key == 'q') ejecutarPromocion('D');
		else if (key == 'R' || key == 'r') ejecutarPromocion('T');
		else if (key == 'B' || key == 'b') ejecutarPromocion('A');
		else if (key == 'N' || key == 'n') ejecutarPromocion('C');
		return;
	}
	if (juegoTerminado)
	{
		if (key == 13 || key == ' ') reiniciar();
		return;
	}
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

void Mundo::registrarCaptura(int x, int y)
{
	Pieza *capturada = tablero.MatrizPuntero[x - 1][y - 1];
	if (capturada == 0) return;

	if (capturada->getColor() == 1)
	{
		if (numCapturadasBlancas < 16)
			strcpy(capturadasBlancas[numCapturadasBlancas++], capturada->getNombre());
	}
	else
	{
		if (numCapturadasNegras < 16)
			strcpy(capturadasNegras[numCapturadasNegras++], capturada->getNombre());
	}
}

void Mundo::comprobarPromocion()
{
	for (int x = 1; x <= 8; x++)
	{
		Pieza *p = tablero.MatrizPuntero[x - 1][8 - 1];
		if (p != 0 && strcmp(p->getNombre(), "Peon") == 0 && p->getColor() == 1)
		{
			promocionPendiente = true;
			promocionX = x;
			promocionY = 8;
			promocionColor = 1;
			return;
		}
		p = tablero.MatrizPuntero[x - 1][1 - 1];
		if (p != 0 && strcmp(p->getNombre(), "Peon") == 0 && p->getColor() == 0)
		{
			promocionPendiente = true;
			promocionX = x;
			promocionY = 1;
			promocionColor = 0;
			return;
		}
	}
}

void Mundo::ejecutarPromocion(char tipo)
{
	Pieza *peon = tablero.MatrizPuntero[promocionX - 1][promocionY - 1];
	if (peon == 0) return;

	int x = peon->getPos().x;
	int y = peon->getPos().y;

	tablero.MatrizPuntero[x - 1][y - 1] = 0;
	tablero.posiciones[x - 1][y - 1] = 0;

	Pieza *nueva = 0;
	if (tipo == 'D') nueva = new Dama();
	else if (tipo == 'T') nueva = new Torre();
	else if (tipo == 'A') nueva = new Alfil();
	else if (tipo == 'C') nueva = new Caballo();
	if (nueva == 0) return;

	nueva->setColor(promocionColor);
	nueva->SetPos(x, y);
	transfor += nueva;

	promocionPendiente = false;
}
inline void Mundo::MenuB()
{
}
inline void Mundo::MenuN()
{
}

/* Helper: true if the piece sits on a valid board square (1..8) */
static inline bool onBoard(Pieza &p) {
    Vector v = p.getPos();
    return v.x >= 1 && v.x <= 8 && v.y >= 1 && v.y <= 8;
}

bool Mundo::JaqueN()
{
	/* Only check pieces that are still physically on the board.
	 * Captured pieces are off-board and must not participate. */
	bool check = false;
	if (onBoard(alfilB1)) check = check || alfilB1.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(alfilB2)) check = check || alfilB2.PuedoMoverAlfil(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(caballoB1)) check = check || caballoB1.PuedoMoverCaballo(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(caballoB2)) check = check || caballoB2.PuedoMoverCaballo(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(torreB1)) check = check || torreB1.PuedoMoverTorre(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(torreB2)) check = check || torreB2.PuedoMoverTorre(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(damaB)) check = check || damaB.PuedoMoverDama(reyN.getPos().x, reyN.getPos().y);
	/* Pawns: use PuedoMoverPeon (diagonal ONE square forward) instead of
	 * PuedoMoverAlfil which would check along the entire diagonal. */
	if (onBoard(peonB1)) check = check || peonB1.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(peonB2)) check = check || peonB2.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(peonB3)) check = check || peonB3.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(peonB4)) check = check || peonB4.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(peonB5)) check = check || peonB5.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(peonB6)) check = check || peonB6.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(peonB7)) check = check || peonB7.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	if (onBoard(peonB8)) check = check || peonB8.PuedoMoverPeon(reyN.getPos().x, reyN.getPos().y);
	return check;
}
bool Mundo::JaqueB()
{
	bool check = false;
	if (onBoard(alfilN1)) check = check || alfilN1.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(alfilN2)) check = check || alfilN2.PuedoMoverAlfil(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(caballoN1)) check = check || caballoN1.PuedoMoverCaballo(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(caballoN2)) check = check || caballoN2.PuedoMoverCaballo(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(torreN1)) check = check || torreN1.PuedoMoverTorre(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(torreN2)) check = check || torreN2.PuedoMoverTorre(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(damaN)) check = check || damaN.PuedoMoverDama(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN1)) check = check || peonN1.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN2)) check = check || peonN2.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN3)) check = check || peonN3.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN4)) check = check || peonN4.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN5)) check = check || peonN5.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN6)) check = check || peonN6.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN7)) check = check || peonN7.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	if (onBoard(peonN8)) check = check || peonN8.PuedoMoverPeon(reyB.getPos().x, reyB.getPos().y);
	return check;
}
Vector Mundo::PedirPieza(int x, int y)
{
	if (juegoTerminado || promocionPendiente)
	{
		seleccionValida = false;
		Vector v;
		v.x = 0;
		v.y = 0;
		return v;
	}

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
	if (juegoTerminado || promocionPendiente)
	{
		seleccionValida = false;
		haySeleccion = false;
		return;
	}

	Vector coordenadas;
	coordenadas.x = 0;
	coordenadas.y = 0;
	coordenadas = convertirpixelscoordenadas(x, y);

	if (coordenadas.x < 1 || coordenadas.x > 8 || coordenadas.y < 1 || coordenadas.y > 8) return;
	if (posicionPieza.x < 1 || posicionPieza.x > 8 || posicionPieza.y < 1 || posicionPieza.y > 8) return;

	if (coordenadas.x == posicionPieza.x && coordenadas.y == posicionPieza.y)
	{
		haySeleccion = false;
		seleccionValida = false;
		return;
	}

	Pieza *pieza = tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1];
	if (pieza == 0)
	{
		seleccionValida = false;
		haySeleccion = false;
		return;
	}

	Pieza *captured = tablero.MatrizPuntero[coordenadas.x - 1][coordenadas.y - 1];
	if (captured != 0)
		registrarCaptura(coordenadas.x, coordenadas.y);

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
		if (captured)
		{
			int col = (captured->getColor() == 1)
				? numCapturadasBlancas - 1
				: numCapturadasNegras - 1;
			/* White captives at x=9..10, black captives at x=11..12 */
			int baseX = (captured->getColor() == 1) ? 9 : 11;
			captured->setDisplayPos(baseX + col / 4, 1 + 2 * (col % 4));
		}
		if (JaqueN()) reyN.jaque = 1;
		else reyN.jaque = 0;
		if (JaqueB()) reyB.jaque = 1;
		else reyB.jaque = 0;
		comprobarPromocion();
		if (!promocionPendiente) toggleTurno();
		haySeleccion = false;
		seleccionValida = false;
	}
	else
	{
		seleccionValida = false;
		haySeleccion = false;
	}
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
	/* Remember the piece that will be captured before moverPieza resets it */
	Pieza *captured = tablero.MatrizPuntero[dstX - 1][dstY - 1];
	if (captured != 0)
		registrarCaptura(dstX, dstY);
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
		/* Place the captured piece at a unique off-board position.
		 * moverPieza → SetPos → capturar() has already put it at (0,0);
		 * we override with a display coordinate. */
		if (captured)
		{
			int col = (captured->getColor() == 1)
				? numCapturadasBlancas - 1
				: numCapturadasNegras - 1;
			/* White captives at x=9..10, black captives at x=11..12.
			 * The piece drawing formula 2*pos-1 maps to visible world coords. */
			int baseX = (captured->getColor() == 1) ? 9 : 11;
			captured->setDisplayPos(baseX + col / 4, 1 + 2 * (col % 4));
		}
		if (JaqueN()) reyN.jaque = 1;
		else reyN.jaque = 0;
		if (JaqueB()) reyB.jaque = 1;
		else reyB.jaque = 0;
		comprobarPromocion();
		if (!promocionPendiente) toggleTurno();
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
	glColor4f(1.0f, 1.0f, 0.0f, 0.4f);
	glBegin(GL_POLYGON);
	glVertex3f(xpos, ypos, 0.05f);
	glVertex3f(xpos + Tablero::Ancho_Cuadrado, ypos, 0.05f);
	glVertex3f(xpos + Tablero::Ancho_Cuadrado, ypos + Tablero::Ancho_Cuadrado, 0.05f);
	glVertex3f(xpos, ypos + Tablero::Ancho_Cuadrado, 0.05f);
	glEnd();
	glDisable(GL_BLEND);

	glColor4f(1.0f, 1.0f, 0.0f, 0.8f);
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(xpos, ypos, 0.06f);
	glVertex3f(xpos + Tablero::Ancho_Cuadrado, ypos, 0.06f);
	glVertex3f(xpos + Tablero::Ancho_Cuadrado, ypos + Tablero::Ancho_Cuadrado, 0.06f);
	glVertex3f(xpos, ypos + Tablero::Ancho_Cuadrado, 0.06f);
	glEnd();
	glLineWidth(1.0f);
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
			sprintf(buf + strlen(buf), "_");
		}
		ETSIDI::setTextColor(255, 255, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("ENTRADA:", -10, 32, 2);
		ETSIDI::printxy(buf, 0, 32, 2);
	}

	const char *turnoStr = (CoordinadorAjedrez::quien == 1) ? "TURNO BLANCAS" : "TURNO NEGRAS";
	bool enJaque = (CoordinadorAjedrez::quien == 1) ? (reyB.jaque == 1) : (reyN.jaque == 1);
	const char *jaqueStr = enJaque ? "  JAQUE!" : "";

	ETSIDI::setTextColor(255, 255, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	glTranslatef(10.0, -5.0, 0.0);
	ETSIDI::printxy("TURNO:", 7, 32, 2);
	ETSIDI::printxy(turnoStr, 7, 29, 2);
	if (enJaque)
	{
		ETSIDI::setTextColor(255, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		char buf[64];
		sprintf(buf, "%s%s", turnoStr, " - JAQUE!");
		ETSIDI::printxy(buf, 7, 26, 2);
	}
	glTranslatef(-10.0, 5.0, 0.0);
}
void Mundo::dibujarCapturadas()
{
	char buf[256];
	buf[0] = '\0';

	if (numCapturadasBlancas > 0)
	{
		sprintf(buf, "BLANCAS CAPT: ");
		for (int i = 0; i < numCapturadasBlancas; i++)
		{
			char abr[4] = {capturadasBlancas[i][0], ' ', 0};
			if (strcmp(capturadasBlancas[i], "Caballo") == 0) strcpy(abr, "C ");
			else if (strcmp(capturadasBlancas[i], "Alfil") == 0) strcpy(abr, "A ");
			else if (strcmp(capturadasBlancas[i], "Torre") == 0) strcpy(abr, "T ");
			else if (strcmp(capturadasBlancas[i], "Dama") == 0) strcpy(abr, "D ");
			else if (strcmp(capturadasBlancas[i], "Peon") == 0) strcpy(abr, "P ");
			sprintf(buf + strlen(buf), "%s", abr);
		}
		ETSIDI::setTextColor(255, 100, 100);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		glTranslatef(11.5, -17.0, 0.0);
		ETSIDI::printxy(buf, 7, 16, 2);
		glTranslatef(-11.5, 17.0, 0.0);
	}

	if (numCapturadasNegras > 0)
	{
		buf[0] = '\0';
		sprintf(buf, "NEGRAS CAPT: ");
		for (int i = 0; i < numCapturadasNegras; i++)
		{
			char abr[4] = {capturadasNegras[i][0], ' ', 0};
			if (strcmp(capturadasNegras[i], "Caballo") == 0) strcpy(abr, "C ");
			else if (strcmp(capturadasNegras[i], "Alfil") == 0) strcpy(abr, "A ");
			else if (strcmp(capturadasNegras[i], "Torre") == 0) strcpy(abr, "T ");
			else if (strcmp(capturadasNegras[i], "Dama") == 0) strcpy(abr, "D ");
			else if (strcmp(capturadasNegras[i], "Peon") == 0) strcpy(abr, "P ");
			sprintf(buf + strlen(buf), "%s", abr);
		}
		ETSIDI::setTextColor(100, 100, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		glTranslatef(11.5, -19.0, 0.0);
		ETSIDI::printxy(buf, 7, 16, 2);
		glTranslatef(-11.5, 19.0, 0.0);
	}
}
void Mundo::dibujarEstado()
{
	if (juegoTerminado)
	{
		ETSIDI::setTextColor(255, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 28);
		glTranslatef(-5.0, 5.0, 0.0);
		ETSIDI::printxy(mensajeFin, 7, 20, 2);
		ETSIDI::setTextColor(200, 200, 200);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PRESIONE ESPACIO O ENTER PARA REINICIAR", 7, 17, 2);
		glTranslatef(5.0, -5.0, 0.0);
	}
}
void Mundo::dibujarPromocion()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(0.0f, 0.0f, 0.0f, 0.6f);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.1f);
	glVertex3f(16.0f, 0.0f, 0.1f);
	glVertex3f(16.0f, 16.0f, 0.1f);
	glVertex3f(0.0f, 16.0f, 0.1f);
	glEnd();
	glDisable(GL_BLEND);

	ETSIDI::setTextColor(255, 255, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 22);
	glTranslatef(3.0, 5.0, 0.0);
	ETSIDI::printxy("PROMOCION DE PEON", 7, 12, 2);
	ETSIDI::setTextColor(200, 200, 200);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Elija: Q=Dama  R=Torre  B=Alfil  N=Caballo", 7, 10, 2);
	glTranslatef(-3.0, -5.0, 0.0);
}
