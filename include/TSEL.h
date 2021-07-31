#ifndef TSEL_H
#define TSEL_H

//#include "design_func.h"

// Types
typedef struct tubing tubing_t;
typedef struct screws screws_t;
typedef struct engine engine_t;

// Function prototypes
tubing_t * tsel_tubing_init(
    char* material,
    float diameter,
    float thickness,
    float young_module,
    float shear_tension,
    float shear_pressure,
    float ult_tension,
    float ult_pressure
);
screws_t * tsel_screws_init(
    char* material,
    unsigned int amount,
    float diameter,
    float dist_center_wall
);
engine_t * tsel_engine_init(
    float pressure,
    float temperature,
    int n_grains,
    float internal_radius,
    float external_radius,
    float longitude,
    float separation,
    tubing_t* used_tube,
    screws_t* used_screws
);
float tsel_psi_to_pa(float psi);
void tsel_set_pressure(engine_t* engine, float pressure);
void tsel_set_escape_vel(engine_t* engine, float vel);
float tsel_get_escape_vel(engine_t* engine);
float tsel_get_pressure(engine_t* engine);
float tsel_temper_garganta();
float br_combustion();

#endif //TSEL_H
