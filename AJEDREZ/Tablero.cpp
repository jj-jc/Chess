#include "Tablero.h"
Tablero::Tablero(){

	//BLANCAS
	Alfil alfilB1(3, 1), alfilB2(6, 1);
	Caballo caballoB1(2, 1), caballoB2(7,1);
	Dama damaB(4, 1);
	Rey reyB(5, 1);
	Torre torreB1(1, 1), torreB2(8, 1);
	Peon peonB1(1, 2), peonB2(2, 2), peonB3(3, 2), peonB4(4, 2), peonB5(5, 2), peonB6(6, 2), peonB7(7, 2), peonB8(8, 2);
	
	//NEGRAS
	Alfil alfilN1(3, 8), alfilN2(6, 8);
	Caballo caballoN1(2, 8), caballoN2(7, 8);
	Dama damaN(4, 8);
	Rey reyN(5, 8);
	Torre torreN1(1, 8), torreN2(8, 8);
	Peon peonN1(1, 7), peonN2(2, 7), peonN3(3, 7), peonN4(4, 7), peonN5(5, 7), peonN6(6, 7), peonN7(7, 7), peonN8(8, 7);
		
}