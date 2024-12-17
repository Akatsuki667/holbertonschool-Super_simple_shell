#!/bin/bash
# Récupérer la limite maximale de processus
maxproc=$(launchctl limit | grep maxproc | awk '{print $3}')
# maxproc=$() -> exécute commande et stocke sa sortie dans une variable
# launchctl limit -> liste les limites des ressources définies
# | grep maxproc -> le pipe redirige sortie de launchctl comme entrée vers grep
# grep maxproc -> recherche uniquement ligne contenant maxproc
# | awk -> résultat de grep est passé à awk (outil traitement de texte en colonne
# '{print $3}' -> $3(3ème colonnes)

# Afficher la valeur
echo "Le nombre maximal de processus (et donc de PIDs) sur ce système est : $maxproc"