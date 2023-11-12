#include "main.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg value
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{
	stream_t stream[] = { INFO_INIT };
	int fd = 2;
	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_errPuts(av[0]);
				_errPuts(": 0: Cant't be opened");
				_errPuts(av[1]);
				_errPutChar('\n');
				_errPutChar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		stream->readfd = fd;
	}
		populateEnvList(stream);
		raedHistory(stream);
		hsh(stream, av);
	return (EXIT_SUCCESS);
}
