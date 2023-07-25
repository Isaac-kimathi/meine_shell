#include "xshell.h"

/**
 * envir_puts - establishes value of the global var
 * @nm: name of the global variable
 * Return: string of value
 */
char *envir_puts(const char *nm)
{
	char *fx;
	int q, w;

	if (!nm)
		return (NULL);
	q = 0;
	for (; environ[q]; q++)
	{
		w = 0;
		if (nm[w] == environ[q][w])
		{
			while (nm[w])
			{
				if (nm[w] != environ[q][w])
					break;
				w++;
																		}
			if (nm[w] == '\0')
			{
				fx = (environ[q] + w + 1);
				return (fx);
			}
		}
	}
	return (0);
}

/**
 * fnd_ptnm - finds the pathname of a file
 * @fn: filename or command
 * @hd: head of linked list of path directories
 * Return: filename or NULL incase there is no match
 */
char *fnd_ptnm(char *fn, dir_path *hd)
{
	struct stat fx;
	char *str;

	dir_path *tmp = hd;

	while (tmp)
	{
		str = concat_str(tmp->dpt, "/", fn);
		if (stat(str, &fx) == 0)
		{
			return (str);
		}
		free(str);
		tmp = tmp->l;
	}
	return (NULL);
}
