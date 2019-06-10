# Implémentation

Voici une implémentation **C++** de la Jam de code Matchmaking.
> Résumé des caractéristiques de la ***(v0.4)*** :
> Un joueur a une classe, un elo et peut bannir une map.

Pour compiler le code utiliser la commande :
```
g++ Matchmaking.cpp -o Matchmaking.exe
```
Pour exécuter le code utiliser la commande :
```
Matchmaking.exe < input.txt > output.txt
```
## Fonctionnement du code

Une *Queue* contient plusieurs *GameList*.  
Chaque *GameList* est associée à une map.  
Lorsque l'on ajoute un joueur, il est ajouté aux *GameList* dont la map n'est pas celle bannie par le joueur.  
Pour cela, le joueur crée une *Game* dont il en est l'hôte et essaye, d'un côté de s'ajouter à toutes les *Game* déjà créées, et d'un autre, d'ajouter à sa *Game* tous les autres joueurs déjà en queue.  
Si une *Game* est pleine, elle est créée. Tous les joueurs présents dans celle-ci sont déclarés comme invalides afin de les supprimer de toutes les autres *Game*. Si l'hôte d'une *Game* est invalide, la *Game* est supprimée.  
Ainsi la fin de l'ajout de joueurs marque la fin de la création de parties. Tous les joueurs sont donc supprimés.
