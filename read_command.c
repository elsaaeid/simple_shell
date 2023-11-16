/* read_command.c */
#include "main.h"

/**
 * read_command - function to read a line of command from the user
 * @command: pointer which required to enter
 * Return: command pointer
 */

void read_command(char *command)
{
	printf("$");
	fgets(command, MAX_COMMAND_LENGTH, stdin);
	command[strcspn(command, "\n")] = '\0';
}
