# Jam de code Matchmaking - 6 juin 2019 - Arolla

## Underwatch, un FPS médiéval par équipe

Vous faites partie de l'équipe de développement d'Underwatch, un FPS par équipe en 5vs5. Comme la plupart des jeux multijoueurs récents, c'est vous qui hébergez les serveurs de jeu : les joueurs se connectent, se mettent en file d'attente pour jouer et un système de matchmaking assemble automatiquement les équipes et démarrent la partie.

C'est à vous d'écrire le système de matchmaking et comme le développement itératif c'est la base, vous démarrez sur une version simple, avant d'itérer avec des fonctionnalités supplémentaires.

## Détails techniques

Pour simplifier la jam et la rendre agnostique vis à vis d'un langage ou d'une stack technique particulière, la file d'attente des joueurs est représentée par un fichier CSV, avec `;` comme séparateur. Les parties qui sont créées sont aussi représentées dans ce format. Les champs seront précisés à chaque étape.

Les étapes après la première sont masquées par défaut pour garder l'effet de surprise, vous préférerez ne pas vous divulgâcher la suite.

## Version 0.1

C'est votre MVP, celui qui va permettre à l'équipe QA de tester un peu plus facilement la version actuelle du jeu, la 0.1. Vous devez simplement créer une partie dès que vous avez 10 joueurs par équipe.

Dans les fichiers d'entrée, le deuxième champ contient le nom de joueurs. Le format de sortie attendu est un fichier CSV séparé par des `;` à deux colonnes, chacune contenant la liste des noms des joueurs de chaque équipe, séparés par des `,`.

Une fois votre matchmaker implémenté, vous recevez les remerciements de l'équipe QA. Il leur suffit de se mettre en file d'attente, au lieu de devoir lancer des lignes de commande obscures pour démarrer une partie.

## Version 0.2

<details><summary>Cliquez pour révéler cette étape</summary><p>
Pour cette version, les développeurs vous annoncent fièrement qu'ils ont implémenté les classes. Les joueurs peuvent être tanks (`T`), soigneurs (`H`) ou dégâts (`D`). Pour des raisons d'équilibre, chaque équipe doit comporter 1 tank, 1 soigneur et 3 dégâts.
  
Votre matchmaking doit désormais prendre cette caractéristique en compte.

La classe est désignée par sa lettre dans le troisième champ du fichier d'entrée.
</p></details>

Après avoir implémenté cette étape, on vous prévient que l'équipe QA a rencontré un problème. Pouvez-vous deviner de quoi il s'agit ?
