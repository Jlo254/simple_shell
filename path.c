

#include "shell.h"

/**
 * break_side - function that breaks the path environment
 * @side: path environment variable;
 *
 * Return: the directory
 */

char **break_side(char *side)
{
char *token, *path_dup;
char **path_dirs;
int i, path_count;
path_count = get_side_num(side);
path_dirs = malloc(sizeof(char *) * (path_count + 1));
if (path_dirs == NULL)
{
free(side);
return (NULL);
}
path_dup = _strd(side);
token = strtok(path_dup, ":");
i = 0;
while (i < path_count)
{
path_dirs[i] = _strd(token);
i++;
token = strtok(NULL, ":");
}
path_dirs[path_count] = NULL;
free(side);
free(path_dup);
return (path_dirs);
}


/**
 * concat_path - function that concates path
 * @side: the path arg
 * @comd: the command to add
 *
 * Return: a pointer to the buff
 */
char *concat_path(char *side, char *comd)
{
int i, j, total_len;
char *path_buff;
i = 0;
total_len = str_len(side) + str_len(comd);
path_buff = malloc(sizeof(char) * (str_len(side) + str_len(comd) + 2));
if (path_buff == NULL)
return (NULL);
while (side[i])
{
path_buff[i] = side[i];
i++;
}
path_buff[i] = '/';
i += 1;
for (j = 0; comd[j]; j++, i++)
{
path_buff[i] = comd[j];
}
path_buff[total_len + 1] = '\0';
return (path_buff);
}


/**
 * check_file - function that checks file
 * @dir_arr: Array directory
 * @command: the file to look for
 *
 * Return: the path if found, null on error
 */
char *check_file(char **dir_arr, char *command)
{
char *path_buf;
int i, ok_f = 0, ok_x = 0;

for (i = 0; dir_arr[i]; i++)
{
path_buf = concat_path(dir_arr[i], command);
ok_f = access(path_buf, F_OK);
ok_x = access(path_buf, X_OK);
if (ok_f == 0)
{
if (ok_x == 0)
{
mem_free(dir_arr);
return (path_buf);
}
else
{
mem_free(dir_arr);
free(path_buf);
return ("no access");
}
}
free(path_buf);
}
mem_free(dir_arr);
return (NULL);
}

/**
 * get_side_num - function that gets numbers
 * @side: Environ path to count
 *
 * Return: the nums of dir
*/
int get_side_num(char *side)
{
int i, counts;
i = 0;
counts = 0;
while (side[i] != '\0')
{
if (side[i] == ':')
{
counts++;
}
i++;
}
return (counts);
}
