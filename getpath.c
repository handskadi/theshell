#include "main.h"

/**
 * get_path_var - this will get path variable
 * Description: this will get the path variable using **environ
 * @p_name: Path name like PATH,HOME Etc
 * Return: NULL
 */
char *get_path_var(const char *p_name)
{
	/*extern char **environ;*/
	int path_index;

	for (path_index = 0; environ[path_index] != NULL; path_index++)
	{
		char *eqSign = locate_char_str(environ[path_index], '=');
		size_t p_nameLength = eqSign - environ[path_index];

		if (string_compare_2(environ[path_index], p_name, p_nameLength) == 0)
		{
			return (eqSign + 1);
		}
	}
	return (NULL);
}

/**
 * get_path - get the variable path of sys
 * @cmd: content of the path to be tokenized
 * Return: file_path which is full path or NULL
 */
char *get_path(char *cmd)
{
	char *path, *path_cpy, *p_token, *full_path;
	int path_len, cmd_len;
	struct stat buffer;

	path = get_path_var("PATH");
	if (path)
	{
		path_cpy  = duplicate_string(path);
		cmd_len = string_length(cmd);
		p_token = strtok(path_cpy, ":");
		while (p_token != NULL)
		{
			path_len = string_length(p_token);
			full_path = malloc(cmd_len + path_len + 2);
			make_string_copy(full_path, p_token);
			string_cat(full_path, "/");
			string_cat(full_path, cmd);
			string_cat(full_path, "\0");

			if (stat(full_path, &buffer) == 0)
			{
				free(path_cpy);
				return (full_path);
			}
			else
			{
				free(full_path);
				p_token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}
		return (NULL);
	}
	return (NULL);
}

/**
 * execute_command - excute my commands
 * Description: this will excute the given commands
 * @argv: passed command
 */

void execute_command(char **argv)
{
	char *cmd = NULL;
	char *actual_cmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		actual_cmd = get_path(cmd);
		if (execve(actual_cmd, argv, NULL) == -1)
		{
			__print("./hsh: No such file or directory\n");
			/*perror("Oops!..");*/
		}
	}
}

