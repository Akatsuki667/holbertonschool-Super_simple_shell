#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - Création multiple processus enfant à exécuter une commande
 * Return: 0 pour succès, 1 pour échec
 */
int main()
{
	int i = 0; /* compteur création processus enfants */
	pid_t pid; /* stockage pid renvoyé par fork */
	int status; /* stockage status fin de processus enfants */

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	/* tableau contenant argumznts pour commande à exécutée */

	for (i = 0; i < 5; i++) /* boucle création processus enfants */
	{
		pid = fork(); /* création processus enfant */
		if (pid == - 1) /* vérification échec processus */
		{
			perror("Error:");
			return (1);
		}
		else if (pid == 0) /* vérification processus enfant */
		{
			if (execve(argv[0], argv, NULL) == -1)
			/* vérification exécution valide */
				perror("Error:");
		}
		else /* Sinon processus parent */
			wait(&status); /* instruction pour ce dernier */
	}
	return (0);
}
