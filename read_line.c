/* read_line.c */
#include "main.h"

/**
 * read_line is function to read a line of input from the user
 * @line
 * Return: read line
 */
char* read_line()
{
    char* line = malloc(MAX_LINE);
    
    fgets(line, MAX_LINE, stdin);
    return line;
}
