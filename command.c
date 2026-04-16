#include <stdlib.h>
#include <string.h>

/**
 * split_string - Découpe une chaîne de caractères en un tableau de mots.
 * @str: La chaîne de caractères à découper (provenant de getline).
 *
 * Description: Utilise strtok pour séparer la chaîne selon les espaces
 * et les retours à la ligne. Chaque mot est dupliqué en mémoire.
 * Return: Un tableau de pointeurs vers les mots, terminé par NULL.
 * Retourne NULL en cas d'échec d'allocation.
 */

char **split_string(char *str)
{
	int i = 0;
	char *current_word;
	char **words;

	words = malloc(sizeof(char *) * 64);

	current_word = strtok(str, " \n");

	while (current_word != NULL)
	{
		words[i] = strdup(current_word);
		i++;
		current_word = strtok(NULL, " \n");
	}

	words[i] = NULL;

	return (words);
}

/**
 * free_args - Libère la mémoire allouée pour un tableau de chaînes.
 * @args: Le tableau de pointeurs vers les chaînes de caractères.
 *
 * Description: Parcourt le tableau pour libérer chaque chaîne dupliquée
 * par strdup, puis libère le tableau lui-même. Ne fait rien si args est NULL
 */

void free_args(char **args)

{
	int i;

	if (args == NULL)
		return;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}

	free(args);
}
