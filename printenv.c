#include <stdio.h>
#include <unistd.h> /* accéder à environ */
/**
 * main - programme principal pour afficher les variables d'environnement
 * @ac: nombre d'arguments (non utilisé)
 * @av: tableau des arguments (non utilisé)
 * @env: tableau des variables d'environnement
 * Return: 0 pour succès
 */
int main(int ac, char **av, char **env)
{
	extern char **environ; /* déclaration externe variable environnement */

	int i = 0; /* index parcourir variable environnement */

	(void)ac; /* marqueur paramètre non utilisé */
	(void)av; /* marqueur paramètre non utilisé */

	while (environ[i]) /* parcourt chaque variable d'environnement */
	{
		printf("%s\n", environ[i]); /* affiche chaque variable d'environnement */
		i++; /* incrémentation varaible d'environnement suivante */
	}

	return (0);
}
