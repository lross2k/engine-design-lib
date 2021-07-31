#include "val_termod.h"

// Volumenes

// E49 Volumen Especifico Camara de Combustible
float vol_esp_cam_combustion()
{
    return (TEMPERATURA_CAMARA * CONSTANTE_GASES) / press_Pa;

}

// E50 Volumen Especifico de Garganta
float vol_esp_garganta()
{
    return vol_esp_cam_combustion() * (powf((HEAT_CAPACITY_RATIO + 1),(1 / HEAT_CAPACITY_RATIO - 1)));
}

// E51 Volumen Especifico Escape
float vol_esp_escape()
{
    return vol_esp_cam_combustion() * powf((press_Pa / PRESION_ATMOSFERICA), (1 / HEAT_CAPACITY_RATIO));
}

// Presiones

// E53 presion de garganta
float presion_garganta()
{
    return press_Pa * powf((vol_esp_cam_combustion() / vol_esp_garganta()), (HEAT_CAPACITY_RATIO));
}

// Temperaturas

// E56 temperatura de garganta
float tsel_temper_garganta()
{
    return TEMPERATURA_CAMARA * powf((vol_esp_cam_combustion() / vol_esp_garganta()),(HEAT_CAPACITY_RATIO - 1));
}


// E57 temperatura de escape
float presion_escape()
{
    return TEMPERATURA_CAMARA * (powf((PRESION_ATMOSFERICA / press_Pa),((HEAT_CAPACITY_RATIO - 1) / HEAT_CAPACITY_RATIO)));
}


// Velocidades

// E59 velocidad garganta
float velocidad_garganta()
{
    return powf(((2.0f * HEAT_CAPACITY_RATIO) / (HEAT_CAPACITY_RATIO + 1.0f) * CONSTANTE_GASES * TEMPERATURA_CAMARA),(0.5f));
}

// E60 Velocidad Sonica Local at
float vel_sonica_local_at()
{
    return powf((HEAT_CAPACITY_RATIO * CONSTANTE_GASES * presion_garganta()),(0.5));
}

// E61 Numero Mach Mt
float vel_numero_mach_mt()
{
    return velocidad_garganta() / vel_sonica_local_at();
}

// E62 Velocidad de Escape
float velocidad_escape()
{
    return powf(powf(((2 * HEAT_CAPACITY_RATIO) / (HEAT_CAPACITY_RATIO - 1) * CONSTANTE_GASES * TEMPERATURA_CAMARA * (1 - (PRESION_ATMOSFERICA / press_Pa))),
    ((HEAT_CAPACITY_RATIO - 1) / HEAT_CAPACITY_RATIO)), (0.5));
}

// E63 Velocidad Sonica Local a2
float vel_sonica_local_a2()
{
    return powf((HEAT_CAPACITY_RATIO * CONSTANTE_GASES * presion_escape()),(0.5)); 
}

// E64 Numero Mach M2
float vel_numero_mach_m2()

{
    return velocidad_escape() / vel_sonica_local_a2();
}

// E65 Velocidad de escape caracteristica
float vel_escape_caract()
{
    return powf(powf((CONSTANTE_GASES * TEMPERATURA_CAMARA) / (HEAT_CAPACITY_RATIO *(2 / (HEAT_CAPACITY_RATIO + 1))),((HEAT_CAPACITY_RATIO + 1) / (HEAT_CAPACITY_RATIO - 1))), (0.5));
}
