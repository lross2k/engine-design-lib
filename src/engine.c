#include "engine.h"

// Initializes all the variables in the tube struct
tubing_t* tsel_tubing_init(
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
        printf("Tubing initialization failed\n");
        exit(1);
    }
    tube->material                  = material;
    tube->diameter_ext              = diameter;
    tube->wall_thickness            = thickness;
    tube->young_module              = young_module;
    tube->shear_stress_tension      = shear_tension;
    tube->shear_stress_pressure     = shear_pressure;
    tube->ult_stress_tension        = ult_tension;
    tube->ult_stress_pressure       = ult_pressure;
    tube->mean_tubing_diameter      = 0.0f;
    tube->transversal_area          = 0.0f;
    tube->internal_radius           = (tube->diameter_ext-(2*tube->wall_thickness))/2; // temp_E15
    tube->sector_angle              = 0.0f;    // degrees
    tube->material_area             = 0.0f;
    return(tube);
}

// Initializes all the variables in the screws struct
screws_t* tsel_screws_init(
    char *material,
    unsigned int amount,
    float diameter,
    float dist_center_wall)
{
    screws_t *screws = malloc(sizeof(*screws));
    if (!screws) {
        printf("Screws initialization failed\n");
        exit(1);
    }
    screws->material = material;
    screws->diameter = diameter;
    screws->amount = amount;
    screws->dist_center_wall = dist_center_wall;
    screws->area_per_screw = 0.0f;
    screws->screw_occupied_area = 0.0f;
    screws->width_cutting_segment = 0.0f;
    return(screws);
}

// Initializes all the variables in the engine struct
engine_t* tsel_engine_init(
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
        printf("Engine initialization failed\n");
        exit(1);
    }
    engine->width_condition = 0.0f;
    engine->margin_of_safety = 0.0f;
    engine->max_stress = 0.0f;
    engine->radial_stress = 0.0f;
    engine->tangencial_stress = 0.0f;
    engine->longitudinal_stress = 0.0f;
    engine->max_pressure = 0.0f;
    engine->pressure = pressure;
    engine->temperature = temperature;
    engine->n_grains = n_grains;
    engine->internal_radius = internal_radius;
    engine->external_radius = external_radius;
    engine->longitude = longitude;
    engine->separation = separation;
    engine->used_tube = used_tube;
    engine->used_screws = used_screws;
    engine->escape_vel = calc_escape_vel(engine);
	return(engine);
}

// TODO: screws init funtion

// 'Diseño'!E25 Retorna presion actual del motor en pascales
float tsel_psi_to_pa(float psi)
{
	return 6894.757f*psi;
}

float tsel_get_pressure(engine_t *engine)
{
    return(engine->pressure);
}

void tsel_set_pressure(engine_t *engine, float pressure)
{
	engine->pressure = pressure;
}

void tsel_set_escape_vel(engine_t *engine, float vel)
{
     engine->escape_vel = vel;
}

float tsel_get_escape_vel(engine_t *engine)
{
    return engine->escape_vel;
}
