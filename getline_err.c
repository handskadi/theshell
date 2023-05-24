#include "main.h"

/**
 *
 *
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

