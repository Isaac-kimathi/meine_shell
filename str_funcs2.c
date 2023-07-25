#include "xshell.h"

/**
 * dup_str - returns a pointer to a newly allocated space in memory,
 * containing a copy of str allocated as parameter
 * @stng: string pointer par
 * Return: string pointer
 */
char *dup_str(char *stng)
{
	char *nw_mm;
	int x, y;

	if (!stng)
	{
		return (NULL);
	}
	y = 0;
	for (; stng[y] != '\0';)
	{
		y++;
	}
	nw_mm = malloc(sizeof(char) * y + 1);
	if (!nw_mm)
	{
		return (NULL);
	}
	x = 0;
	for (; x < y; x++)
	{
		nw_mm[x] = stng[x];
	}
	nw_mm[y] = stng[y];
	return (nw_mm);
}

/**
 * concat_str - concats 3 strings in a newly allocated memory
 * @fx: first string
 * @dg: second string
 * @ct: Third string
 * Return: pointer to the new string
 */
char *concat_str(char *fx, char *dg, char *ct)
{
	char *rt;
	int w, q, s, x, z;

	w = length_str(fx);
	q = length_str(dg);
	s = length_str(ct);

	rt = malloc(w + q + s + 1);
	if (!rt)
		return (NULL);
	x = 0;
	for (; fx[x]; x++)
		rt[x] = fx[x];
	z = x;
	for (x = 0; dg[x]; x++)
		rt[z + x] = dg[x];
	z = z + x;
	x = 0;
	for (; ct[x]; x++)
		rt[z + x] = ct[x];
	z = z + x;
	rt[z] = '\0';

	return (rt);
}
