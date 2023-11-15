/* is_builtin_command.c */
#include "main.h"

/**
 * is_builtin_command is function to compare command
 * @command
 * Return: 0 or 1
 */
int is_builtin_command(char* command)
{
    if (strcmp(command, "exit") == 0 || strcmp(command, "cd") == 0)
    {
        return 1;
    }
    return 0;
}
