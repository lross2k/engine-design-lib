#include <design_resist.h>

/*****
Implementacion original por Kevin, en Python
Inicio de traduccion a C por lross2k
******/

// Variables necesarias de partes anteriores
//float temp_E13 = 0.0730f;
//float temp_E14 = 0.0052f;
//float temp_E15 = 0.0314f;

// Resistencia de materiales E115
void tsel_mean_tubing_diameter(engine_t *engine, float temp_E13, float temp_E14)
{
    engine->used_tube->mean_tubing_diameter = temp_E13-temp_E14;
}
// condición de espesor del tubo E116
void tsel_width_condition(engine_t *engine, float temp_E14)
{
    engine->width_condition = engine->used_tube->mean_tubing_diameter/temp_E14;
}
// Presión maxima E118
void tsel_engine_max_pressure(engine_t *engine)
{
    // TODO: max_pressure = get_max(float *sim_data, int n_sim_data)
    engine->max_pressure = 5.95f*pow(10,6); // Pascal
    //engine.max_pressure = 5.95*e**6 # Pascales (Obtenido de simulación)
    //engine.pmax = 863.01 #PSI
}

/* Esfuerzo por presión */
// Esfuezo Tangencial E121
void tsel_tangencial_stress(engine_t *engine, float temp_E13, float temp_E14)
{
    // TODO: implement into engine
    // could be done branchless
    if (engine->width_condition> 20)
    {
        engine->tangencial_stress = engine->max_pressure*engine->used_tube->internal_radius/temp_E14;
    }
    else
    {
        engine->tangencial_stress = engine->max_pressure*(pow((temp_E13/2),2)+pow(engine->used_tube->internal_radius,2))/(pow(temp_E13/2,2)-pow(engine->used_tube->internal_radius,2));
    }
}
// Esfuerzo Longitudinal E122
void tsel_logitudinal_stress(engine_t *engine, float temp_E13, float temp_E14)
{
    if (engine->width_condition > 20)
    {
        engine->longitudinal_stress = engine->max_pressure*engine->used_tube->internal_radius/2*temp_E14;
    }
    else
    {
        engine->longitudinal_stress = engine->max_pressure*pow(engine->used_tube->internal_radius,2)/(pow(temp_E13,2)-pow(engine->used_tube->internal_radius,2));
    }
}
// Esfuerzo Radial E123
void tsel_radial_stress(engine_t *engine)
{
    if (engine->width_condition > 20)
    {
        engine->radial_stress = 0;
    }
    else
    {            
        engine->radial_stress = -engine->max_pressure;
    }
}
// Esfuerzo Maximo E125
void tsel_max_stress(engine_t *engine)
{
    if (engine->tangencial_stress > engine->radial_stress)
    {
        engine->max_stress = engine->tangencial_stress;
    }
    else
    {
        engine->max_stress = engine->radial_stress;
    }
}
// Margen de Seguridad E127
void tsel_margin_of_safety(engine_t *engine, float temp_E20)
{
    engine->margin_of_safety = temp_E20/engine->max_stress;
}

/* Determinación de Areas afectadas por tornillos */

// engine_t has screws_t *used_screws to initialize at allocation
//engine->used_screws->n_screws = 6;
//engine->used_screws->diameter = 0.009f;
//engine->used_screws->dist_center_wall = 0.01f;

// Area_Transversal_tubo E133
// engine_t has tubing_t *used_tube
void tsel_transversal_area_tube(engine_t *engine, float temp_E13)
{
    engine->used_tube->transversal_area = (float)PI*(pow(temp_E13/2,2)-pow(engine->used_tube->internal_radius,2));
}
// Angulo de sector circular E134
void tsel_ang_circular_sector(engine_t *engine)
{
    engine->used_tube->sector_angle = (float)(180/PI)*asin((engine->used_screws->diameter/2)/engine->used_tube->internal_radius);
}
// Area transversal de 1 tornillo E135
void tsel_area_per_screw(engine_t *engine, float temp_E13, float temp_E14)
{
    engine->used_screws->area_per_screw = (float)(engine->used_tube->sector_angle/2)*(pow(temp_E13/2,2)-pow(engine->used_tube->internal_radius,2)-pow(temp_E14,2));
}
// Area transversal ocupada por los tornillos E136
void tsel_screw_occupied_area(engine_t *engine)
{
    engine->used_screws->screw_occupied_area = engine->used_screws->area_per_screw*engine->used_screws->n_screws;
}
// Area de material E137
void tsel_tube_mateial_area(engine_t *engine)
{
    engine->used_tube->material_area = engine->used_tube->transversal_area-engine->used_screws->screw_occupied_area;
}
// Espesor del segmento cortante E138
void tsel_width_cutting_segment(engine_t *engine)
{
    engine->used_screws->width_cutting_segment = engine->used_screws->dist_center_wall-(engine->used_screws->diameter/2);
}
