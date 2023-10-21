#include "shell.h"

/**
 *_eputs - A fun prts an input strn
 * @str: The strg to be prt.
 *
 * Return: Non
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _putfd - A fun that wrt the char
 * @c: The char to print.
 * @fd: The filedescriptor.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - A fun that prnts an input str
 * @str: The strg to be prtd.
 * @fd: The filedescriptor.
 *
 * Return: the No of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
 * _eputchar - A fun that writes the char c to.
 * @c: The char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set app.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
