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
