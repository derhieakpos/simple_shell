#include "shell.h"

/**
 * custom_Strcmp - It's check the string
 *
 * @str1: the first string char
 * @str2: the second string char
 *
 * Return: the str1 and str2
 */
int custom_Strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
