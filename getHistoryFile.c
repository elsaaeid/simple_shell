#include "main.h"

/**
 * getHistoryFile - gets the history file
 * @stream: parameter struct
 *
 * Return: allocated string
 */

char *getHistoryFile(stream_t *stream)
{
	char *buf, *dir;

	dir = getEnv(stream, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strLength(dir) + _strLength(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strCopy(buf, dir);
	_strConcatenation(buf, "/");
	_strConcatenation(buf, HIST_FILE);
	return (buf);
}
