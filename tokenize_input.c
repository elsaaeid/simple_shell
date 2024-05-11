/* tokenize_input.c */
#include "main.h"

/**
 * tokenize_input - function to split a command
 * @command: pointer of command
 * @arguments: pointer args to loop on strings
 * Return: splited command
 */

void tokenize_input(char *command, char *arguments)
{
	char *token = strtok(command, " ");
	int num_arguments = 0;

	while (token != NULL && num_arguments < MAX_NUM_ARGUMENTS)
	{
		arguments[num_arguments] = token;
		num_arguments++;
		token = strtok(NULL, " ");
	}
	arguments[num_arguments] = NULL;
}
