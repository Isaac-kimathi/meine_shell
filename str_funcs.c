#include "xshell.h"

/**
 * _putchr - writes the char c to stdout
 * @c: char to print
 * Return: 1 if successful, -1 on error and set appropriately
 */
int _putchr(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a str
 * @s: pointer to string
 * Return: void
 */
void _puts(char *s)
{
	int x = 0;

	for (; s[x]; x++)
		_putchr(s[x]);
}

/**
 * conv_str - converts a str into an int
 * @str: string pointer
 * Return: an int
 */
int conv_str(char *str)
{
	int x = 0, intr = 0, sgn = 1;

	while (!((str[x] >= 48) && (str[x] <= 57)) && (str[x] != '\0'))
	{
		if (str[x] == '-')
		{
			sgn = sgn * (-1);
		}
		x++;
	}
	while ((str[x] >= 48) && (str[x] <= 57))
	{
		intr = (intr * 10) + (sgn * (str[x] - '0'));
		x++;
	}
	return (intr);
}

/**
 * length_str - put forth length of a string
 * @str: string pointer
 * Return: length of str
 */
int length_str(char *str)
{
	int q = 0;

	while (*(str + q) != '\0')
	{
		q++;
	}
	return (q);
}
