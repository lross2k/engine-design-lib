#include "rendimientos.h"

//Otras variables adyacentes 
//E43
float br_combustion()
{
    return (float)(const_a_br * pow(press_Pa * fact_conv_br, const_n_br) * fact_conv_m_to_i);
}

//Combustible//

//E67 Volumen_Combustible
float volumen_combustible()
{
    return (float)(PI*Lg*cant_granos*(pow(re, 2)-pow(ri, 2)));
}

//E68 Masa_Combustible
float masa_combustible()
{
    return (volumen_combustible() * dens_comb);
}

//Combustión//

//E70 Tiempo de quemado total_Combustible
float Tiempo_quemado_combustion()
{
    return (re-ri)/br_combustion();
}

//E71 Área de quemado 
float Ab_combustion()
{
    return (prom_A_Quemado()*cant_granos);
}

//E72 Flujo másico
float mg_combustion()
{
    return Ab_combustion()*dens_comb*br_combustion();
}

//Fuerzas//

//E74 Empuje teórico
float emp_teo()
{
    return mg_combustion()*escape;
}

//E76 Empuje promedio esperado
float emp_prom(float list[])
{
    return empuje_prom_tiempo(list);
}

//E78 Empuje máximo esperado
float emp_max(float list[])
{
    float max = 0;
    for (int n = 0; n < sizeof(list); n++)
    {
        if (list[n] > max)
        {
            max = list[n];
        }
    }
    return max;
}

//Impulsos//

//E81 Impulso específico teórico
float I_sp_teo()
{
    return escape/g_terr;
}

//E82 Impulso específico esperado
float I_sp_esperado(float list[])
{
    return (float)(impulso_esp(list)/(masa_combustible()*g_terr));
}

//E83 Impulso total teórico
float I_tot_teo()
{
    return emp_teo()* Tiempo_quemado_combustion();
}

//E84 Impulso total esperado
float I_tot_esp(float list[])
{
    return impulso_tot(list);
}

//E85 Delta V esperado
float Delta_V_Esp(float list[])
{
    return delta_V(list);
}