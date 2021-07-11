#include "engine.h"

// Initializes all the variables in the tube struct
tubing_t* tubing_init(
    char *material,
    float diameter,
    float thickness,
    float young_module,
    float shear_tension,
    float shear_pressure,
    float ult_tension,
    float ult_pressure
)
{
    tubing_t *tube = malloc(sizeof(*tube));
    if (!tube) {
        printf("malloc failed\n");
        exit(1);
    }
    tube->material = material;
    tube->diameter_ext = diameter;
    tube->wall_thickness = thickness;
    tube->young_module = young_module;
    tube->shear_stress_tension = shear_tension;
    tube->shear_stress_pressure = shear_pressure;
    tube->ult_stress_tension = ult_tension;
    tube->ult_stress_pressure = ult_pressure;
    return(tube);
}

// Initializes all the variables in the engine struct
engine_t* engine_init(
    float pressure,
    float temperature,
    int n_grains,
    float internal_radius,
    float external_radius,
    float longitude,
    float separation,
    tubing_t *used_tube,
    screws_t *used_screws
)
{
    engine_t *engine = malloc(sizeof(*engine));
    if (!engine) {
        printf("malloc failed\n");
        exit(1);
    }
    engine->pressure = pressure;
    engine->temperature = temperature;
    engine->n_grains = n_grains;
    engine->internal_radius = internal_radius;
    engine->external_radius = external_radius;
    engine->longitude = longitude;
    engine->separation = separation;
    engine->used_tube = used_tube;
    engine->used_screws = used_screws;
    engine->escape_vel = 0;
	return(engine);
}

// 'Diseño'!E25 Retorna presion actual del motor en pascales
float get_pressure_pa(engine_t *self)
{
	return 6894.757f*(self->pressure);
}

float get_pressure(engine_t *self)
{
    return(self->pressure);
}

void set_pressure(engine_t *self, float pressure)
{
	self->pressure = pressure;
}

void set_escape_vel(engine_t *self)
{
     // Ejemplo usando funciones de design_func.c 
     self->escape_vel = calc_escape_vel(self);
}
float get_escape_vel(engine_t *self)
{
    return self->escape_vel;
}
