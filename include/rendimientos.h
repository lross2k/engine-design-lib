#ifndef RENDIMIENTOS
#define RENDIMIENTOS

#include <math.h>
#include "design_constants.h"
#include "comp_area.h"
#include "comp_tiempo.h"

// TODO: cambiar list[] por nombres mas descriptivos

//Constructores
float volumen_combustible();
float masa_combustible();
float Tiempo_quemado_combustion();
float Ab_combustion();
float br_combustion();
float mg_combustion();
float emp_teo();
float emp_prom(float list[]);
float emp_max(float list[]);
float I_sp_teo();
float I_sp_esperado(float list[]);
float I_tot_teo();
float I_tot_esp(float list[]);
float Delta_V_Esp(float list[]);


#endif // RENDIMIENTOS