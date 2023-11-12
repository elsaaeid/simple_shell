#include "main.h"

/**
 * _strLength - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int _strLength(char *str)
{
	if (!str)
		return (0);
    for(int i = 0; *str++; i++)
	return (i);
}
