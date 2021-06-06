#include <stdio.h>
#include <string.h>

#include "design_func.h"

// Ejemplo de como funcionara o pruebas de la libreria en terminal
int main(int argc, char *argv[])
{
	motor_t example_engine = {
	.presion = 800,	// psi
	.escape_vel = 42
	};
	
	printf("Rocket engine lib v0.0.1\n");

	if (argc <= 1)
	{
		printf("debug usage: .\\cli_debug -f rocketfile [options]\n");
	}
	else{
		for (int i = 1; i < argc; i++)
		{
			// Just an example: -f rocket1 [apogee,top_speed]
			if (!strncmp(argv[i], "-e", 2))
			{
				int exists = !strncmp(argv[i+1], "example_engine", 1);
				if (exists)
				{
					printf("Using 'example_engine'\n"
					"Pressure in engine: %f Pa\n"
					"Escape velocity: %f\n",get_presion_pa(&example_engine),get_escape_vel(&example_engine));
				} else
				{
					printf("Engine '%s' doesn't exist in the database\n", argv[i+1]);
				}
				i++;
			}
			else if (!strncmp(argv[i], "-f", 2))
			{
				printf("There is no support for custom files like: %s.tsrocket\n", argv[i+1]);
				i++;
			}
			else if(!strncmp(argv[i], "[", 1))
			{
				printf("Options parameter has no handles yet\n"
				"Given options: %s\n", argv[i]);
			}
			else
			{
				printf("Unexpected parameter: %s\n", argv[i]);
			}
		}
	}
	
	return 0;
}
