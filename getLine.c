#include "main.h"

/**
 * inputBuffer - buffers chained commands
 * @stream: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 * Return: bytes read
 */

ssize_t inputBuffer(stream_t *stream, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)stream->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, signalNumHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = getLine(stream, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			stream->inputLineCount = 1;
			removeComments(*buf);
			buildHistoryList(stream, *buf, stream->histCount++);
			/* if (_strChar(*buf, ';')) is this a command chain? */
			{
				*len = r;
				stream->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * getInputLine - gets a line minus the newline
 * @stream: parameter struct
 * Return: bytes read
 */
ssize_t getInputLine(stream_t *stream)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(stream->arg), *p;

	_putChar(BUF_FLUSH);
	r = inputBuffer(stream, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		j = i; /* init new iterator to current buf position */
		p = buf + i; /* get pointer for return */

		checkChain(stream, buf, &j, i, len);
		while (j < len) /* iterate to semicolon or end */
		{
			if (isChain(stream, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			stream->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strLength(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from getLine() */
}

/**
 * readBuffer - reads a buffer
 * @stream: parameter struct
 * @buf: buffer
 * @i: size
 * Return: r
 */
ssize_t readBuffer(stream_t *stream, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(stream->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * getLine - gets the next line of input from STDIN
 * @stream: parameter struct
 * @linePtr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated linePtr buffer if not NULL
 * Return: s
 */
int getLine(stream_t *stream, char **linePtr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *linePtr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = readBuffer(stream, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strChar(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strConcatenation(new_p, buf + i, k - i);
	else
		_strNCopy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*linePtr = p;
	return (s);
}

/**
 * signalNumHandler - handle signal number
 * @sig_num: the signal number
 * Return: void
 */
void signalNumHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putChar(BUF_FLUSH);
}
