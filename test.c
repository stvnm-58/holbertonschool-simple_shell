/*
*
*
* Espace de test / stockage temporaire de code
*
*/




#include "main.h"
#include <stdio.h>
#include <stdlib.h>


int main (void)
{

char *line = NULL;
size_t len = 0;
ssize_t nread;
char **args;
int i;

while (1)
{
    printf ("$ ");
nread = getline(&line, &len, stdin);
if (nread = -1)
{
    free(line);
    exit(EXIT_SUCCESS);
}


args = split_string(line);

i = 0;

while (args[i] != NULL)
{
    printf ("Argument %d : %s\n", i, args[i]);
}

free (args);
return (0);
}

}
