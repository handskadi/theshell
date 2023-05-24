#include "main.h"

/**
 * my_fork - My custom foking method
 * description: Forking and checking if -1
 * @av: av
 * @env: env
 * @cmd: command
 * @argv: vector
 */
void my_fork(char **av, char **env, char *cmd, char **argv)
{
	int wait_status;
	pid_t pid = fork();

	if (pid < 0)
	{
		free(cmd);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		(void)env;
		(void)av;
		execute_command(argv);
	}
	else
	{
		wait(&wait_status);
	}
}
