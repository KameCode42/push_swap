<img width="720" height="720" alt="Image" src="https://github.com/user-attachments/assets/19912239-3f98-4e19-803f-567930488b84" />

# Sujet :
push_swap est un projet d’algorithme et d’optimisation. L’objectif est de trier une série d’entiers fournis en argument de la ligne de commande, en utilisant deux piles (stack A et stack B) et un ensemble limité d’opérations.

# Fonctionnement :
Initialisation : 
- On lit les arguments et on les place dans la pile A (la pile B est vide).

Tri : <br>
A chaque étape, on applique une des opérations autorisées :

swap (sa, sb, ss) :
- sa, sb : échange les 2 premiers éléments de la pile A (ou B)
- ss : sa et sb simultanément
<br>

push (pa, pb) :
- pa, pb : pousse le sommet de B vers A (pa) ou de A vers B (pb)
<br>

rotate (ra, rb, rr) : <br>
- ra, rb : fait remonter le sommet de A (ou B) en bas
- rr : ra et rb simultanément
<br>

reverse rotate (rra, rrb, rrr) : <br>
- rra, rrb : fait descendre le dernier élément de A (ou B) au sommet
- rrr	: rra et rrb simultanément
<br>

Algorithme utilisé dans ce projet : <br>
- On utilise un tri par Radix, pour gérer efficacement jusqu'à plusieurs centaines d’éléments (499 max).
- Le but est de convertir chaque index (0, 1, 2, …,) en sa représentation binaire, puis de trier bit par bit. <br>
0 → 000 <br>
1 → 001 <br>
2 → 010 <br>
3 → 011 <br>
4 → 100 

# Explications :
Calcul de max_bits
- Cherche le plus grand index (index_max) = size_a - 1

La boucle while ((index_max >> max_bits) != 0)
- Compte le nombre de bits nécessaires pour le représenter

Boucle externe sur les bits (while (++i < max_bits))
- Chaque itération traite un bit (bit 0, bit 1, …)

Boucle interne sur les éléments (while (++j < size)) <br>
Pour chaque élément :
- Décalage à droite de i et & 1 pour isoler le bit i-ème.
- Si le bit = 1 → rotate_a (on laisses l’élément dans A en le faisant passer en fin de pile).
- Si le bit = 0 → push_b (on envoies l’élément vers B).
- Une fois tous les éléments traités pour le bit courant, on récupères tous les éléments de B vers A, ce qui préserve l’ordre partiel obtenu.
- Après la dernière passe, la pile A est triée en ordre croissant.

Exemple :
- Si les valeurs initiales sont [40, 10, 30, 20], leur liste triée est [10, 20, 30, 40].
- On réétiquette : 10→0, 20→1, 30→2, 40→3.
- On travaille ensuite avec [3, 0, 2, 1] dans la pile A.
