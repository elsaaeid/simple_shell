#include "main.h"


/**
 **_strChar - locates a character in a string
 *@str: the string to be parsed
 *@ch: the character to look for
 *Return: (str) a pointer to the memory area s
 */
char *_strChar(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
