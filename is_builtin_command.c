/* is_builtin_command.c */
#include "main.h"

/**
 * is_builtin_command - function to compare command
 * @command: pointer which points to command
 * Return: 0 or 1
 */
int is_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0 || strcmp(command, "cd") == 0)
	{
		return (1);
	}
	return (0);
}
