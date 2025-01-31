/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/01/31 10:40:27 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rechercher le plus grand nombre du tableau
static int	max_value(t_stacks *stack)
{
	int	i;
	int	max_value;

	i = 0;
	max_value = stack->a[i];
	while (i < stack->size_a)
	{
		if (max_value < stack->a[i])
			max_value = stack->a[i];
		i++;
	}
	return (max_value);
}

//p contient le nombre de chiffres de nbr_max exemple 170 = 3 chiffre p = 3
//si le nombre suivant est 45, il est compter comme 045
static	int	count_pass(t_stacks *stack)
{
	int	p;
	int	nbr_max;

	p = 0;
	nbr_max = max_value(stack);
	while (nbr_max != 0)
	{
		nbr_max = nbr_max / 10;
		p += 1;
	}
	return (p);
}

void	radix_sort(t_stacks *stack)
{
	int	count[10];

	count = 0;
}
