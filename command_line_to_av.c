#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - Entry point, découpage d'une string en sous-chaîne
 * Return: 0 pour succès, 1 pour échec
 */
int main(void)
{
	char *line = NULL; /* pointeur stockage entrée utilisateur */
	size_t len = 0; /* taille initiale buffer alloué */
	char *token; /* pointeur stockage mot extrait avec strtok */
	char *array[1024]; /* stockage mot extrait */
	char *delim = " "; /* délilmitateur des mots */
	int i = 0; /* index pour écrire dans le tableau */
	int j; /* index pour lire tableau */

	printf("$ "); /* affichage prompt*/

	if (getline(&line, &len, stdin) == -1) /* vérification lecture a échoué */
	/* lire ligne d'entrée à partir de stdin(clavier) */
	{
		printf("Error detected, exiting\n");
		free(line);
		return (1);
	}

	token = strtok(line, delim); /* découpage line en sous chaîne */
	while (token) /* tant que mots disponible */
	{
		array[i++] = token; /* stockage de chaque mot trouvé */
		token = strtok(NULL, delim); /* appel pour continuer analyse line */
	}
	for(j = 0; j < i; j++) /* boucle lecture tableau */
		printf("%s\n", array[j]); /* affichage chaque mots trouver */

	free(line);
	return (0);

}
