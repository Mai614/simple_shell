#include "main.h"

/**
 * print_error - Prints an error message.
 * @info: The parameter and return info struct.
 * @estr: String containing specified error type.
 * Return: Nothing
 */
void print_error(info_t *info, char *estr)
{
char *n = info->fname;
while (*n != '\0')
_eputchar(*n++);
_eputs(": ");
n = convert_number(info->line_count, 10, 0);
while (*n != '\0')
_eputchar(*n++);
_eputs(": ");
n = info->argv[0];
while (*n != '\0')
_eputchar(*n++);
_eputs(": ");
n = estr;
while (*n != '\0')
_eputchar(*n++);
}

/**
 * _erratoi - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: 0 if no numbers in string, converted number otherwise,
 * -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;

if (*s == '+')
s++;
for (i = 0; *(s + i) != '\0'; i++)
{
if (*(s + i) >= '0' && *(s + i) <= '9')
{
result *= 10;
result += (*(s + i) - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 * print_d - Prints a decimal (integer) number (base 10)
 * @input: The input number
 * @fd: The file descriptor to write to
 * Return: The number of characters printed
 */
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;
return (count);
}

/**
 * remove_comments - Replaces the first instance of '#' with '\0'
 * @buf: Address of the string to modify
 * Return: 0
 */
void remove_comments(char *buf)
{
char *n = buf;

while (*n != '\0')
{
if (*n == '#' && (n == buf || *(n - 1) == ' '))
{
*n = '\0';
break;
}
n++;
}
}

/**
 * convert_number - Converter function, a clone of itoa
 * @num: The number
 * @base: The base
 * @flags: Argument flags
 * Return: The converted string
 */
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
char signs = 0;
char *n;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
signs = '-';
}
n = &buffer[49];
*n = '\0';

do {
*--n = "0123456789ABCDEF"[n % base];
n /= base;
} while (n != 0);
if (signs)
*--n = signs;
return (n);
}
