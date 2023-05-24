#include "main.h"

extern char **environ;

void env_print()
{
	char **ev =  environ;
	while (*ev != NULL)
	{
		printf("%s\n", *ev);
		ev++;
	}
}
