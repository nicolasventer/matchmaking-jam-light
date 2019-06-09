# Commentaires

## Version 0.1

L'objectif de cette version est de démarrer la jam sur une itération très simple. Elle permet aux participants de mettre
en place leur environnement de développement, de se mettre d'accord sur le choix du langage ou d'eventuelles méthodes 
particulières comme le TDD.

C'est aussi un retour aux basiques avec de la lecture de fichiers, pour laquelle on est souvent un peu rouillé :-)

Dans cette version, la file d'attente est une file, au sens le plus basique du terme : linéaire, consommé uniquement à
partir de la tête, avec un ordre fixe.

## Version 0.2 

Le problème rencontré par l'équipe QA est qu'il peut y avoir un déséquilibre entre les classes, ce qui fait que certains
joueurs peuvent passer trop de temps en file d'attente. Dans les jeux où il y a une contrainte forte de ce type à
l'entrée dans la file d'attente, il n'y a pas vraiment de solution algorithmique. On va plutôt inciter les joueurs à 
choisir une des classes les plus demandées, par exemple avec des récompenses supplémentaires (c'est ce que fait
World of Warcraft).

Le passage à la version 0.2 est l'occasion d'introduire deux concepts centraux dans les systèmes de matchmaking : 

- files d'attentes multiples (par exemple ici, une file d'attente pas classe) qui rendent plus facile la sélection des 
joueurs dans une partie

- système de template pour créer des parties : le matchmaker initialise un template, lequel détermine quels joueurs 
sélectionner dans la file d'attente.

## Version 0.3

Les deux problèmes rencontrés sont évidemment lié à cette exclusion de carte.

- si une carte est exclue par une majorité de joueurs, elle ne sera plus jouée

- si un joueur exclut la carte la plus populaire, il passera plus de temps en file d'attente

Pour éviter qu'un système d'exclusion n'ait un impact trop grand sur le matchmaking, il suffit de limiter le nombre
d'exclusions par rapport au nombre de choix totaux. Ici on a 1 exclusion pour 3 choix, en pratique on aura au minimum
une exclusion pour 10 choix.

Quand on commence à accumuler les contraintes, on peut envisager de voir la file d'attente comme une base de données 
ordonnées de joueurs, qu'on peut alors sélectionner suivant des contraintes particulières.

## Version 0.4

Ajouter la notion de niveau de joueur avec un score peut avoir plusieurs impacts négatifs. La répartition des scores
suit généralement une gaussienne : il y a donc beaucoup de joueurs autour de la moyenne, peu avec des scores extrêmes.
Ces derniers subissent donc souvent des temps d'attente plus longs lorsqu'ils cherchent des parties.

Il peut alors être nécessaire d'étendre un peu la plage acceptable de scores pour les valeurs extrêmes, même si 
l'équilibre de la partie risque d'en souffrir.

Quand les joueurs sont séparés par classe au moment du matchmaking, représenter leur niveau par un score unique est
trop réducteur. Par exemple un tank très expérimenté avec un score élevé peut décider de se mettre à jouer en soigneur,
rôle pour lequel il sera moins bon. On essayera alors de noter les joueurs rôle par rôle, pour avoir une estimation 
précise de leur niveau.

La gestion d'un score présente de très nombreux challenges et peut être un exercice à part entière, bien que plus 
centré sur les statistiques et les mathématiques en général.

## Extras

Lorsqu'on se met à gérer les groupes prédéfinis, d'autres approches peuvent devenir nécessaire, comme par exemple de
créer des parties à partir d'un groupe prédéfini et des les compléter avec des joueurs disponibles.

Un jeu comme Overwatch cherche à équilibrer les groupes prédéfinis (qui dans un jeu par équipe vont souvent mieux 
communiquer et donc avoir un avantage) en mettant des groupes similaires en taille et en niveau de chaque côté. 

## Exemples de la vie réelle 

* [Scott Mercer, de l'équipe d'Overwatch, donne un aperçu des mécanismes interne du matchmaking du jeu](https://us.forums.blizzard.com/en/overwatch/t/groups-and-matchmaking-in-overwatch/134776)

* [Aperçu du système de templates dans le matchmaking de World of Tanks](http://wiki.wargaming.net/fr/Matchmaking_(WoT))

* [Système Trueskill 2.0 de Microsoft pour déterminer le niveau d'un joueur](https://www.microsoft.com/en-us/research/publication/trueskill-2-improved-bayesian-skill-rating-system/)

* [Présentation du matchmaking de League of Legends](https://support.riotgames.com/hc/fr/articles/201752954-Guide-du-matchmaking)
