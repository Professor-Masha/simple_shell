#include "shell.h"

/**
 * display_history - A fun that Displays the command history list
 *                   preceded with line numbers, starting at 0.
 * @info: The pointer to the info structure.
 *
 * Return: Returns 0.
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * remove_alias - A fun that Removes an alias with a given Nm
 * @info: The pointer to the info structure
 * @name: The Nm of the alias to remove.
 *
 * Return: 0 on success, 1 on error.
 */
int remove_alias(info_t *info, char *name)
{
	char *p, c;
	int ret;
	
	p = _strchr(name, '=');
	if (!p)
		return 1;
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, name, -1)));
	*p = c;
	return ret;
}

/**
 * create_alias - A fun that Creates an alias with a given str
 * @info: Pnt to the info structure
 * @str: The str representing the alias.
 *
 * Return: 0 on success, 1 on error.
 */
int create_alias(info_t *info, char *str)
{
    char *p;

    p = _strchr(str, '=');
    if (!p)
        return 1;
    if (!*++p)
        return remove_alias(info, str);

    remove_alias(info, str);
    return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - A fun that prints an alias string.
 * @node: The alias node to print.
 *
 * Return: 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = _strchr(node->str, '=');
        for (a = node->str; a <= p; a++)
            _putchar(*a);
        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
        return 0;
    }
    return 1;
}

/**
 * manage_alias - A fun that manages aliases
 * @info: The Pointer to the info structure.
 *
 * Return: Returns 0.
 */
int manage_alias(info_t *info)
{
    int i = 0;
    char *p = NULL;
    list_t *node = NULL;

    if (info->argc == 1)
    {
        node = info->alias;
        while (node)
        {
            print_alias(node);
            node = node->next;
        }
        return 0;
    }
    for (i = 1; info->argv[i]; i++)
    {
        p = _strchr(info->argv[i], '=');
        if (p)
            create_alias(info, info->argv[i]);
        else
            print_alias(node_starts_with(info->alias, info->argv[i], '='));
    }

    return 0;
}