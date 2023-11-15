/* tokenize_input.c */
#include "main.h"

/**
 * tokenize_input is function to tokenize the input command
 * @line
 * Return: token after spliting
 */
char** tokenize_input(char* line)
{
    char** tokens = malloc(MAX_ARGS * sizeof(char*));
    char* token;
    int i = 0;
    
    token = strtok(line, " \t\n");
    while (token != NULL)
    {
        tokens[i] = strdup(token);
        token = strtok(NULL, " \t\n");
        i++;
    }
    
    tokens[i] = NULL;
    return tokens;
}
