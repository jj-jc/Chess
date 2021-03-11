#pragma once
#include "glut.h"
#include "Vector.h"

class Pieza {
	public:
	Pieza();
	~Pieza();
	void Morir();
	Vector getPos() { return posicion; }
	void setNombre();
	void SetPos(int x, int y);
	Vector Consultar_Posicion();
	Vector posicion;
	char nombre[10] = "Pieza";
	bool Color = 1;  //todas blancas por defecto

public:
	

	bool Consultar_Color();
	void ImprimeNombre();
	virtual bool moverPieza(int x, int y) = 0;





	//Dibujar
	static void Base(int altura);
	static void Esfera(GLfloat radio);
	static void Cilindro(GLfloat radio, GLfloat altura);
	static void Disco(GLfloat radio);
	static void Box(GLfloat x, GLfloat y, GLfloat z);
	

};

	
