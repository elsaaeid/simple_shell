#include "main.h"


/**
 * renumberHistory - renumbers the history linked list after changes
 * @stream: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histCount
 */
int renumberHistory(stream_t *stream)
{
	list_t *node = stream->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (stream->histCount = i);
}
