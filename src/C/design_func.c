#include "design_func.h"

// Hoja de Excel: Diseño

// Constantes
// E9 PRESION_ATMOSFERICA

// E25
float E25 = 5515805.60;        // No implementada

// E26
float E26 = 1710.0;              // No implementada

// E46
float E46 = 1.043;             // No implementada

// E47
float E47 = 196.14;            // No implementada

// E54
// Equivale a PRESION_ATMOSFERICA

// E62 'velocidad de escape'
//(((2*E46)/(E46-1))*E47*E26*(1-(E54/E25)^((E46-1)/(E46))))^(0.5)                 // Excel
//sqrt(2*E46/(E46-1)*E47*E26*(1-pow((PRESION_ATMOSFERICA/E25),((E46-1)/E46))))    // equivalente en C

// Posible funcion para mayor modularidad
float calc_escape_vel(float k, float R, float T1, float P2, float P1)
{	
	return sqrt(2*k/(k-1)*R*T1*(1-pow((P2/P1),((k-1)/k))));	
}

float E62 = 1572.242432; // Valor obtenido de calc_escape_vel