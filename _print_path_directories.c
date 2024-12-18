#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _print_path_directories - Imprime chaque répertoire dans la variable PATH
 */
void _print_path_directories()
{
	extern char **environ; /* déclaration externe variable environnement */
	char *path; /* stockage PATH */
	char *copy_path; /* stockage copie PATH*/
	char *token; /* stockage déécoupage PATH */
	char *delim = ":"; /* délimitateur mots */

	path = getenv("PATH"); /* extraction PATH */
	if (path == NULL) /* vérification PATH valide */
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return;
	}

	copy_path = strdup(path); /* copie PATH extrait */
	if (copy_path == NULL) /* vérification allocation mémoire copie valide */
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		return;
	}

	token = strtok(copy_path, delim); /* découpage PATH */
	while (token) /* parcours PATH */
	{
		printf("%s\n", token); /* imprime répertoire actuelle */
		token = strtok(NULL, delim); /* passe répertoire suivant */
	}
	free(copy_path);
}

int main()
{
	_print_path_directories();
	return(0);
}
