/* tokenize_input.c */
#include "main.h"

/**
 * tokenize_input is function to execute a command
 * @command
 * @arguments
 * Return: 0 or 1
 */

void tokenize_input(char* command, char** arguments)
{
    char* token = strtok(command, " ");
    int i = 0;

    while (token != NULL)
    {
        arguments[i++] = token;
        token = strtok(NULL, " ");
    }

    arguments[i] = NULL;
}
