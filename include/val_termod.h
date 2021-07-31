#ifndef VAL_TERMOD_FUNC_H
#define VAL_TERMOD_FUNC_H 

#include <math.h>

#include "DLLDefines.h"
#include "design_constants.h"

// Prototipos de funciones
float vol_esp_cam_combustion();
float vol_esp_garganta();
float vol_esp_escape();
float presion_garganta();
float presion_escape();	// TODO
float APPLIB_EXPORT tsel_temper_garganta();
float temper_escape();
float velocidad_garganta();
float vel_sonica_local_at();
float vel_numero_mach_mt();
float velocidad_escape();
float vel_sonica_local_a2();
float vel_numero_mach_m2();
float vel_escape_caract();

#endif // VAL_TERMOD_FUNC_H

