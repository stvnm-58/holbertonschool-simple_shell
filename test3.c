
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/*RECHERCHE DU CHEMIN (EXO 4/5)*/
char *find_path(char *command)
{
	char *path = NULL, *path_copy, *token, *full_path;
	struct stat st;
	int i = 0;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
		i++;
	}
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/* MAIN (EXO 6)*/
int main(void)
{
	char *line = NULL, *full_path;
	size_t len = 0;
	char *av[64];
	int i, status;
	pid_t child_pid;

	while (1)
	{ /* Affiche le prompt seulement en mode interactif */
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			break;
		}

		/*Découpage SEPARER FONCTION*/
		i = 0;
		av[i] = strtok(line, " \n\t");
		while (av[i] != NULL)
		{
			i++;
			av[i] = strtok(NULL, " \n\t");
		}

		/*LE CERVEAU : Prise de décision */

		/* Cas A : L'utilisateur n'a rien tapé */
		if (av[0] == NULL)
			continue;

		/* Cas B : L'utilisateur veut quitter */
		if (strcmp(av[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}
		/* Cas C : L'utilisateur veut voir l'environnement */
		else if (strcmp(av[0], "env") == 0)
		{
			int j = 0;
			while (environ[j])
			{
				printf("%s\n", environ[j]);
				j++;
			}
		}
		/* Cas D : Commande externe (ls, /bin/ls, etc.) */
		else
		{
			full_path = find_path(av[0]);
			if (full_path != NULL)
			{
				child_pid = fork();
				if (child_pid == 0)
				{
					if (execve(full_path, av, environ) == -1)
						perror("./shell");
					exit(0);
				}
				else
					wait(&status);
				free(full_path);
			}
			else
				fprintf(stderr, "./shell: 1: %s: not found\n", av[0]);
		}
	}
	return (0);
}
