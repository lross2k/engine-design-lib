#include "design_func.h"

int main(int argc, char *argv[])
{
	float prueba;
	const float E25 = 5515805.60, E46 = 1.043, E47 = 196.14;
	const int E26 = 1710;
	
	prueba = calc_escape_vel(E46, E47, E26, PRESION_ATMOSFERICA, E25);
	
	printf("%f",prueba);
	
	return 0;
}
