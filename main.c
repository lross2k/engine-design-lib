#include <string.h>

// Header for all the library functions
#include "TSEL.h"

// Debugging example to test functions and print them out
void debug()
{
    printf("Inicializando structs\n");
    screws_t created_screw = {
        .diameter = 0.007466f,
        .n_screws = 6,
        .material = "Acero"
    };
    tubing_t* created_tube = tubing_init(
        "Aluminio 6061-T6",
        0.073f,
        0.0052f,
        68900000000.0f,
        275000000.0f,
        -1,
        310000000,
        205000000
    );
	engine_t* testing_engine = engine_init(
        800,
        1710,
        4,
        0.01f,
        0.0304f,
        0.1f,
        0.001f,
        created_tube,
        &created_screw
    );
	printf("La presion del motor debug es %f psi\n",get_pressure(testing_engine));
	printf("La velocidad de escape es %f antes de ser calculada\n", get_escape_vel(testing_engine));
	set_escape_vel(testing_engine);
	printf("La velocidad de escape es %f luego de usar la funcion calc_escape_vel()\n", get_escape_vel(testing_engine));
}

// Para hacer pruebas de la lib se tiene la aplicacion de CLI basica
int main(int argc, char *argv[])
{
	printf("* * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("*            TECSpace Engine Lib              *\n");
	printf("*            v 0.0.1d                         *\n");
	//printf("*                                             *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	if (argc <= 1)
	{
		printf("Usage: -f <enginefile> [options]\n");
		printf("Check help with: --help or -h\n");
	}
	else
	{
		int i;
		for (i = 1; i < argc; i++) {
			printf("Parameter %s\n", argv[i]);
			if (strncmp(argv[i],"-f",2) == 0) {
				if (i+1 < argc) {
					//-f toma el siguiente argumento
					if (strncmp(argv[i+1],"debug",6) == 0) {
						printf("\'-f debug\' showing the debugging example\n");
						debug();
					}
					else {
						printf("%s is not a valid file for -f\nRead --help\n", argv[i+1]);
					}
					i++;
				}
				else
				{
					printf("Missing arguments\n");
				}
			}
			else if (strncmp(argv[i],"--help",7) == 0 || strncmp(argv[i],"-h",3) == 0) {
				printf("This app hasn't been released yet, expect bugs\n\n");
				printf("--help (-h)\nShows this message\n\n");
				printf("-f <enginefile> [options]\nSelects the engine file to read and searches for options\n"
					"options should be given as [opt1,opt2,opt3] with no spaces\n"
					"there aren\'t avaliable options yet\n");
			}
			else
			{
				printf("Unknown parameter %s\n", argv[i]);
			}
			printf("\n");
		}
	}
	return(0);
}
