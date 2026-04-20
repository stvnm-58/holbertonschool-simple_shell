#include "main.h"

#include "main.h"

/**
 * main - Point d'entrée principal pour le shell simple.
 *
 * Ce programme affiche un prompt, lit l'entrée utilisateur,
 * la découpe en arguments et gère l'exécution des commandes.
 * Il gère également le mode non-interactif et la commande 'exit'.
 *
 * Return: Toujours 0 (Succès).
 */

int main(void)
{
	char *line;
	size_t len;
	char *av[64];
	line = NULL;
	len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}

		parse_line(line, av);

		if (av[0] == NULL)
			continue;

		if (strcmp(av[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}

		handle_execution(av, line);
	}

	return (0);
}
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *av[64];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}
		parse_line(line, av);
		if (av[0] == NULL)
			continue;
		if (strcmp(av[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}
		handle_execution(av, line);
	}
	return (0);
}
