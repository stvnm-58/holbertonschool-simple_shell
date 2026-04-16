/*
*
*
* Deuxième espace de test / stockage temporaire de code
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

extern char **environ;

char *_getenv(const char *name)
{
    int i = 0;
    size_t len = strlen(name);
    while (environ[i])
    {
        if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
            return (&environ[i][len + 1]);
        i++;
    }
    return (NULL);
}

int main(int ac, char **av)
{
    struct stat st;
    char *path_copy, *token;
    char full_path[1024];

    if (ac < 2)
    {
        printf("Usage: %s command\n", av[0]);
        return (1);
    }

    /* Je récupère et on copie le PATH */
    path_copy = strdup(_getenv("PATH"));
    
    /* Je découpe */
    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        /* Je construit le chemin complet */
        sprintf(full_path, "%s/%s", token, av[1]);

        /* Je teste si ça existe */
        if (stat(full_path, &st) == 0)
        {
            printf("%s\n", full_path);
            free(path_copy);
            return (0);
        }
        token = strtok(NULL, ":");
    }

    printf("Command not found\n");
    free(path_copy);
    return (1);
}
