#include "shell.h"

/**
 * fj_gets - function that collects environment var
 *
 * @process: variable to get
 * @environ: Environment variables
 *
 * Return: a pointer to the env var value
 */
char *fj_gets(char *process, char **environ)
{
int i, len, compare1 = 1;
char *f_var, *token, *value1;
i = 0;
len = str_len(process);
while (environ[i])
{
compare1 = compare_str(environ[i], process);
if ((compare1 == 0))
{
f_var = _strd(environ[i]);
if (str_len(f_var) == (len + 1))
{
free(f_var);
return (NULL);
}
token = strtok(f_var, "=");
token = strtok(NULL, "=");
value = _strd(token);
}
i++;
}
free(f_var);
return (value1);
}

/**
 * check - function that checks user input
 * @command: command variable
 *
 * Return: 1 on true, 0 otherwise
 */
int check(char *command)
{
int compare, compare1;
compare = compare_str(command, "/");
compare1 = compare_str(command, ".");
if (compare == 0 || compare1 == 0)
{
return (0);
}
return (1);
}
