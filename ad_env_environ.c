#include <stdio.h>

int main(int ac, char **av, char **env)
/* env est une copie spécifique de ce tableau passé à main */
{
	extern char **environ;
	/* environ est une référence statique aux variables d'environnement */

	int i = 0; /* index parcourir variable environnement */
	int j = 0; /* index parcourir variable environnement */

	(void)ac; /* marqueur paramètre non utilisé */
	(void)av; /* marqueur paramètre non utilisé */

	printf("ADRESSE MÉMOIRE ENVIRON :\n");

	while(environ[i]) /* parcourt chaque variable d'environnement */
	{
		printf("%p\n", environ[i]); /* affiche chaque variable d'environnement */
		i++; /* incrémentation variable d'environnement suivante */
	}

	printf("ADRESSE MÉMOIRE ENV :\n");

	while (env[j]) /* parcourt chaque variable d'environnement */
	{
		printf("%p\n", env[j]); /* affiche chaque variable d'environnement */
		j++; /* incrémentation varaible d'environnement suivante */
	}

	return (0);
}