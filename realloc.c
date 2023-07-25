#include "xshell.h"

/**
 * mem_reall - Reallocates memory block
 * @p: pointer par
 * @ld_sz: previous pointer size
 * @nw_sz: pointer size
 * Return: Pointer
 */

void *mem_reall(void *p, unsigned int ld_sz, unsigned int nw_sz)
{
	char *nw, *ld;
	unsigned int x;

	if (p == NULL)
		return (malloc(nw_sz));

	if (nw_sz == ld_sz)
		return (p);

	if (nw_sz == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}
	nw = malloc(nw_sz);
	ld = p;
	if (nw == NULL)
		return (NULL);
	if (nw_sz > ld_sz)
	{
		x = 0;
		for (; x < ld_sz; x++)
			nw[x] = ld[x];
		free(p);
		for (x = ld_sz; x < nw_sz; x++)
			nw[x] = '\0';
	}
	if (nw_sz < ld_sz)
	{
		x = 0;
		for (; x < nw_sz; x++)
			nw[x] = ld[x];
		free(p);
	}
	return (nw);
}

/**
 * agrv_fr - frees the array of pointers arv
 * @av: array of pointers
 * Return: void
 */
void agrv_fr(char **av)
{
	int y;

	y = 0;
	for (; av[y]; y++)
		free(av[y]);
	free(av);
}
