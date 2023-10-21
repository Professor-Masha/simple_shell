#include "shell.h"

/**
 * exit_shell - A fun that exits the shell with a given exit status.
 * @info: The pointer to the info structure
 *
 * Return: 0 if info->argv[0] is not "exit".
 */
int exit_shell(info_t *info)
{
	int exit_check;

	if (info->argv[1]) /* Check if there is an exit argument. */
	{
		exit_check = string_to_integer(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_check;
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * change_directory - A fun that changes the current directory of the process.
 * @info: The pointer to the info structure.
 *
 * Return: Always returns 0.
 */
int change_directory(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * display_help - A fun that displays help information for the shell.
 * @info: The pointer to the info structure.
 *
 * Return: Returns 0.
 */
int display_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("Help functionality is not yet implemented.\n");
	if (0)
		_puts(*arg_array); /* Temporary unused variable workaround */
	return (0);
}
