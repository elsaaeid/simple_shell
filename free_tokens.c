/* free_tokens.c */
#include "main.h"

/**
 * free_tokens is function to reserve space for tokens
 * @tokens
 * Return: tokens
 */
void free_tokens(char** tokens)
{
    int i = 0;
    do 
    {
        free(tokens[i]);
        i++;
    } 
    while (tokens[i] != NULL);
    free(tokens);
}
