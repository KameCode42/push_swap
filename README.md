![push_swap](https://github.com/user-attachments/assets/0964941e-bf0f-4fec-9e55-0276531e1aaa)

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
rotate (ra, rb, rr) :
- ra, rb : fait remonter le sommet de A (ou B) en bas
- rr : ra et rb simultanément
<br>
reverse rotate (rra, rrb, rrr) :
- rra, rrb : fait descendre le dernier élément de A (ou B) au sommet
- rrr	: rra et rrb simultanément
<br>
Algorithme utilisé :
- Pour gérer efficacement jusqu'à plusieurs centaines d’éléments, on utilise un tri par Radix adapté aux piles

# Explications :

