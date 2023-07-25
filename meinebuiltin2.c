#include "xshell.h"
/**
 * envr - prints current envir
 * @av: argument vector
 * Return: void
 */
void envr(char **av)
{
	int x = 0;

	(void)av;
	for (; environ[x]; x++)
	{
		_puts(environ[x]);
		_puts("\n");
	}
}

/**
 * rmv_env - Removes env var
 * @av: argument vector
 * return: void
 */
void rmv_env(char **av)
{
	int x, y;

	if (!av[1])
	{
		perror(envir_puts("_"));
		return;
	}
	x = 0;
	for (; environ[x]; x++)
	{
		y = 0;
		if (av[1][y] == environ[x][y])
		{
		while (av[1][y])
		{
			if (av[1][y] != environ[x][y])
			break;
			y++;
		}
		if (av[1][y] == '\0')
		{
			free(environ[x]);
			environ[x] = environ[x + 1];
			while (environ[x])
			{
				environ[x] = environ[x + 1];
				x++;
			}
			return;
		}
		}
	}
}
