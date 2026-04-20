#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
void handle_execution(char **av, char *line);
char *find_path(char *command);
void parse_line(char *line, char **av);
void print_env(void);

#endif
