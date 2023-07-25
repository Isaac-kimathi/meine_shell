#ifndef XSHELL_H
#define XSHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;
void rec_parse(char *com, char **av);

/**
 * struct meinebuilde - function pointer with relate builtin cmd
 * @nm: builtin cmd
 * @cexec: executes builtin cmd
 */
typedef struct meinebuilde
{
	char *nm;
	void (*cexec)(char **);
} meinebuilde;
void (*builtin_chck(char **av))(char **av);
int conv_str(char *str);
int _putchr(char c);
void _puts(char *s);

/**
 * struct dir_path - Linked list containing PATH directories
 * @dpt: directory in path
 * @l: pointer to node next
 */
typedef struct dir_path
{
	char *dpt;
	struct dir_path *l;
} dir_path;
void lst_fr(dir_path *hd);
dir_path *create_path(char *pt);dir_path *create_path(char *pt);
dir_path *ndadd_end(dir_path **hd, char *str);
char *fnd_ptnm(char *fn, dir_path *head);
char *envir_puts(const char *nm);
void exite(char **av);
void envr(char **av);
void setenvr(char **av);
void rmv_env(char **av);
void *mem_reall(void *p, unsigned int ld_sz, unsigned int nw_sz);
void agrv_fr(char **av);
char **str_split(char *s, const char *delim);
void execute(char **av);
int length_str(char *str);
char *dup_str(char *stng);
char *concat_str(char *fx, char *dg, char *ct);

#endif
