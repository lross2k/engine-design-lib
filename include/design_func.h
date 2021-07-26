#ifndef DESIGN_FUNC_H
#define DESIGN_FUNC_H

#include <math.h>

#include "design_constants.h"
#include "engine.h"
#include "DLLDefines.h"

// Function prototypes
float APPLIB_EXPORT volumen_camara();
float APPLIB_EXPORT calc_escape_vel();
float APPLIB_EXPORT area_interna();
float APPLIB_EXPORT fuerza_maxima();
float APPLIB_EXPORT fuerza_tornillo();
float APPLIB_EXPORT tension();
float APPLIB_EXPORT margen_de_seguridad();
float APPLIB_EXPORT area_de_cortante();
float APPLIB_EXPORT cortante_promedio();
float APPLIB_EXPORT margen_de_seguridad_cortante();
float APPLIB_EXPORT aplastamiento();
float APPLIB_EXPORT margen_de_seguridad_aplaztamiento();

#endif //DESIGN_FUNC_H
