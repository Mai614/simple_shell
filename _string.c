/**************************done**************************/

#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}


/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (str[length] != '\0')
		length++;

	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		ret[length] = str[length];

	ret[length] = '\0';
	return (ret);
}


/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;

	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] < s2[i] ? -1 : 1);
}


/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = *src;

	return (ret);
}


/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*needle != *haystack)
			return (NULL);
		needle++;
		haystack++;
	}

	return ((char *)haystack);
}
