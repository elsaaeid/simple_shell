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
    int status;

    do
    {
        printf("> ");
        line = read_line();
        args = parse_line(line);
        execute(args);

        free(line);
        free_tokens(args);
    }
    while (status);

    return 0;
}
