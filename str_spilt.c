#include "xshell.h"

/**
 * str_split - splits a string and makes it an array of pointers to words
 * @s: the string to be split
 * @delim: the delimiter
 * Return: pointer to array of words
 */
char **str_split(char *s, const char *delim)
{
	int x, ft;
	char **arr, *tok, *dup;

	dup = malloc(length_str(s) + 1);
	if (dup == NULL)
	{
		perror(envir_puts("_"));
		return (NULL);
	}
	x = 0;
	while (s[x])
	{
		dup[x] = s[x];
		x++;
	}
	dup[x] = '\0';

	tok = strtok(dup, delim);
	arr = malloc((sizeof(char *) * 2));
	arr[0] = dup_str(tok);
	x = 1;
	ft = 3;
	while (tok)
	{
		tok = strtok(NULL, delim);
		arr = mem_reall(arr, (sizeof(char *) * (ft - 1)), (sizeof(char *) * ft));
		arr[x] = dup_str(tok);
		x++;
		ft++;
																}
	free(dup);

	return (arr);
}

/**
 * execute - executes a command
 * @av: array of arguments
 * Return: void
 */
void execute(char **av)
{
	int i, status;

	if (!av || !av[0])
		return;
	i = fork();
	if (i == -1)
	{
		perror(envir_puts("_"));
	}
	if (i == 0)
	{
		execve(av[0], av, environ);
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
