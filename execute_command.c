/* execute_command.c */
#include "main.h"

/**
 * execute_command - function to execute a command
 * @arguments: pointer which points to command
 * Return: pointer of args
 */

void execute_command(char **arguments)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		fprintf(stderr, "Fork failed\n");
		exit(1);
	}
	else if (pid == 0)
	{
		execvp(arguments[0], arguments);
		fprintf(stderr, "Command '%s' not found\n", arguments[0]);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
