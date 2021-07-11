#ifndef ENGINE_H
#define ENGINE_H

#include <stdlib.h>
#include <stdio.h>

#include "DLLDefines.h"
#include "design_func.h"

// Estructura para tuberia
typedef struct tubing
{
   char *material;
   float diameter_ext, wall_thickness;
   float young_module;
   float shear_stress_tension, shear_stress_pressure;
   float ult_stress_tension, ult_stress_pressure;
} APPLIB_EXPORT tubing_t;

// Estructura para tornillos
typedef struct screws
{
	float diameter;
	unsigned int n_screws;
	char  *material;
} APPLIB_EXPORT screws_t;

// Estructura del engine
typedef struct engine
{
	float pressure;         // chamber pressure in psi
	float escape_vel, temperature;
    // grains data
    int n_grains;
    float internal_radius, external_radius, longitude, separation;
    tubing_t *used_tube;    // ptr to intialized struct
	screws_t *used_screws;  // ptr to initialized struct
} APPLIB_EXPORT engine_t;

// Function prototypes
engine_t APPLIB_EXPORT *engine_init(
    float pressure,
    float temperature,
    int n_grains,
    float internal_radius,
    float external_radius,
    float longitude,
    float separation,
    tubing_t *used_tube,
    screws_t *used_screws
);
tubing_t APPLIB_EXPORT *tubing_init(
    char *material,
    float diameter,
    float thickness,
    float young_module,
    float shear_tension,
    float shear_pressure,
    float ult_tension,
    float ult_pressure
);
float APPLIB_EXPORT get_pressure_pa(engine_t *self);
void APPLIB_EXPORT set_pressure(engine_t *self, float pressure);
void APPLIB_EXPORT set_escape_vel(engine_t *self);
float APPLIB_EXPORT get_escape_vel(engine_t *self);
float APPLIB_EXPORT get_pressure(engine_t *self);

#endif // ENGINE_H
