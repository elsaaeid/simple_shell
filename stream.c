#include "main.h"

/**
 * clearStream - initializes info_t struct
 * @stream: struct address
 */
void clearStream(stream_t *stream)
{
	stream->arg = NULL;
	stream->argv = NULL;
	stream->path = NULL;
	stream->argc = 0;
}

/**
 * setStream - initializes stream_t struct
 * @stream: struct address
 * @av: argument vector
 */
void setStream(stream_t *stream, char **av)
{
	int i = 0;

	stream->fname = av[0];
	if (stream->arg)
	{
		stream->argv = strtokFunc1(stream->arg, " \t");
		if (!stream->argv)
		{

			stream->argv = malloc(sizeof(char *) * 2);
			if (stream->argv)
			{
				stream->argv[0] = _strDuplication(stream->arg);
				stream->argv[1] = NULL;
			}
		}
		for (i = 0; stream->argv && stream->argv[i]; i++)
			;
		stream->argc = i;

		replaceAlias(stream);
		replaceVars(stream);
	}
}

/**
 * freeStream - frees stream_t struct fields
 * @stream: struct address
 * @all: true if freeing all fields
 */
void freeStream(stream_t *stream, int all)
{
	ffree(stream->argv);
	stream->argv = NULL;
	stream->path = NULL;
	if (all)
	{
		if (!stream->cmd_buf)
			free(stream->arg);
		if (stream->env)
			freeList(&(stream->env));
		if (stream->history)
			freeList(&(stream->history));
		if (stream->alias)
			freeList(&(stream->alias));
		ffree(stream->environ);
			stream->environ = NULL;
		bfree((void **)stream->cmd_buf);
		if (stream->readfd > 2)
			close(stream->readfd);
		_putChar(BUF_FLUSH);
	}
}
