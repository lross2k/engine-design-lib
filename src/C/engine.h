#ifndef ENGINE_H
#define ENGINE_H

// Estructura del motor
typedef struct engine
{
	float presion;  // psi
	float escape_vel;
} motor_t;

// Function prototypes
float get_presion_pa(motor_t *self);
void set_presion(motor_t *self, float presion);
float get_escape_vel(motor_t *self);

#endif // ENGINE_H
