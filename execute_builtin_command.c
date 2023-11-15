/* execute_builtin_command.c */
#include "main.h"

/**
 * execute_builtin_command is function to execute a command of builtin
 * @arguments
 * Return: 0
 */
void execute_builtin_command(char** arguments)
{
    if (strcmp(arguments[0], "exit") == 0)
    {
        exit(0);
    } 
    else if
    (strcmp(arguments[0], "cd") == 0)
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
