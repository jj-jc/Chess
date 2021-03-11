
#pragma once
#include "Mundo.h"
#include <iostream>
#include <ETSIDI.h> 
#include "CoordinadorAjedrez.h"
using namespace std;

/*void Mundo::RotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
Mundo::Mundo() {

}

void Mundo::Dibuja()
{
	gluLookAt(8.0,8.0,30.0,  // posicion del ojo 
			8.0, 8.0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);
	tablero.dibujarTablero();
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
	glVertex3f(-30, 0, -0.1); //
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

	

	glTranslatef(-1.2, 0.5, 0.0);
	ETSIDI::setTextColor(200, 200, 200);
	ETSIDI::setFont("fuentes/HarryPotter.ttf", 35);
	for (char i = '1'; i < '9'; i++) {
		ETSIDI::printxy(&i, 2 * (i - 48), -2, 2);
		ETSIDI::printxy(&i, 0, 2 * (i - 48) - 2, 2);
	}

	glTranslatef(1.2, -0.5, 0.0);
	
	
	
	
	
	

	glEnable(GL_LIGHTING);

}




void Mundo::Inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
	
	//INICIALIZAMOS LAS MATRICES 
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tablero.posiciones[i][j] = 0;
		}
	}

	//INICIALIZACION DE MATRIX DE PUNTEROS
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			(Tablero::MatrizPuntero[i][j]) = 0;
		}
	}
	
	
	
	//BLANCAS
	alfilB1.Color = 1, alfilB2.Color = 1;
	alfilB1.SetPos(3, 1),alfilB2.SetPos(6,1);
	tablero.MatrizPuntero[3 - 1][1 - 1] = &alfilB1;
	tablero.MatrizPuntero[6 - 1][1 - 1] = &alfilB2;
	caballoB1.Color = 1, caballoB2.Color = 1;
	caballoB1.SetPos(2, 1); 
	caballoB2.SetPos(7, 1);
	tablero.MatrizPuntero[2 - 1][1 - 1] = &caballoB1;
	tablero.MatrizPuntero[7 - 1][1 - 1] = &caballoB2;
	damaB.Color = 1;
	damaB.SetPos(4, 1);
	tablero.MatrizPuntero[4 - 1][1 - 1] = &damaB;
	peonB1.Color = 1, peonB2.Color = 1, peonB3.Color = 1, peonB4.Color = 1, peonB5.Color = 1, peonB6.Color = 1, peonB7.Color = 1, peonB8.Color = 1;
	peonB1.SetPos(1, 2), peonB2.SetPos(2, 2), peonB3.SetPos(3, 2), peonB4.SetPos(4, 2), peonB5.SetPos(5, 2), peonB6.SetPos(6, 2), peonB7.SetPos(7, 2), peonB8.SetPos(8, 2);
	tablero.MatrizPuntero[1 - 1][2 - 1] = &peonB1;
	tablero.MatrizPuntero[2 - 1][2 - 1] = &peonB2;
	tablero.MatrizPuntero[3 - 1][2 - 1] = &peonB3;
	tablero.MatrizPuntero[4 - 1][2 - 1] = &peonB4;
	tablero.MatrizPuntero[5 - 1][2 - 1] = &peonB5;
	tablero.MatrizPuntero[6 - 1][2 - 1] = &peonB6;
	tablero.MatrizPuntero[7 - 1][2 - 1] = &peonB7;
	tablero.MatrizPuntero[8 - 1][2 - 1] = &peonB8;
	reyB.Color = 1;
	reyB.SetPos(5, 1);
	tablero.MatrizPuntero[5 - 1][1 - 1] = &reyB;
	torreB1.Color = 1, torreB2.Color = 1;
	torreB1.SetPos(1, 1), torreB2.SetPos(8, 1);
	tablero.MatrizPuntero[1 - 1][1 - 1] = &torreB1;
	tablero.MatrizPuntero[8 - 1][1 - 1] = &torreB2;
	

	//NEGRAS
	alfilN1.Color = 0, alfilN2.Color = 0;
	alfilN1.SetPos(3, 8), alfilN2.SetPos(6, 8);
	tablero.MatrizPuntero[3 - 1][8 - 1] = &alfilN1;
	tablero.MatrizPuntero[6 - 1][8 - 1] = &alfilN2;
	caballoN1.Color = 0, caballoN2.Color = 0;
	caballoN1.SetPos(2, 8), caballoN2.SetPos(7, 8);
	tablero.posiciones[6][7] = 2;
	tablero.MatrizPuntero[2 - 1][8 - 1] = &caballoN1;
	tablero.MatrizPuntero[7 - 1][8 - 1] = &caballoN2;
	damaN.Color = 0;
	damaN.SetPos(4, 8);
	tablero.MatrizPuntero[4 - 1][8 - 1] = &damaN;
	peonN1.Color = 0, peonN2.Color = 0, peonN3.Color = 0, peonN4.Color = 0, peonN5.Color = 0, peonN6.Color = 0, peonN7.Color = 0, peonN8.Color = 0;
	peonN1.SetPos(1, 7), peonN2.SetPos(2, 7), peonN3.SetPos(3, 7), peonN4.SetPos(4, 7), peonN5.SetPos(5, 7), peonN6.SetPos(6, 7), peonN7.SetPos(7, 7), peonN8.SetPos(8, 7);
	tablero.MatrizPuntero[1 - 1][7 - 1] = &peonN1;
	tablero.MatrizPuntero[2 - 1][7 - 1] = &peonN2;
	tablero.MatrizPuntero[3 - 1][7 - 1] = &peonN3;
	tablero.MatrizPuntero[4 - 1][7 - 1] = &peonN4;
	tablero.MatrizPuntero[5 - 1][7 - 1] = &peonN5;
	tablero.MatrizPuntero[6 - 1][7 - 1] = &peonN6;
	tablero.MatrizPuntero[7 - 1][7 - 1] = &peonN7;
	tablero.MatrizPuntero[8 - 1][7 - 1] = &peonN8;
	reyN.Color = 0;
	reyN.SetPos(5, 8);
	tablero.MatrizPuntero[5 - 1][8 - 1] = &reyN;
	torreN1.Color = 0, torreN2.Color = 0;
	torreN1.SetPos(1, 8), torreN2.SetPos(8, 8);
	tablero.MatrizPuntero[1 - 1][8 - 1] = &torreN1;
	tablero.MatrizPuntero[8 - 1][8 - 1] = &torreN2;



}
bool Mundo::Enroque(int x, int y) {
	if ((reyB.enroque==0)) {
		if (torreB1.enroque == 0) {
			if ((x == 3) && (y == 1) && (torreB1.Colision_Torre(4, 1) == 0)) {
				torreB1.SetPos(4, 1);
				reyB.SetPos(3, 1);
				return 1;
			}
		}
			if (torreB2.enroque == 0) {
				if ((x == 7) && (y == 1) && (torreB2.Colision_Torre(6, 1) == 0)) {
					torreB2.SetPos(6, 1);
					reyB.SetPos(7, 1);
					return 1;
				}
			}
	}

	if ((reyN.enroque == 0)) {
		if (torreN1.enroque == 0) {
			if ((x == 3) && (y == 8) && (torreN1.Colision_Torre(4, 8) == 0)) {
				torreN1.SetPos(4, 8);
				reyN.SetPos(3, 8);
			}
		}
		if (torreN2.enroque == 0) {
			if ((x == 7) && (y == 8) && (torreN2.Colision_Torre(6, 8) == 0)) {
				torreN2.SetPos(6, 8);
				reyN.SetPos(7, 8);
			}
		}
	}

}
void Mundo::Tecla(unsigned char key)
{
	if (CoordinadorAjedrez::quien == 1) {
		MenuB();
		CoordinadorAjedrez::quien = 0;
	}
	else if(CoordinadorAjedrez::quien == 0){
		MenuN();
		CoordinadorAjedrez::quien = 1;
	}
	
}
inline void Mundo::MenuB() {
	int xpos, ypos;
	int x, y;
	bool pasoturno = FALSE;
	
	do{
		cout << "\t\t\tTURNO DE LAS BLANCAS. Escriba las coordenadas de la Pieza que desee mover:\t ";
		cin >> xpos >> ypos;
		
		//Hacemos un bucle hasta del que no puede salir hasata que ponga la coordenada de una pieza blanca
		do {
			if ((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1] == 0) || ((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1]->Color) == 0)) {
				cout << "\t\t\tCoordenada incorrecta, introduzca otra:\t ";
				cin >> xpos >> ypos;
			}
		} while (((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1]) == 0) || ((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1]->Color) == 0));

		//Una vez que nos hemos asegurado que coje una pieza blancaa procedemos al movimiento de la pieza
		//Ahora ponemos identificamos la pieza seleccionada

		cout << "La pieza que quieres mover es un " << ( tablero.MatrizPuntero[xpos - 1][ypos - 1]->nombre) << endl;
		cout << "Indique las coordenadas a las que quiere mover el " << tablero.MatrizPuntero[xpos - 1][ypos - 1]->nombre<<endl;
		cin >> x >> y;
		if (strcmp((tablero.MatrizPuntero[xpos - 1][ypos - 1]->nombre), "Rey") == 0) {
			if (((tablero.MatrizPuntero[xpos - 1][ypos - 1]))->moverPieza(x, y) != 1) {
				pasoturno=Enroque(x, y);
			}
		}
		else {
			pasoturno = (((tablero.MatrizPuntero[xpos - 1][ypos - 1]))->moverPieza(x, y));
		}
		
	} while (pasoturno==FALSE);
			

    if (Mundo::JaqueN()) {
			reyN.jaque = 1;
			
			cout<< "\t\t\t";
			cout << "****************" <<"\tJAQUE AL REY NEGRO\t" << "****************";
			cout << endl;
			}
    if (Mundo::JaqueN()==0) {
				reyN.jaque = 0;
			}
    
    if (Mundo::JaqueB()) {
				reyB.jaque = 1;
				printf("\t\t\t");
				cout << "****************" << "\tJAQUE AL REY BLANCO\t" << "****************";
				cout << endl;
			}
    if (Mundo::JaqueB() == 0) {
				reyB.jaque = 0;
			}
    
    cout<< "\n\n";
    for (int j = 7; j > -1; j--) {
				printf("\n");
				for (int i = 0; i < 8; i++) {
					printf("%d\t",tablero.posiciones[i][j]);
				}
			}
    cout<<"\n";

	
    cout<<"\n";
    for (int j = 7; j > -1; j--) {
				printf("\n");
				for (int i = 0; i < 8; i++) {
					printf("%d  ", (int)Mundo::tablero.MatrizPuntero[i][j]);
				}
			}
    cout<<"\n";

}
inline void Mundo::MenuN() {
	int xpos, ypos;
	int x, y;
	bool pasoturno = FALSE;

	do {
		cout << "\t\t\tTURNO DE LAS NEGRAS. Escriba las coordenadas de la Pieza que desee mover:\t ";
		cin >> xpos >> ypos;

		//Hacemos un bucle hasta del que no puede salir hasata que ponga la coordenada de una pieza blanca
		do {
			if ((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1] == 0) || ((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1]->Color) == 1)) {
				cout << "\t\t\tCoordenada incorrecta, introduzca otra:\t ";
				cin >> xpos >> ypos;
			}
		} while (((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1]) == 0) || ((Mundo::tablero.MatrizPuntero[xpos - 1][ypos - 1]->Color) == 1));

		//Una vez que nos hemos asegurado que coje una pieza negra procedemos al movimiento de la pieza
		//Ahora identificamos la pieza seleccionada

		cout << "La pieza que quieres mover es un " << (tablero.MatrizPuntero[xpos - 1][ypos - 1]->nombre) << endl;
		cout << "Indique las coordenadas a las que quiere mover el " << tablero.MatrizPuntero[xpos - 1][ypos - 1]->nombre << endl;
		cin >> x >> y;
		if (strcmp((tablero.MatrizPuntero[xpos - 1][ypos - 1]->nombre), "Rey") == 0) {
			if (((tablero.MatrizPuntero[xpos - 1][ypos - 1]))->moverPieza(x, y) != 1) {
				pasoturno = Enroque(x, y);
			}
		}
		else {
			pasoturno = (((tablero.MatrizPuntero[xpos - 1][ypos - 1]))->moverPieza(x, y));
		}

	} while (pasoturno == FALSE);

		
		if (Mundo::JaqueN()) {
			reyN.jaque = 1;

			printf("\t\t\t");
			cout << "****************" << "\tJAQUE AL REY NEGRO\t" << "****************";
			cout << endl;
		}
		if (Mundo::JaqueN() == 0) {
			reyN.jaque = 0;
		}

		if (Mundo::JaqueB()) {
			reyB.jaque = 1;
			printf("\t\t\t");
			cout << "****************" << "\tJAQUE AL REY BLANCO\t" << "****************";
			cout << endl;
		}
		if (Mundo::JaqueB() == 0) {
			reyB.jaque = 0;
		}

		cout << "\n\n";
		for (int j = 7; j > -1; j--) {
			cout<< "\n";
			for (int i = 0; i < 8; i++) {
				cout<< ("%d\t", Mundo::tablero.posiciones[i][j]);
			}
		}

}

bool Mundo::JaqueN() {
	return(alfilB1.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y)|| alfilB2.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y)|| caballoB1.PuedoMoverCaballo(reyN.posicion.x, reyN.posicion.y)|| caballoB2.PuedoMoverCaballo(reyN.posicion.x, reyN.posicion.y) || torreB1.PuedoMoverTorre(reyN.posicion.x, reyN.posicion.y) || torreB2.PuedoMoverTorre(reyN.posicion.x, reyN.posicion.y) || damaB.PuedoMoverDama(reyN.posicion.x, reyN.posicion.y)||
		peonB1.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y)|| peonB2.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y) || peonB3.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y) || peonB4.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y) || peonB5.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y) || peonB6.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y) || peonB7.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y) || peonB8.PuedoMoverAlfil(reyN.posicion.x, reyN.posicion.y));
}
bool Mundo::JaqueB() {
	return(alfilN1.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || alfilN2.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || caballoN1.PuedoMoverCaballo(reyB.posicion.x, reyB.posicion.y) || caballoN2.PuedoMoverCaballo(reyB.posicion.x, reyB.posicion.y) || torreN1.PuedoMoverTorre(reyB.posicion.x, reyB.posicion.y) || torreN2.PuedoMoverTorre(reyB.posicion.x, reyB.posicion.y) || damaN.PuedoMoverDama(reyB.posicion.x, reyB.posicion.y) ||
		peonN1.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || peonN2.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || peonN3.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || peonN4.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || peonN5.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || peonN6.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || peonN7.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y) || peonN8.PuedoMoverAlfil(reyB.posicion.x, reyB.posicion.y));
}
Vector Mundo::PedirPieza(int x, int  y)
{
	cout << x << endl << y << endl;

	Vector coordenadaspos;
	coordenadaspos.x = 0;
	coordenadaspos.y = 0;

	coordenadaspos = convertirpixelscoordenadas(x, y);
	if (Mundo::tablero.MatrizPuntero[coordenadaspos.x - 1][coordenadaspos.y - 1] != 0) {
		cout << "La pieza que quieres mover es un " << Mundo::tablero.MatrizPuntero[coordenadaspos.x - 1][coordenadaspos.y - 1]->nombre << endl;
	}

	return coordenadaspos;
}
void Mundo::MoverPieza(Vector posicionPieza, int x, int y) {
	Vector coordenadas;
	coordenadas.x = 0;
	coordenadas.y = 0;
	coordenadas = convertirpixelscoordenadas(x, y);

	
	if (Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1] != 0) {


		if (strcmp((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]->nombre), "Caballo") == 0) {
			cout << "Indique las coordenadas a las que quiere mover el caballo:" << endl;
			(Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1])->moverPieza(coordenadas.x, coordenadas.y);

		}
		else if (strcmp((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]->nombre), "Alfil") == 0) {
			cout << "Indique las coordenadas a las que quiere mover el alfil:" << endl;
			((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]))->moverPieza(coordenadas.x, coordenadas.y);
		}
		else if (strcmp((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]->nombre), "Torre") == 0) {
			cout << "Indique las coordenadas a las que quiere mover la torre:" << endl;
			((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]))->moverPieza(coordenadas.x, coordenadas.y);
		}
		else if (strcmp((tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]->nombre), "Peon") == 0) {
			cout << "Indique las coordenadas a las que quiere mover el peon:" << endl;

			((tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]))->moverPieza(coordenadas.x, coordenadas.y);
		}
		else if (strcmp((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]->nombre), "Dama") == 0) {
			cout << "Indique las coordenadas a las que quiere mover la dama:" << endl;
			((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]))->moverPieza(coordenadas.x, coordenadas.y);
		}
		
		else if (strcmp((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]->nombre), "Rey") == 0) {
			cout << "Indique las coordenadas a las que quiere mover el rey:" << endl;
			if (((Mundo::tablero.MatrizPuntero[posicionPieza.x - 1][posicionPieza.y - 1]))->moverPieza(coordenadas.x, coordenadas.y) != 1) {
				Mundo::Enroque(coordenadas.x, coordenadas.y);
			}
		}
	}
	cout<<"\n";
	
	for (int j = 7; j > -1; j--) {
		cout<<"\n";
		for (int i = 0; i < 8; i++) {
			cout<< ("%d\t", Mundo::tablero.posiciones[i][j]);
		}
	}
	
	cout<<"\n";
	
}
Vector Mundo::convertirpixelscoordenadas(int xpixel, int ypixel) {
	Vector coordenadas;
	coordenadas.x = 0;
	coordenadas.y = 0;
	//CON LA PANTALLA DE LA SALA DE OREDENADORES
	//Anchura de x=65.25
	//Anchura de y=92.37

	/*
	for (int i = 0;i < 8;i++) {
	if ((220 +i*62< xpixel) && (xpixel < 220+62+i*62)) {
	coordenadas.x = i+1;
	}

	if ((875-92*i > ypixel) && (ypixel > 875-92-92*i)) {
	coordenadas.y = i+1;
	}
	}
	return coordenadas;
	*/
	//CON LAS COORDENADAS DE MI PORTATIL
	//ANCHURA DE X=52.375
	//ANCHURA DE Y=76

	for (int i = 0; i < 8; i++) {
		if ((173 + i * 52< xpixel) && (xpixel < 173 + 52 + i * 52)) {
			coordenadas.x = i + 1;
		}

		if ((721 - 76 * i > ypixel) && (ypixel > 721 - 76 - 76 * i)) {
			coordenadas.y = i + 1;
		}
	}
	return coordenadas;
}



