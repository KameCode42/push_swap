/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/02/06 18:27:39 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	radix(t_stacks *stack)
{
	int	max;
	int	exp;
	int	digit;
	int	i;

	max = stack->size_a - 1;//trouve l index max
	exp = 1;
	while (max / exp > 0)//exemple max = 1 12 / 1 % = 2 11 / 10 % = 1 12 / 100 < 0 boucle s arrete
	{
		digit = -1;
		while (++digit < 10)//compare avec un digit de 0 > 9
		{
			i = stack->size_a + 1;
			while (--i > 0)
			{
				if ((stack->a[0] / exp) % 10 == digit)//on verfie si l extraction et le digit courant sont = si oui on push dans pile b
					push_b(stack);
				else
					rotate_a(stack);//sinon on rotate dans la pile a jusqu a trouver
			}
		}
		while (stack->size_b > 0)//on rempli la pile a trier
			push_a(stack);
		exp *= 10;
	}
}
*/

void radix(t_stacks *stack)
{
    int i, j;
    int max = stack->size_a - 1; // Puisque la pile est normalisée, max == n - 1
    int max_bits = 0;

    // Calcul du nombre de bits nécessaires
    while ((max >> max_bits) != 0)//juste pour calcuer le nombre de pass
        max_bits++;

    // Pour chaque bit
    for (i = 0; i < max_bits; i++)
    {
        int size = stack->size_a; // Nombre d'éléments à traiter pour cette passe

        // Pour chaque élément de la pile A
        for (j = 0; j < size; j++)
        {
            // Si le bit i de l'élément en tête vaut 1, on le rotate dans A,
            // sinon on le pousse dans B.
            if (((stack->a[0] >> i) & 1) == 1)
                rotate_a(stack);
            else
                push_b(stack);
        }
        // On remet tous les éléments de B dans A
        while (stack->size_b > 0)
            push_a(stack);
    }
}
