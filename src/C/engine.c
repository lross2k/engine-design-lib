#include "engine.h"

// 'Diseño'!E25 Retorna presion actual del motor en pascales
float get_presion_pa(motor_t *self)
{
	return 6894.757*(self->presion);
}

void set_presion(motor_t *self, float presion)
{
    self->presion = presion;
}

float get_escape_vel(motor_t *self)
{
    return self->escape_vel;
}