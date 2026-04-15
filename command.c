#include <stdlib.h>
#include <string.h>


/*
*
* fonction pour découper une chaîne de caractère
* en mots organisé dans un tableau
*/
char **split_string(char *str)
{
	int i = 0;
	char *current_word;
	char **words;

	words = malloc(sizeof(char *) * 64);

	current_word = strtok(str, " ");

	while (current_word != NULL)
	{
		words[i] = current_word;
		i++;
		current_word = strtok(NULL, " ");
	}

	words[i] = NULL;

	return (words);
}



/*
*
* Fonction pour vider la mémoire d'un tableau de string
*
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
