/* main.c */
#include "main.h"

/**
 * Function of entry point
 * Return: 0 on success
 */
int main()
{
    char command[MAX_COMMAND_LENGTH];
    char* arguments[MAX_NUM_ARGUMENTS];

    while (1)
    {
        read_command(command);
        tokenize_input(command, arguments);

        if (is_builtin_command(arguments[0])) 
        {
            execute_builtin_command(arguments);
        }else 
        {
            execute_command(arguments);
        }
    }

    return 0;
}
