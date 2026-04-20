#include "main.h"

/**
 * main - Point d'entrée du shell
 * Return: 0
 */
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