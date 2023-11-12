#include "main.h"

/**
 * _strCopy - copies a string
 * @dest: the destination
 * @src: the source
 * Return: pointer to destination
 */
char *_strCopy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
		do {
			dest[i] = src[i];
			i++;
		} while (src[i]);
	dest[i] = 0;
	return (dest);
}
