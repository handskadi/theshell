#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int string_length(const char *str);
char *make_string_copy(char *destination, char *source);
void __print(const char *string);
char *string_cat(char *dest, char *src);
char *duplicate_string(const char *string);
int string_compare(char *str1, char *str2);
void shell_p(char **av, char **env);
char *get_path(char *cmd);
char *get_path_var(const char *p_name);
void execute_command(char **argv);
char *locate_char_str(char *string, char character);
int string_compare_2(const char *s1, const char *s2, size_t len);
void env_print(void);
extern char **environ;
#endif
