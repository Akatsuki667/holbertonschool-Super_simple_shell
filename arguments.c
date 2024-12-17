#include <stdlib.h>
#include <stdio.h>
/**
 * main - imprimer av sans utiliser ac
 * @ac:nb arguments
 * @av: pointeur sur arguments
 * Return: retourne 0
 */
int main(int ac, char **av)
{
while (*av) /* parcours arguments */
{
printf("%s\n", *av); /* impression arguments */
av++; /* incrémentation pointeur */
}
return (0);
}