/* tokenize_input.c */
#include "main.h"

/**
 * tokenize_input - function to split to tokens
 * @command: command line pointer
 * @arguments: pointer of strings
 * Return: string tokens which splited
 */

void tokenize_input(char *command, char **arguments)
{
	char *token = strtok(command, " ");
	int i = 0;

	while (token != NULL)
	{
		arguments[i++] = token;
		token = strtok(NULL, " ");
	}
	arguments[i] = NULL;
}
