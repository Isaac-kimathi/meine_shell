#include "xshell.h"

/**
 * main - shell main function
 *
 * Return: 0 (success)
 */
int main(void)
{
	int y = 0;
	char *av[21];
       	char *cmnd = (char *) malloc(sizeof(char) * 100);

	while (1)
	{
		rec_parse(cmnd, av);
		if (strcmp(cmnd, "exit") == 0)
			break;
		if (fork() != 0)
			wait(NULL);
		else
		{
			y = execve(cmnd, av, environ);
			if (y == -1)
			{
				strcpy(cmnd, "/bin/");
				strcat(cmnd, av[0]);
				strcpy(av[0], cmnd);
				y = execve(cmnd, av, environ);
			}
		}
	}
	exit(0);
	return (0);
}
