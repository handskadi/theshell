#include "main.h"

/**
 * _getline_err - Handle getline error
 * description: Handles error when it is -1
 * @cmd_char_num: number of comands' character
 * @cmd: command
 */

void _getline_err(ssize_t cmd_char_num, char *cmd)
{
	if (cmd_char_num == -1)
	{
		free(cmd);
		__print("\n");
		exit(EXIT_FAILURE);
	}
}

