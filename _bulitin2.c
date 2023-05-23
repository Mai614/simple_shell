/*****************done**********************/
#include "main.h"
/**
 * _myhelp - Prints help information.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: 0
 */
int _myhelp(info_t *info)
{
char **arg_array = info->argv;
_puts("help call works. Function not yet implemented\n");
if (0)
_puts(*arg_array);
return (0);
}

/**
 * _myexit - Exits the shell.
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 * Return: Exits with a given exit status (0) if info.argv[0] != "exit".
 */
int _myexit(info_t *info)
{
int exitcheck;

if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
/**
 * _mycd - Changes the current directory of the process.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: 0
 */
int _mycd(info_t *info)
{
char *m, *dirc, buffer[1024];
int chdir_ret;

m = getcwd(buffer, 1024);
if (!m)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
dirc = _getenv(info, "HOME=");
if (!dirc)
chdir_ret = chdir((dirc = _getenv(info, "PWD=")) ? dirc : "/");
else
chdir_ret = chdir(dirc);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(m);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD="));
_putchar('\n');
chdir_ret = chdir((dirc = _getenv(info, "OLDPWD=")) ? dirc : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]);
_eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}
