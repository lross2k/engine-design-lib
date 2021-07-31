#include "design_func.h"
/*Hoja de Excel: Diseño*/

/*Constants*/
// E9 PRESION_ATMOSFERICA
// E26 TEMPERATURA_CAMARA
// E46 'Heat Capacity ratio' HEAT_CAPACITY_RATIO
// E47 CONSTANTE_GASES
// E54 PRESION_ATMOSFERICA
// E162 DIAMETRO_NUCLEO

/*Functions*/
// E25 get_pressure_pa(engine_t *engine)
float get_pressure_pa(engine_t* engine)
{
	return(tsel_psi_to_pa(engine->pressure));
}
// E49 Volumen especifico camara
float volumen_camara(engine_t *engine)
{
	return(TEMPERATURA_CAMARA*CONSTANTE_GASES/get_pressure_pa(engine));
}
// E62 Velocidad de escape
float calc_escape_vel(engine_t* engine)
{	
	float calc_pow = powf((PRESION_ATMOSFERICA / get_pressure_pa(engine)), ((HEAT_CAPACITY_RATIO - 1.0f) / HEAT_CAPACITY_RATIO));
	return(sqrtf(2.0f * HEAT_CAPACITY_RATIO /(HEAT_CAPACITY_RATIO -1.0f) * CONSTANTE_GASES * TEMPERATURA_CAMARA * (1.0f - calc_pow)));
	//powf es para double, analizar posible cambio de type en todo
}
/* Determinacion de fuerza sobre tapas*/
// E140 Area interna
float temp_E15 = 1;	// Dependencia E15
float area_interna()
{
	return(PI*powf(temp_E15,2));	//powf es para double, analizar posible cambio de type en todo
}
// E141 Fuerza maxima
float temp_E118 = 1;	// Dependencia E118
float fuerza_maxima()
{
	return(temp_E118*area_interna()); 
}
// E142 Fuerza por tornillo
float temp_E130 = 1;	// Dependencia E130
float fuerza_tornillo()
{
	return(fuerza_maxima()/temp_E130);
}
/*Esfuerzo circunferencial*/
// E144 Tension
float temp_E137 = 1;	// Dependencia E137
float tension()
{
	return(fuerza_maxima()/temp_E137);
}
// E145 Margen de seguridad
float temp_E20 = 1;	// Dependencia E20
float margen_de_seguridad()
{
	return(temp_E20/tension());
}
/*Esfuerzo longitudinal*/
// E146 Area de cortante
float temp_E14 = 1;	// Dependencia E14
float temp_E138 = 1;	// Dependencia E138
float area_de_cortante()
{
	return(temp_E138*temp_E14);
}
// E147 Cortante promedio
float cortante_promedio()
{
	return(fuerza_tornillo()/area_de_cortante());
}
// E148 Margen de seguridad cortante
float temp_E21 = 1;	// Dependencia E21
float margen_de_seguridad_cortante()
{
	return(temp_E21/cortante_promedio());
}
/*Esfuerzo de aplastamiento*/
// E149 Aplastamiento
float temp_E135 = 1;	// Dependencia E135
float aplastamiento()
{
	return(fuerza_tornillo()/temp_E135);
}
// E150 Margen de seguridad aplaztamiento
float margen_de_seguridad_aplaztamiento()
{
	return(temp_E20/aplastamiento());
}
/*Deformacion circunferencial*/
// E152 Deformacion unitaria
float temp_E18 = 1;	// Dependencia E18
float temp_E121 = 1;	// Dependencia E121
float deformacion_unitaria()
{
	return(temp_E121/temp_E18);
}
// E153 Circunferencia interna total
//float temp_E15 = 1;	// Dependencia E15
float circunferencia_interna_total()
{
	return(2*PI*temp_E15);
}
// E154 Deformacion de la circunferencia interna
float deformacion_circunferencia_interna()
{
	return(deformacion_unitaria()*circunferencia_interna_total()*1000);
}
// E155 Circunferencia externa inicial
float temp_E13 = 1;	// Dependencia E13
float circunferencia_externa_inicial()
{
	return(PI*temp_E13);
}
// E156 Deformacion de circunferencia externa
float deformacion_circunferencia_externa()
{
	return(circunferencia_externa_inicial()*deformacion_unitaria()*1000);
}
// E157 Radio interno final
// radio_final(circunferencia_interna_total(),deformacion_circunferencia_interna());
float radio_final(float circ_total,float deform_circ)
{
	return(circ_total*(deform_circ/1000)/(2*PI));
}
// E158 Diferencia de radio interno
//float temp_E15 = 1;	// Dependencia E15
float diferencia_radio_interno()
{
	return(radio_final(circunferencia_interna_total(),deformacion_circunferencia_interna())-temp_E15*1000);
}
// E159 es la misma ecuacion de E157
// radio_final(circunferencia_interna_inicial(),deformacion_circunferencia_externa());
// E160 Diferencia radio externo
//float temp_E13 = 1;	// Dependencia E13
float diferencia_radio_externo()
{
	return((radio_final(circunferencia_externa_inicial(),deformacion_circunferencia_externa())-(temp_E13/2))*1000);
}

/*Resistencia de tornillos*/

/*Ecuacion de Barlow*/

/*Longitud maxima de Tornillo*/

/*O-ring's*/

/*Informacion*/

