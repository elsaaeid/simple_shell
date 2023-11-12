#include "main.h"

/**
 * readHistory - reads history from file
 * @stream: the parameter struct
 *
 * Return: histCount on success, 0 otherwise
 */
int readHistory(stream_t *stream)
{
	int i, last = 0, lineCount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = getHistoryFile(stream);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			buildHistoryList(stream, buf + last, lineCount++);
			last = i + 1;
		}
	if (last != i)
		buildHistoryList(stream, buf + last, lineCount++);
	free(buf);
	stream->histCount = lineCount;
	while (stream->histCount-- >= HIST_MAX)
		deleteNodeAtIndex(&(stream->history), 0);
	renumberHistory(stream);
	return (stream->histCount);
}
