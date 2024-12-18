#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *_getenv(const char *name)
{
	extern char **environ; /* déclaration externe variable environnement */

	int i = 0; /* index parcourir variable environnement */
	size_t j; /* index comparaison caractères */
	size_t len = strlen(name); /* longueur clé(name) */
	int flag = 0; /* indicateur de correspondance */

	while (environ[i]) /* parcours variable environnment */
	{
		for (j = 0; j < len; j++)
		/* comparaison caractères clé avec environ[i]*/
		{
			if (environ[i][j] != name[j])
			/* si pas de correspondance */
				break; /* arrêt comparaison */
		}
		if (j == len && environ[i][j] == '=')
		/* si correspondance et caractère suivant est "=" */
		{
			flag = 1; /* indique correspondance trouvé */
			break; /* arrêt boucle for */
		}
		i++; /* incrémentation variable environnement suivant */
	}
	return (flag == 1 ? &environ[i][j+1] : NULL);
	/* retourn pointeur sur la valeur après "=" si correspondance */
}

int main()
{
	char *value = _getenv("PATH");

	if (value)
		printf("Valeur de PATH : %s\n", value);
	else
		printf("Variable PATH introuvable\n");

	return (0);
}
