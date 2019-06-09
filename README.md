# Jam de code Matchmaking - 6 juin 2019 - Arolla

Ce sujet de programmation est disponible sous licence [Creative Commons BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.fr).

Vous êtes libres de le copier, le modifier ou le partager dans les mêmes conditions, y compris pour un usage commercial,
sous réserve d'attribution à l'auteur original (vous pouvez mentionner "Christophe MICHEL" ou mettre un lien vers ce
dépôt).

## Underwatch, un FPS médiéval par équipe

Vous faites partie de l'équipe de développement d'Underwatch, un FPS par équipe en 5vs5. Comme la plupart des jeux 
multijoueurs récents, c'est vous qui hébergez les serveurs de jeu : les joueurs se connectent, se mettent en file 
d'attente pour jouer et un système de matchmaking assemble automatiquement les équipes et démarrent la partie.

C'est à vous d'écrire le système de matchmaking et comme le développement itératif c'est la base, vous démarrez sur 
une version simple, avant d'itérer avec des fonctionnalités supplémentaires.

## Détails techniques

Pour simplifier la jam et la rendre agnostique vis à vis d'un langage ou d'une stack technique particulière, la file 
d'attente des joueurs est représentée par un fichier CSV, avec `;` comme séparateur. Les parties qui sont créées sont 
aussi représentées dans ce format. Les champs seront précisés à chaque étape.

Prenez soin de ne pas lire les specs d'une étape avant d'avoir complété la précédente pour ne pas vous 
divulgâcher la suite.

## Version 0.1

[Spécifications de la version 0.1](/v0.1/specs1.md)

Une fois votre matchmaker implémenté, vous recevez les remerciements de l'équipe QA. Il leur suffit de se mettre en 
file d'attente, au lieu de devoir lancer des lignes de commande obscures pour démarrer une partie.

## Version 0.2

[Spécifications de la version 0.2](/v0.2/specs2.md)

Après avoir implémenté cette étape, on vous prévient que l'équipe QA a rencontré un problème. Pouvez-vous deviner de 
quoi il s'agit ? Quelles solutions proposez-vous ?

## Version 0.3

[Spécifications de la version 0.3](/v0.3/specs3.md)

Cette fois c'est encore pire, l'équipe QA a remonté deux problèmes. A votre avis, lesquels ? Et comment pensez-vous les
régler ?

## Version 0.4

[Spécifications de la version 0.4](/v0.4/specs4.md)

Une fois le système en place, le calme revient dans le studio. Vous n'avez pas de fonctionnalités à implémenter dans
l'immédiat, vous décidez donc d'aider les designers sur le système que vous venez d'intégrer.

Quels sont les problèmes potentiels de ce type de système pour un jeu comme **Underwatch** ? Comment les 
aborderiez-vous ?

## Contraintes supplémentaires

Une fois ces étapes déroulées, vous pouvez pousser l'exercice plus loin avec 
[ces contraintes supplémentaires](extras/contraintes.md).

## Commentaires

Une fois les implémentations terminées, vous pouvez également lire les 
[commentaires faits pendant la jam](extras/commentaires.md).
