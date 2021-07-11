from design_func import PRESION_ATMOSFERICA, calc_escape_vel

def main():
    # Valores de referencia
    PRESION_ATMOSFERICA = 101325
    E25 = 5515805.60
    E26 = 1710
    E46 = 1.043
    E47 = 196.14

    print(calc_escape_vel(E46, E47, E26, PRESION_ATMOSFERICA, E25))
    
main()