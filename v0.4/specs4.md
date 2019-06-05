# Version 0.4

Celà fait déjà pas mal de temps qu'**Underwatch** est en test interne. Alors qu'il commence à vraiment prendre forme, le
responsable du projet décide de lancer une alpha interne ouverte à tout le studio de développement. Tout le monde a 
hâte d'essayer le jeu et un afflux de nouveaux joueurs se rue sur les serveurs.

Deux bonnes nouvelles. D'abord, les ops ont monté des serveurs bien dimensionnés et il n'y a pas de problème de 
capacité. Ensuite, votre matchmaking semble fonctionner comme attendu.

Mais rapidement, tout le monde se plaint auprès des game designers : les testeurs de l'équipe QA mettent des grosses
peignées à tout le monde. Ils connaissent le jeu par coeur et sont bien trop forts.

Les designers sont formels, il faut un système de classement pour ne pas dégoûter les débutants. 

Ils mettent au point un système de type [ELO](https://fr.wikipedia.org/wiki/Classement_Elo) avec un 
**score entre 0 et 100**, dans le but que les joueurs ne jouent qu'avec d'autres de niveau similaires.

## Spécifications

Vous ne devez maintenant créer des parties qu'avec des joueurs dont la plus grande différence de score est au 
maximum de 20.

Le **fichier d'entrée** contient un quatrième champ supplémentaire : le score du joueur.
 
Le format du **fichier de sortie** ne change pas.
