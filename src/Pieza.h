#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include "glut.h"
#include "Vector.h"



class Pieza {
	//Atributos Comunes para todas las piezas, para que sea más robusto las pondremos como private
	Vector posicion;
	char nombre[10] = "Pieza";
	bool color = 1;  //todas blancas por defecto

public:
	Pieza() {}
	//Pieza(int x, int y) { posicion.x = x; posicion.y = y; }
	~Pieza();
	//metodos comunes
	void ImprimeNombre();
	virtual bool moverPieza(int x, int y) = 0;

	//métodos para los atributos
	
	void SetPos(int x, int y);
	Vector getPos() { return posicion; }
	void setNombre(char minombre[10]) { strcpy(nombre,minombre); }
	char *getNombre() { return nombre; }
	bool getColor() { return color; }
	void setColor(bool micolor) { color = micolor; }
	
	//Dibujar

	static void Base(int altura);
	static void Esfera(GLfloat radio);
	static void Cilindro(GLfloat radio, GLfloat altura);
	static void Disco(GLfloat radio);
	static void Box(GLfloat x, GLfloat y, GLfloat z);
	

};

	
