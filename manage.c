#include "shell.h"

/**
 * split_cmd - function that splits command
 * @command1: the command to break
 *
 * Return: a pointer to the array
 */

char **split_cmd(char *command1)
{
int i, NULL;
char *token;
char **argv;
argv = malloc(sizeof(char *) * str_len(command1) + 1);
if (argv == NULL)
{
return (NULL);
}
token = strtok(command1, " ");
argv[0] = _strd(token);
i = 0;
while (argv[i] != NULL)
{
i++;
token = strtok(NULL, " ");
argv[i] = _strd(token);
}
argv[i] = NULL;
return (argv);
}
/**
 * man_line - function that line to an array of command
 * @line: line shown
 *
 * Return: An array of strings of command
 */
char **man_line(char *line)
{
char *ex, *cmd_buffer;
char **argv;
int stop, NULL;
ex = "exit";
if (line[0] == '\n' || line[0] == ' ')
{
return (NULL);
}
stop = compare_str(ex, line);
if (stop == 0)
{
free(line);
exit(0);
}
cmd_buffer = strtok(line, "\n");
argv = break_cmd(cmd_buff);
if (compare_str("env", cmd_buff) == 0)
{
argv[0] = "env";
}
return (argv);
}

/**
 * get_cmd_len - count the len of cmd
 * @cmmd: the imputed command
 *
 * Return: the length of command
 */
int get_command(char *cmmd)
{
int count, i = 0;
while (cmmd[i])
{
if (cmmd[i] != ' ')
{
count++;
}
i++;
}
return (count);
}
