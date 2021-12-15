/// Pojmenování jednotlivých pinů pro arduino uno
#ifndef BUS_PINS_UNO_H
#define BUS_PINS_UNO_H

// Patice DIGITAL, piny DX, X - čísla napsaná na desce 
namespace BusDigital8Pin{
	const int D00 = 0; 
	const int D01 = 1; 
	const int D02 = 2; 
	const int D03 = 3; 
	const int D04 = 4; 
	const int D05 = 5; 
	const int D06 = 6; 
	const int D07 = 7; 
};

// Patice DIGITAL, piny DX, X - čísla napsaná na desce 
namespace BusDigital10Pin{
	// jako GPIO lze uzit pouze 6 pinu
	const int D08 = 8; 
	const int D09 = 9; 
	const int D10 = 10; 
	const int D11 = 11; 
	const int D12 = 12; 
	const int D13 = 13; 
};

// Patice ANALOG, nazvy tak jak jsou na desce 
namespace BusAnalog{
	const int A0 = 14; 
	const int A1 = 15; 
	const int A2 = 16; 
	const int A3 = 17; 
	const int A4 = 18; 
	const int A5 = 19; 
};

#endif

