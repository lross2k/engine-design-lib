#include "design_func.h"
// Hoja de Excel: Diseño

// Variable declaration
motor_t motor_activo = {
	.presion = 800,	// psi
	.escape_vel = 0
};

// Constants

// E9 PRESION_ATMOSFERICA
// E26 TEMPERATURA_CAMARA
// E46 'Heat Capacity ratio' HEAT_CAPACITY_RATIO
// E47 CONSTANTE_GASES
// E54 PRESION_ATMOSFERICA

// Functions

// E25 get_presion_pa(motor_t *motor)
// E49 Volumen especifico camara
float volumen_camara()
{
	return TEMPERATURA_CAMARA*CONSTANTE_GASES/get_presion_pa(&motor_activo);
}
// E62 Velocidad de escape
float calc_escape_vel()
{	
	float k = HEAT_CAPACITY_RATIO;
	return sqrt(2*k/(k-1)*CONSTANTE_GASES*TEMPERATURA_CAMARA*
	(1-pow((PRESION_ATMOSFERICA/get_presion_pa(&motor_activo)),((k-1)/k))));
}
