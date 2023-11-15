/* main.c */
#include "main.h"

/**
 * Function of entry point
 * @status
 * Return: 0 on success
 */
int main() 
{
    char* line;
    char** args;
    int status;

    do
    {
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
