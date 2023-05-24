#include "main.h"
#define MAX_CMD 15

/**
 * shell_p - Prompt
 * Description: my shell will go on infinite loop to show always prompt to user
 * @av: command passed by user
 * @env: Enviroment Variable
 * Return: 0 Always success
 */

void shell_p(char **av, char **env)
{
	char *cmd = NULL, *delimiter = " ", *argv[MAX_CMD];
	size_t n = 25;
	int cmd_index, strtok_index;
	ssize_t cmd_char_num;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			__print("#cisfun$ ");

		cmd = malloc(sizeof(char) * n);
		cmd_char_num = getline(&cmd, &n, stdin);
		_getline_err(cmd_char_num, cmd);
		cmd_index = 0;
		while (cmd[cmd_index])
		{
			if (cmd[cmd_index] == '\n')
				cmd[cmd_index] = 0;

			cmd_index++;
		}
		strtok_index = 0;
		argv[strtok_index] = strtok(cmd, delimiter);
		while (argv[strtok_index] != NULL)
		{
			argv[++strtok_index] = strtok(NULL, delimiter);
		}

		if (string_compare(argv[0], "exit") == 0)
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (string_compare(argv[0], "env") == 0)
			env_print();

		my_fork(av, env, cmd, argv);
	}
}
