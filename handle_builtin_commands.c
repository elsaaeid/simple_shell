/* handle_builtin_commands.c */
#include "main.h"

/**
 * Function to handle built-in commands
 *
 * Return: 0 on success
 */


int handle_builtin_commands(char** args) {
    if (strcmp(args[0], "exit") == 0) {
        return 0;
    }
    return 1;
}
