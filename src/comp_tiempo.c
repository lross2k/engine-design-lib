//Proms_Comportamiento_Tiempo//
#include "Rendimientos.h"

//Lista definida desde AB32:AB1149
float empuje_prom_tiempo(float list[])
{
    float prom_final = 0;
    int cont = 0;
    for (int n = 0; n < sizeof(list); n++)
    {
        if (list[n] > 0)
        {
            prom_final = prom_final + list[n];
            cont += 1;
        }
    }
    prom_final = prom_final / cont;
}

//E25
float impulso_tot(float list[])
{
    int IT = 0;
    for (int n = 0; n < sizeof(list); n++)
    {
        IT = IT + list[n];
    }
    return IT;
}

//E26
float impulso_esp(float list[])
{
    return impulso_tot(list) / (masa_combustible() * 9.81);
}

//AD3511
float delta_V(float list[])
{
    int DeltaV = 0;
    for (int n = 0; n < sizeof(list); n++)
    {
        DeltaV = DeltaV + list[n];
    }

    return DeltaV;
}