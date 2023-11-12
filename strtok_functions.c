#include "main.h"

/**
 * **strtokFunc1 - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @delimeter: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtokFunc1(char *str, char *delimeter)
{
	int i, j, k, m, inputData = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delimeter)
		delimeter = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!isDelimeter(str[i], delimeter) && (isDelimeter(str[i + 1], delimeter) || !str[i + 1]))
			inputData++;

	if (inputData == 0)
		return (NULL);
	s = malloc((1 + inputData) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < inputData; j++)
	{
		while (isDelimeter(str[i], delimeter))
			i++;
		k = 0;
		while (!isDelimeter(str[i + k], delimeter) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtokFunc2 - splits a string into words
 * @str: the input string
 * @delimeter: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtokFunc2(char *str, char delimeter)
{
	int i, j, k, m, inputData = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delimeter && str[i + 1] == delimeter) ||
		    (str[i] != delimeter && !str[i + 1]) || str[i + 1] == delimeter)
			inputData++;
	if (inputData == 0)
		return (NULL);
	s = malloc((1 + inputData) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < inputData; j++)
	{
		while (str[i] == delimeter && str[i] != delimeter)
			i++;
		k = 0;
		while (str[i + k] != delimeter && str[i + k] && str[i + k] != delimeter)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
