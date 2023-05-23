#include "main.h"

/**
 * _putsfd - Prints an input string.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters put.
 */
int _putsfd(char *str, int fd)
{
int count = 0;
int i;
if (!str)
return (0);
for (i = 0; str[i] != '\0'; i++)
count += _putfd(str[i], fd);
return (count);
}

/**
 * _eputs - Prints an input string.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void _eputs(char *str)
{
int i;

if (!str)
return;
for (i = 0; str[i] != '\0'; i++)
_eputchar(str[i]);
}

/**
 * _putfd - Writes the character c to given fd.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

i = 0;
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

/**
 * _eputchar - Writes the character c to stderr.
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

i = 0;
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
