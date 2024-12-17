#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * main - Entry point
 * Return: 0 pour succès, 1 si EOF est détecté
 */
int main(void)
{
char *line = NULL; /* pointeur stockage entrée utilisateur */
size_t len = 0; /* taille initiale du buffer alloué */
printf("$ "); /* affichage prompt */
if (getline(&line, &len, stdin) == - 1) /* vérification lecture a échoué */
/* lire ligne d'entrée à partir de stdin(clavier) */
{
printf("EOF detected, exiting\n"); /* affichage messeage erreur */
free(line); /* libération mémoire alloué par getline() */
return 1;
}
printf("%s\n", line); /* sinon affiche entrée utilisateur */
free(line); /* libération mémoire alloué par getline()*/
return 0;
}