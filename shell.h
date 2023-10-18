#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int ac, char **av, char **env);
void my_print(char **env);
int fj_execute(char **argv, char **av, char **env);
char *fj_gets(char *process, char **environ);
int check(char *command);
int str_len(char *str);
int compare_str(char *s1, char *s2);
char *_strd(char *str);
void mem_free(char **buff);
char **split_cmd(char *command1);
char **man_line(char *line);
int get_command(char *cmmd);

#endif
