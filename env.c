#include "main.h"

/**
 * _env - prints the current environment
 * @stream: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _env(stream_t *stream)
{
	printListStr(stream->env);
	return (0);
}

/**
 * getEnv - gets the value of an environ variable
 * @stream: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *getEnv(stream_t *stream, const char *name)
{
	list_t *node = stream->env;
	char *p;

	while (node)
	{
		p = startsWith(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * setEnv - Initialize a new environment variable,
 *             or modify an existing one
 * @stream: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int setEnv(stream_t *stream)
{
	if (stream->argc != 3)
	{
		_errPuts("Incorrect number of arguments\n");
		return (1);
	}
	if (setEnv(stream, stream->argv[1], stream->argv[2]))
		return (0);
	return (1);
}

/**
 * unsetEnv - Remove an environment variable
 * @stream: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int unsetEnv(stream_t *stream)
{
	int i;

	if (stream->argc == 1)
	{
		_errPuts("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i <= stream->argc; i++)
		unsetEnv(stream, stream->argv[i]);

	return (0);
}

/**
 * populateEnvList - populates env linked list
 * @stream: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populateEnvList(stream_t *stream)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		addNodeEnd(&node, environ[i], 0);
	stream->env = node;
	return (0);
}
