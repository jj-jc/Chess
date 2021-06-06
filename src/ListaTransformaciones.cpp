#include "ListaTransformaciones.h"




ListaTransformaciones::ListaTransformaciones():num(0)
{
	for (int i = 0; i < MAX; i++) 
		transformaciones[i] = 0;
}


ListaTransformaciones::~ListaTransformaciones()
{
}
bool ListaTransformaciones::operator += (Pieza *mipieza) {
	if (num < MAX) {
		transformaciones[num++] = mipieza;
		return true;
	}
	return false;
}