#include "xshell.h"

/**
 * rec_parse - receives and parses the command
 * @com: string command
 * @av: command arguments
 *
 * Return: void
 */
void rec_parse(char *com, char **av)
{
	int x = 0;
	size_t y = 0;
	char *tkn;
	char *d = (char *)malloc(sizeof(char) * 1024);

	printf("kimisa@2023~$ ");
	getline(&d, &y, stdin);
	tkn = strtok(d, " \n");
	while (tkn)
	{
		av[x] = strdup(tkn);
		tkn = strtok(NULL, " \n");
		x++;
	}
	av[x] = NULL;
	strcpy(com, av[0]);
}

/**
 * builtin_chck - whether the command is built
 * @av: argumment vector
 * Return: void
 */
void (*builtin_chck(char **av))(char **av)
{
	int d, e;
	meinebuilde I[] = {
		{"exit", exite},
		{"env", envr},
		{"setenv", setenvr},
		{"unsetenv", rmv_env},
		{NULL, NULL}
	};

	d = 0;
	for (; I[d].nm; d++)
	{
		e = 0;
		if (I[d].nm[e] == av[0][e])
		{
			e = 0;
			for (; av[0][e]; e++)
			{
				if (I[d].nm[e] != av[0][e])
					break;
			}
			if (!av[0][d])
				return (I[d].cexec);
		}
	}
	return (0);
}
