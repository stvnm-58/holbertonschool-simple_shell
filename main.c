#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Point d'entrée du shell simple.
 *
 * Description: Boucle infinie qui affiche un prompt, lit une ligne
 * de commande via getline, la découpe en arguments avec split_string,
 * puis prépare l'exécution.
 *
 * Return: 0 en cas de succès, 1 ou autre en cas d'erreur.
 */

int main(void)
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
