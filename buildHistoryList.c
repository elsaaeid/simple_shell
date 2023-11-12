#include "main.h"


/**
 * buildHistoryList - adds entry to a history linked list
 * @stream: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @lineCount: the history line_count
 *
 * Return: Always 0
 */
int buildHistoryList(stream_t *stream, char *buf, int lineCount)
{
	list_t *node = NULL;

	if (stream->history)
		node = stream->history;
	addNodeEnd(&node, buf, lineCount);

	if (!stream->history)
		stream->history = node;
	return (0);
}
