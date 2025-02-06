/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/02/06 21:14:38 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix(t_stacks *stack)
{
	int i;
	int	j;
	int	size;
	int	index_max = stack->size_a - 1;
	int	max_bits = 0;

	while ((index_max >> max_bits) != 0)//juste pour calcuer le nombre de pass
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = stack->size_a; // Nombre d'éléments à traiter pour cette passe
		while (j < size)// Pour chaque élément de la pile A
		{
			if (((stack->a[0] >> i) & 1) == 1)// Si le bit i de l'élément en tête vaut 1, on le rotate dans A, sinon on le pousse dans B.
				rotate_a(stack);
			else
				push_b(stack);
			j++;
		}
		while (stack->size_b > 0)
			push_a(stack);
		i++;
	}
}
