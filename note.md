push_swap :
- Objectif : trier une pile A avec le moins d'action possible
- Algo utilise : radix

Radix
- algo qui permet de trier des nombres par leur dizaine
- si le case du nombre a comparer est vide, on met un 0
exemple :


//n-s			//trie1			//trie2			//sort
170		->		170		->		802		->		  2
 45		->		 90		->		  2		->		 24
 75		->		802		->		 24		->		 45
 90		->		  2		->		 45		->		 66
802		->		 24		->		 66		->		 75
 24		->		 45		->		170		->		 90
  2		->		 75		->		 75		->		170
 66		->		 66		->		 90		-> 		802


-------------------------------------------------------------------------------------------------------------

Utils :

- convet_number :
fonction qui permet de check si le nbr est un INT_MAX ou MIN
convertit les nombres qui sont en str en int
variable end : permet de controler si des chiffres sont remplacer par des nombres

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
permet d'allouer, de convertir et de remplir la pile a

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

-------------------------------------------------------------------------------------------------------------