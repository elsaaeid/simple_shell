/* free_tokens.c */
#include "main.h"

/**
 * free_tokens is function to reserve space for tokens
 * @tokens
 * Return: tokens
 */
void free_tokens(char** tokens)
{
    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}
