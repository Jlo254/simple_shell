#include "shell.h"

/**
 * main - function that creates entry of shell
 * @av: This shows the argument count
 * @ac: argument vector
 * @env: indicate environment variables
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
ssize_t length_read;
size_t length;
int status,  envs, is_term = isatty(0);
char *strand, **argv;
signal(SIGINT, SIG_IGN);
(void)ac;
length = 0, strand = NULL;
while (1)
{
if (is_term)
write(STDOUT_FILENO, "shellissimple$ ", 9);
length_read = getline(&strand, &length, stdin);
if (length_read == -1)
{
free(strand);
exit(0);
}
argv = man_line(strand);
if (argv == NULL)
continue;
if (compare_str(argv[0], "env") == 0)
{
my_print(env);
continue;
}
envs = check(argv[0]);
status = path_handl(envs, argv, av, env);
if (status == -1)
{
free(strand);
exit(0);
}
fj_execute(argv, av, env);
mem_free(argv);
}
free(strand);
return (0);
}
/**
 * path_handl - function that handles the path dir
 * @argv: Array command
 * @env_f: user input
 * @av: argument vector
 * @env:array of environment variables
 *
 * Return: 0 on succes, -1 on error
 */
int path_handl(int env_f, char **argv, char **av, char **env)
{
char **path_dirs, *value, *path1;
if (env_f == 1)
{
value = fj_gets("PATH", env);
if (value == NULL)
{
handle_error(av[0], argv[0]);
mem_free(argv);
return (-1);
}
path_dirs = break_side(value);
path1 = check_file(path_dirs, argv[0]);
if (path1 != NULL)
{
if (compare_str("no access", path1) == 0)
{
print_error(av[0], argv[0]);
mem_free(argv);
free(path1);
return (-1);
}
free(argv[0]);
argv[0] = path1;
}
else
{
handle_error(av[0], argv[0]);
mem_free(argv);
free(path1);
return (-1);
}
}
return (0);
}
