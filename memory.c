#include "shell.h"

/**
 * bfree - a fun that frees a ptr and NULLs the ads
 * @ptr: The address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
