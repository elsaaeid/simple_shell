/* main.c */
#include "main.h"

/**
 * Function of entry point
 *
 * Return: 0 on success
 */
int main() 
{
    char* line;
    char** args;

    do
    {
	int status;

        printf("> ");
        line = read_line();
        args = tokenize_input(line);
        execute_command(args);

        free(line);
        free_tokens(args);
    }
    while (status);

    return 0;
}
