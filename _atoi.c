#include "shell.h"

/**
 * check_interactive - A fun that checks if the
 * shell is running in interactive mode
 * @info: The pointer to the info structure.
 *
 * Return: 1 if in interactive mode, 0 else
 */
int check_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_separator - A fun that checks if a char is a sep
 * @c: The char to check.
 * @separator: The sep char
 *
 * Return: 1 if it's a separator, 0 otherwise
 */
int is_separator(char c, char separator)
{
	while (separator)
	{
	       	if (*separator++ == c)
		       	return (1);
       	}
       	return (0);
}

/**
 * is_alphabetic - A fun that checks if a char is alpha
 * @c: The char to check.
 *
 * Return: 1 if 'c' is alphabetic, 0 else
 */
int is_alphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	       	return (1);
       	else
	       	return (0);
}

/**
 * string_to_integer - A fun that converts a string to an int.
 * @s: The strg to be convt.
 *
 * Return: 0 if no numbers in the string, converted number else
 */
int string_to_integer(char *s)
{
	int i, sign = 1, flag = 0, output;
       	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
       	{
	       	if (s[i] == '-')
			sign *= -1;
	       
	if (s[i] >= '0' && s[i] <= '9')
	{
		flag = 1;
	       	result *= 10;
	       	result += (s[i] - '0');
       	}
       	else if (flag == 1)
		flag = 2;
       	}
       
	if (sign == -1)
		output = -result;
       	else
	       	output = result;
	
	return (output);
}
