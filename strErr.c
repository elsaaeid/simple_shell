#include "main.h"

/**
 *_errPuts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _errPuts(char *str)
{
	if (!str)
		return;
	for (int i = 0; str[i] != '\0'; i++)
	{
		_errPutChar(str[i]);
	}
}

/**
 * _errPutChar - writes the character ch to stderr
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _errPutChar(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 * _putFileDesc - writes the character ch to given fileDesc
 * @ch: The character to print
 * @fileDesc: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putFileDesc(char ch, int fileDesc)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fileDesc, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 *_putsFileDesc - prints an input string
 * @str: the string to be printed
 * @fileDesc: the fileDescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsFileDesc(char *str, int fileDesc)
{
	int i = 0;

	if (!str)
		return (0);
		do {
			i += _putFileDesc(*str++, fileDesc);
		} while (*str);
	return (i);
}
