/* execute_builtin_command.c */
#include "main.h"

/**
 * execute_builtin_command - function to execute a command of builtin
 * @arguments: it is args which pointer for directory
 * Return: pointer of args
 */

void execute_builtin_command(char **arguments)
{
	if (strcmp(arguments[0], "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(arguments[0], "cd") == 0)
	{
		if (arguments[1] == NULL)
		{
			fprintf(stderr, "cd: missing argument\n");
		}
		else
		{
			if (chdir(arguments[1]) != 0)
			{
				fprintf(stderr, "cd: failed to change directory\n");
			}
		}
	}
}
