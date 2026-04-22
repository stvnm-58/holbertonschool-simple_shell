#include "main.h"

/**
 * find_path - Localise le chemin d'une commande dans le système.
 * @command: Le nom de la commande (ex: "ls" ou "/bin/ls").
 *
 * Description: Parcourt la variable d'environnement PATH pour trouver
 * l'exécutable correspondant à la commande donnée.
 * Return: Chemin complet valide, ou NULL si non trouvé.
 */
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
	if (path == NULL || path[0] == '\0')
		return (NULL);
	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
			return (NULL);
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

/**
 * parse_line - Découpe la ligne de commande en arguments.
 * @line: La chaîne de caractères à découper.
 * @av: Tableau de pointeurs pour stocker les arguments.
 */
void parse_line(char *line, char **av)
{
	int i = 0;

	av[i] = strtok(line, " \n\t");
	while (av[i] != NULL)
	{
		i++;
		av[i] = strtok(NULL, " \n\t");
	}
}

/**
 * print_env - Affiche l'environnement actuel.
 */
void print_env(void)
{
	int j = 0;

	while (environ[j])
	{
		printf("%s\n", environ[j]);
		j++;
	}
}

/**
 * handle_execution - Gère la logique de décision et d'exécution des commandes.
 * @av: Tableau d'arguments.
 * @line: Ligne de saisie brute (pour libération mémoire).
 *
 * Description: Vérifie si la commande est un built-in (env) ou une commande
 * externe. Gère le fork et l'exécution via execve.
 */
void handle_execution(char **av, char *line)
{
	char *full_path;
	int status;
	pid_t child_pid;

	if (strcmp(av[0], "env") == 0)
	{
		print_env();
		return;
	}
	full_path = find_path(av[0]);
	if (full_path)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(full_path, av, environ) == -1)
				perror("./shell");
			free(full_path);
			free(line);
			exit(0);
		}
		wait(&status);
		free(full_path);
	}
	else
		fprintf(stderr, "./shell: 1: %s: not found\n", av[0]);
}
