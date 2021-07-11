import math

# Hoja de Excel: Diseño

# Constantes
PRESION_ATMOSFERICA = 101325    # E9

# Calculos

# E25
E25 = 5515805.60        # No implementada

# E26
E26 = 1710              # No implementada

# E46
E46 = 1.043             # No implementada

# E47
E47 = 196.14            # No implementada

# E54
# Equivale a PRESION_ATMOSFERICA

# E62 'velocidad de escape'
#(((2*E46)/(E46-1))*E47*E26*(1-(E54/E25)^((E46-1)/(E46))))^(0.5)                # del Excel
#(2*E46/(E46-1)*E47*E26*(1-(PRESION_ATMOSFERICA/E25)**((E46-1)/E46)))**(0.5)    # equivalente en Python

#Posible funcion para mayor modularidad
def calc_escape_vel(k, R, T1, P2, P1):
    return math.sqrt(2*k/(k-1)*R*T1*(1-(P2/P1)**((k-1)/k)))

# Generar calculo, nombre nuevo propuesto: escape_vel
E62 = calc_escape_vel(E46, E47, E26, PRESION_ATMOSFERICA, E25)