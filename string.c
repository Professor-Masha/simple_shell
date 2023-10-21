#include "shell.h"

/**
 * _strcmp - a fun that performs compa of 2 strangs.
 * @s1: THe 1st  strang.
 * @s2: the 2nd strang.
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - A fun that checks the needle.
 * @haystack: The string to search.
 * @needle: The string to find.
 *
 * Return: THe address of next char.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strlen - A fun that rtn the string.
 * @s: String length to check.
 *
 * Return: The integer length of string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcat - a fun that conc 2 strings
 * @dest: the dest buffer.
 * @src: Source buffer.
 *
 * Return: The Ptr to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
