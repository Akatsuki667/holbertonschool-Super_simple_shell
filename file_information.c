#include <stdio.h> /* printf, fprintf */
#include <stdlib.h> /* getenv, strdup */
#include <string.h> /* strtok, strdup, snprintf */
#include <unistd.h> /* constantes POSIX */
#include <sys/types.h> /* types comme `struct stat` */
#include <sys/stat.h> /* stat() */

int main(int ac, char **av)
{
    char *paths, *token, *delim = ":";
    char possible_match[1024];
    struct stat stat_buffer;

    if (ac < 2) /* vérification arguments */
    {
        printf("Usage: %s FILENAME\n", av[0]);
        return (1);
    }

    paths = getenv("PATH"); /* récupération liste répertoires séparés */
    if (!paths) /* vérification existance PATH */
    {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        return (1);
    }

    /* Copier PATH pour éviter de modifier l'original */
    char *paths_copy = strdup(paths);
    if (!paths_copy) /* vérification allocation mémoire copie valide */
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return (1);
    }

    token = strtok(paths_copy, delim); /* découpage copie PATH */
    while (token) /* parcours répertoire PATH */
    {
        // Construire le chemin complet
        snprintf(possible_match, sizeof(possible_match), "%s/%s", token, av[1]);
        /* combinaison répertoire courant(token) et fichier recherché(av[1]) */
        /* écrit chemin dans possible_match tout en limitant(sizeof(possible_match)) */
        
        if (stat(possible_match, &stat_buffer) == 0)
        /* vérification existance fichier */
        {
            printf("%s\n", possible_match);
            free(paths_copy); /* Libérer la mémoire */
            return (0);
        }
        token = strtok(NULL, delim);
    }

    // Si aucun chemin trouvé
    fprintf(stderr, "Error: Command '%s' not found in PATH\n", av[1]);
    free(paths_copy); // Libérer la mémoire
    return (1);
}
