# Version 0.3

Les équipes de designers ont travaillé d'arrache-pied et il y a désormais plusieurs cartes disponibles pour jouer les 
parties d'**Underwatch**. La carte originale, un vieux château, s'appelle `u_castle`. Les designers en ont créé deux 
nouvelles, `u_mill` une ferme avec un moulin et `u_city`, un quartier de bourg médiéval.

Vu les premiers retours des testeurs, le style de jeu est très différent entre les cartes et les joueurs ont des avis 
très polarisés. Les fans de `u_castle` ont tendance à détester `u_mill`, très ouverte. A l'inverse, les fans de `u_mill`
n'aiment pas trop les deux autres.

Comme les designers veulent se garder la possibilité de faire des cartes très différentes sans s'aliéner les joueurs,
ils veulent que vous les aidiez.

Pour éviter que les joueurs jouent sur une carte qu'ils détestent, ils pourront désormais choisir d'en exclure une, ce
qui leur garantit qu'ils ne la recontreront jamais.

## Spécifications

Votre matchmaking doit maintenant assigner une carte à chaque partie et bien entendu ne jamais envoyer un joueur sur la
carte qu'il a exclue. 

Le **fichier d'entrée** contient désormais trois champs : le nom du joueur (comme pour la v0.1), suivi de sa classe
(comme pour la v0.2) et maintenant le nom de la carte exclue.

Le **fichier de sortie** contient désormais trois champs : les compositions des deux équipes, ainsi qu'en troisième
champ le nom de la carte sur laquelle se déroule la partie.
