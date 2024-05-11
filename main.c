/* main.c */
#include "main.h"

/**
 * main - function of entry point
 * @arguments: pointer of array which points to commands
 * @command: array - points to max length
 * Return: 0 on success
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_NUM_ARGUMENTS];

	while (1)
	{
		read_command(command);
		tokenize_input(command, arguments);

		if (is_builtin_command(arguments[0]))
		{
			execute_builtin_command(arguments);
		}
		else
		{
			execute_command(arguments);
		}
	}
	return (0);
}
