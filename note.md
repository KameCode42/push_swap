push_swap :
- Objectif : trier une pile A avec le moins d'action possible
- Algo utilise : radix avec des bits

Radix :
L’algorithme va traiter les bits du chiffre, en commençant par le bit le moins significatif (bit 0) et en allant jusqu’au bit le plus significatif nécessaire pour représenter le plus grand nombre (ici, 6 en binaire s’écrit 110 et nécessite 3 bits : positions 0, 1 et 2).

Les opérations utilisées sont:

L’idée générale est la suivante pour chaque bit (de 0 à 2):

	Parcourir l’ensemble des éléments de A.
	Pour chaque élément, extraire le bit d’intérêt avec l’expression ((x >> i) & 1):
		Si ce bit vaut 1, on effectue un rotate_a (l’élément reste dans A mais passe à la fin).
		S’il vaut 0, on fait un push_b (l’élément passe dans B).
	Une fois tous les éléments traités pour ce bit, on remet tous les éléments de B dans A avec push_a.

Liste initiale dans la pile A (le premier élément est le sommet) :
A = [6, 5, 3, 4, 2, 0, 1]
B = [ ] (vide)

Pour rappel, voici les représentations binaires (sur 3 bits) de nos nombres :

    6 → 110 (bit2 = 1, bit1 = 1, bit0 = 0)
    5 → 101 (bit2 = 1, bit1 = 0, bit0 = 1)
    3 → 011 (bit2 = 0, bit1 = 1, bit0 = 1)
    4 → 100 (bit2 = 1, bit1 = 0, bit0 = 0)
    2 → 010 (bit2 = 0, bit1 = 1, bit0 = 0)
    0 → 000 (tous les bits = 0)
    1 → 001 (bit2 = 0, bit1 = 0, bit0 = 1)


-------------------------------------------------------------------------------------------------------------

Utils :

- convet_number :
fonction qui permet de check si le nbr est un INT_MAX ou MIN ou si il contient des chiffres
variable end : permet de controler si des chiffres sont remplacer par des nombres

-------------------------------------------------------------------------------------------------------------

Error :

- check_number :
fonction qui permet de controler si notre nombre ne contient pas de chiffre

- check_duplicate :
fonction qui permet de controler si notre pile a ne contient pas de nombre identiques

- split_args :
fonction qui permet de split les nombres dans le cas d une entree comme "6 5 4 3 2"

- check_args :
fonction qui permet de checker les argument et qui regroupe plusieurs fonctions
si argc == 2 on utilise notre pile split 
si argc > 2 on utilise notre pile normal

-------------------------------------------------------------------------------------------------------------
Initiation :

- init_index
fonction qui permet de creer un index qui va se placer en fonction de la valeur du nombre
utilisation d'une variable count pour identifier les chiffre
si count = 3
le chiffre 4 sera identifier
exemple :
chiffre terminal : 4 3 2 1
index creer		 : 3 2 1 0

0 -> nombre plus petit
3 -> nombre le plus grand

-----------

-init_stack
create_stack :
permet d'allouer, de convertir et de remplir la pile a avec des valeurs sans ""

create_stack_split :
permet d'allouer, de convertir et de remplir la pile a avec des valeurs avec ""

-------------------------------------------------------------------------------------------------------------

Operation :

- push_a
prend le premier element en dessus de b et le met sur a
decale la pile a pour faire de la place
decale les nombres b vers le haut

- push_b
prend le premier element en dessus de a et le met sur b
decale la pile b pour faire de la place
decale les nombres a vers le haut

-----------

- swap_a
swap les deux premiers elements de la pile a

- swap_b
swap les deux premiers elements de la pile b

- swap_a_and_b
swap les deux premiers elements de la pile a et b en meme temps

-----------

- rotate_a
deplace tous les elements de la pile a vers le haut
le premier element devient le dernier

- rotate_b
deplace tous les elements de la pile b vers le haut
le premier element devient le dernier

- rotate_a_and_b
permet de faire un rotate_a et un rotate_b en meme temps

-----------

- reverse_rotate_a
deplace tous les elements de la pile a vers le bas
le dernier element devient le premier

- reverse_rotate_b
deplace tous les elements de la pile b vers le bas
le dernier element devient le premier

rrr_a_and_b
permet de faire un reverse_rotate_a et un reverse_rotate_b en meme temps

-------------------------------------------------------------------------------------------------------------

Algorithm :

- check_sort
fonction permet de savoir si la pile a est deja trier

- sort_two
fonction qui permet de trier 2 nombres dans la pile a

- sort_three :
fonction qui permet de trier 3 nombres dans pile a
si index 0 == 2		-> plus grand nombre
rotate -> premier nombre devient le dernier
si index 1 == 2		-> plus grand nombre
reverse_rotate -> dernier nombre devient le premier
si index 0 == 1		-> nombre du milieu
swap -> echange les 2 premiers elements de la pile

- sort_four
fonction qui permet de trier 4 nombres a l'aide de la pile b
tant que b est vide la boucle continue
si 3 est trouver (nombre le plus grand) la boucle s arrete car b == 1
si non on rotate jusqu a trouver
on passe la fonction sort_three
on push l'element qui se trouve dans la pile b dans la pile a
on rotate effectuer le trie final

- sort_five
fonction qui permet de trier 5 nombres a l'aide de la pile b
tant que la pile b ne contient pas deux elements la boucle continue
si index 0 == 3		-> deuxieme plus grand nombre
push dans la pile b
si index 0 == 4		-> plus grand nombre
push dans la pile b
on trie les 3 elements de a
push a 2 fois dans la pile a
si l index 0 == au plus grand nombre
swap
rotate pour le trie final

-----------

- radix_sort :
L’algorithme va traiter les bits du chiffre, en commençant par le bit le moins significatif (bit 0) et en allant jusqu’au bit le plus significatif nécessaire pour représenter le plus grand nombre

index_max = plus grand nombre de notre pile, si size = 5, plus grand index = 4
max_bits represente le nombre de passe que l'on va effectuer
exemple :
index_max = 6 en bits = 110, boucle : 110 - 011 - 001 donc 3 pass (pass0, pass1, pass2)

1er boucle : on parcours la colonne bit_0 ou pass_0
2eme boucle : on parcours les bit de bas en haut
exemple:
				1er boucle
					|
6 → 110 (bit2 = 1, bit1 = 1, bit0 = 0)
5 → 101 (bit2 = 1, bit1 = 0, bit0 = 1)
3 → 011 (bit2 = 0, bit1 = 1, bit0 = 1)	-- 2eme boucle
4 → 100 (bit2 = 1, bit1 = 0, bit0 = 0)
2 → 010 (bit2 = 0, bit1 = 1, bit0 = 0)

si le bit le plus a droite == 1, on rotate jusqu a trouver le premier bit 0
si le bit 0 es trouver il est push dans b

a la fin du bit_0 ou pass_0, la pile b contient tous les bits avec 0 et la pile a contient tous les bits avec 1
on push tous les elements de la pile b dans la pile a

on recommence avec le bit_1 ou pass_1 jusqu a ce que la pile a soit trier

-------------------------------------------------------------------------------------------------------------