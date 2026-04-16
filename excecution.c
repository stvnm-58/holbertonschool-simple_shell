#include "main.h"

/**
 * find_path - Localise le chemin d'une commande dans le système.
 * @command: Le nom de la commande (ex: "ls" ou "/bin/ls").
 *
 * Description: La fonction vérifie d'abord si la commande contient un slash.
 * Si c'est le cas, elle teste si le fichier existe. Sinon, elle parcourt
 * la variable d'environnement PATH, découpe chaque répertoire et teste
 * l'existence de la commande dans chacun d'eux.
 *
 * Return: Une chaîne de caractères contenant le chemin complet valide,
 * ou NULL si la commande n'est pas trouvée ou en cas d'échec.
 * Note: L'appelant est responsable de libérer la mémoire retournée (free).
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

/*
*
*
* ici les fonction fork, execve et wait
*
*
*
*
*
*/
