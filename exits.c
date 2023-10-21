#include "shell.h"

/**
 **_strncpy - A fun that copies a strg
 *@dest: des strg to be copied.
 *@src: Source strg.
 *@n: Amount of char to be copied.
 *Return: The conc strg.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - The conc 2 strings.
 *@dest: 1st string.
 *@src: 2nd string
 *@n: Amount of bytes to be max used.
 *Return: Conc strg.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - A fun that locates a char in a strg.
 *@s: String to be parsed.
 *@c: Character to look for
 *Return: A pointer to the memory
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
