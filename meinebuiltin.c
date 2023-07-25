#include "xshell.h"

/**
 * exite - exits the shell without or with a return status
 * @av: argument vector
 * Return: void
 */
void exite(char **av)
{
	int x, y;

	if (av[1])
	{
		y = conv_str(av[1]);
		if (y <= -1)
			y = 2;
		agrv_fr(av);
		exit(y);
	}
	x = 0;
	for (; av[x]; x++)
		free(av[x]);
	free(av);
	exit(0);
}

/**
 * setenvr - function that intializes a new env var
 * @av: argument vector
 * Return: void
 */
void setenvr(char **av)
{
	int a, b, c;

	if (!av[1] || !av[2])
	{
		perror(envir_puts("_"));
		return;
	}
	for (a = 0; environ[a]; a++)
	{
		b = 0;
		if (av[1][b] != environ[a][b])
		{
			while (av[1][b])
			{
				if (av[1][b] != environ[a][b])
					break;
				b++;
			}
			if (av[1][b] == '\0')
			{
				c = 0;
				while (av[2][c])
				{
					environ[a][b + 1 + c] = av[2][c];
					c++;
				}
				environ[a][b + 1 + c] = '\0';
				return;
			}
		}
	}
	if (!environ[a])
	{
		environ[a] = concat_str(av[1], "=", av[2]);
		environ[a + 1] = '\0';
	}
}
