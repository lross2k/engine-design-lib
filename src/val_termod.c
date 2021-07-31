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
    return vol_esp_cam_combustion() * (pow((HEAT_CAPACITY_RATIO + 1),(1 / HEAT_CAPACITY_RATIO - 1)));
}

// E51 Volumen Especifico Escape
float vol_esp_escape()
{
    return vol_esp_cam_combustion() * pow((press_Pa / PRESION_ATMOSFERICA), (1 / HEAT_CAPACITY_RATIO));
}

// Presiones

// E53 presion de garganta
float presion_garganta()
{
    return press_Pa * pow((vol_esp_cam_combustion() / vol_esp_garganta()), (HEAT_CAPACITY_RATIO));
}

// Temperaturas

// E56 temperatura de garganta
float temp_garganta()
{
    return TEMPERATURA_CAMARA * pow((vol_esp_cam_combustion() / vol_esp_garganta()),(HEAT_CAPACITY_RATIO - 1));
}


// E57 temperatura de escape
float presion_escape()
{
    return TEMPERATURA_CAMARA * (pow((PRESION_ATMOSFERICA / press_Pa),((HEAT_CAPACITY_RATIO - 1) / HEAT_CAPACITY_RATIO)));
}


// Velocidades

// E59 velocidad garganta
float velocidad_garganta()
{
    return pow(((2 * HEAT_CAPACITY_RATIO) / (HEAT_CAPACITY_RATIO + 1) * CONSTANTE_GASES * TEMPERATURA_CAMARA),(0.5));
}

// E60 Velocidad Sonica Local at
float vel_sonica_local_at()
{
    return pow((HEAT_CAPACITY_RATIO * CONSTANTE_GASES * presion_garganta()),(0.5));
}

// E61 Numero Mach Mt
float vel_numero_mach_mt()
{
    return velocidad_garganta() / vel_sonica_local_at();
}

// E62 Velocidad de Escape
float velocidad_escape()
{
    return pow(pow(((2 * HEAT_CAPACITY_RATIO) / (HEAT_CAPACITY_RATIO - 1) * CONSTANTE_GASES * TEMPERATURA_CAMARA * (1 - (PRESION_ATMOSFERICA / press_Pa))),
    ((HEAT_CAPACITY_RATIO - 1) / HEAT_CAPACITY_RATIO)), (0.5));
}

// E63 Velocidad Sonica Local a2
float vel_sonica_local_a2()
{
    return pow((HEAT_CAPACITY_RATIO * CONSTANTE_GASES * presion_escape()),(0.5)); 
}

// E64 Numero Mach M2
float vel_numero_mach_m2()

{
    return velocidad_escape() / vel_sonica_local_a2();
}

// E65 Velocidad de escape caracteristica
float vel_escape_caract()
{
    return pow(pow((CONSTANTE_GASES * TEMPERATURA_CAMARA) / (HEAT_CAPACITY_RATIO *(2 / (HEAT_CAPACITY_RATIO + 1))),((HEAT_CAPACITY_RATIO + 1) / (HEAT_CAPACITY_RATIO - 1))), (0.5));
}
