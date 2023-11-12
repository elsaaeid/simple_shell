#include "main.h"

/**
 * isChain - test if current char in buffer is a chain delimeter
 * @stream: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */

int isChain(stream_t *stream, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		stream->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		stream->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		stream->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * checkChain - checks we should continue chaining based on last status
 * @stream: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void checkChain(stream_t *stream, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (stream->cmd_buf_type == CMD_AND)
	{
		if (stream->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (stream->cmd_buf_type == CMD_OR)
	{
		if (!stream->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}


/**
 * replaceAlias - replaces an aliases in the tokenized string
 * @stream: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replaceAlias(stream_t *stream)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = nodeStartsWith(stream->alias, stream->argv[0], '=');
		if (!node)
			return (0);
		free(stream->argv[0]);
		p = _strChar(node->str, '=');
		if (!p)
			return (0);
		p = _strDuplication(p + 1);
		if (!p)
			return (0);
		stream->argv[0] = p;
	}
	return (1);
}

/**
 * replaceVars - replaces vars in the tokenized string
 * @stream: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replaceVars(stream_t *stream)
{
	int i = 0;
	list_t *node;

	for (i = 0; stream->argv[i]; i++)
	{
		if (stream->argv[i][0] != '$' || !stream->argv[i][1])
			continue;

		if (!_strComparison(stream->argv[i], "$?"))
		{
			replaceString(&(stream->argv[i]),
				_strDuplication(convertNumber(stream->status, 10, 0)));
			continue;
		}
		if (!_strComparison(stream->argv[i], "$$"))
		{
			replaceString(&(stream->argv[i]),
				_strDuplication(convertNumber(getpid(), 10, 0)));
			continue;
		}
		node = nodeStartsWith(stream->env, &stream->argv[i][1], '=');
		if (node)
		{
			replaceString(&(stream->argv[i]),
				_strDuplication(_strChar(node->str, '=') + 1));
			continue;
		}
		replaceString(&stream->argv[i], _strDuplication(""));

	}
	return (0);
}

/**
 * replaceString - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replaceString(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
