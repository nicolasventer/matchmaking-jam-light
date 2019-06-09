# Contraintes supplémentaires

## Groupes prédéfinis

Donner la possibilité à des joueurs entrant dans la file d'attente d'y entrer ensemble. Les joueurs dans le même groupe
ont un id de corrélation qui permet de les associer quand ils sont dans la file.

On peut rendre la fonctionnalité plus complexe en essayant d'équilibrer les groupes entre les deux équipes (par exemple
si une équipe comporte un groupe de 2, essayer de mettre un groupe de 2 dans l'équipe d'en face).

## Gérer le temps

Prévoir une durée maximum de présence en file d'attente. Pour représenter une situation réaliste, compter le temps en 
"ticks" arbitraires et les faire avancer en fonction d'opérations de base du matchmaking : par exemple sélectionner un 
joueur en file d'attente = 1 tick, créer une partie = 10 ticks, etc.

Un joueur en file d'attente depuis trop longtemps est soit éjecté de la file, soit ses contraintes sont assouplies
(possibilités de le mettre dans une partie avec un écart de niveau plus élevé, ignorer sa carte exclue, etc).
