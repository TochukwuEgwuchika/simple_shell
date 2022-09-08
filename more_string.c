#include "shell.h"
/**
 * _strcpy - copie a string from source to destination
 * @source: the string source
 * @dest: the string destination
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *source)
{
	int i;

	for (i = 0; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _isalpha - check if the input is a letter
 * @c: the character to be checked
 *
 * Return: 1 if letter, -1 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (SUCCESS);
	return (FAIL);
}
/**
 * _isnumber - check if the input is a number
 * @c: the character to be checked
 *
 * Return: 1 if number, -1 otherwise
 */
int _isnumber(int c)
{
	if (c >= 48 && c <= 57)
		return (SUCCESS);
	return (FAIL);
}
/**
 * _strtok - breaks a string into one or more tokens
 * @str: the given string
 * @delim: the set of strings to use for delimiting
 *
 * Return: (Success) a pointer to the token or null if
 * there are no more tokens
 */
char *_strtok(char *str, const char *delim)
{
	static char *p;
	const char *delim_cpy;
	char *start;

	if (str != NULL)
		p = str;

	start = p;
	while (*p)
	{
		delim_cpy = delim;
		while (*delim_cpy)
		{
			if (*delim_cpy == *p)
			{
				*p = '\0';
				p++;
				return (start);
			}
			delim_cpy++;
		}
		p++;
	}
	if (*p == '\0')
		return (NULL);

	return (start);
}
