#include "xshell.h"

/**
 * ndadd__end - adds a new node at the end of a list_t list
 * @hd: double pointer to our linked list
 * @s: pointer to string in previous first node
 * Return: address of the new node
 */
dir_path *ndadd_end(dir_path **hd, char *s)
{
	dir_path *tpr, *nw_nd;

	nw_nd = malloc(sizeof(dir_path));
	if (!nw_nd || !s)
	{
		return (NULL);
	}
	nw_nd->dpt = s;
	nw_nd->l = '\0';
	if (!*hd)
	{
		*hd = nw_nd;
	}
	else
	{
		tpr = *hd;
		while (tpr->l)
			tpr = tpr->l;
		tpr->l = nw_nd;
	}
	return (*hd);
}

/**
 * create_path - puts a linked list for path directories
 * @pt: string of path value
 * Return: pointer to the created linked list
 */
dir_path *create_path(char *pt)
{
	dir_path *hd = '\0';
	char *tkn, *spt = dup_str(pt);

	tkn = strtok(spt, ":");
	while (tkn)
	{
		hd = ndadd_end(&hd, tkn);
		tkn = strtok(NULL, ":");
	}
	return (hd);
}

/**
 * lst_fr - frees a list_t
 * @hd: pointer to our linked list
 * return: void
 */
void lst_fr(dir_path *hd)
{
	dir_path *st;

	while (hd)
	{
		st = hd->l;
		free(hd->dpt);
		free(hd);
		hd = st;
	}
}
