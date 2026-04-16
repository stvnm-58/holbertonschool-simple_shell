#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (void)
{

char *line = NULL;
size_t len = 0;
ssize_t nread;
char **args;
int i;

while (1)
{
write(1, "$ ", 2);
nread = getline(&line, &len, stdin);
if (nread == -1)
{
    free(line);
    exit(EXIT_SUCCESS);
}


args = split_string(line);
if (args == NULL)
    continue;

i = 0;

}
}
