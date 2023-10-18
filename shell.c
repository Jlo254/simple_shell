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
argv = man_line(line);
if (argv == NULL)
continue;
if (compare_str(argv[0], "env") == 0)
{
my_print(env);
continue;
}
envs = check_env(argv[0]);
status = handle_path(envs, argv, av, env);
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
