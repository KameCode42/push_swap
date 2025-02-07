/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/02/07 10:40:39 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stacks *stack)
{
	int	i;
	int	j;
	int	size;
	int	index_max;
	int	max_bits;

	index_max = stack->size_a - 1;
	max_bits = 0;
	while ((index_max >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		size = stack->size_a;
		while (++j < size)
		{
			if (((stack->a[0] >> i) & 1) == 1)
				rotate_a(stack);
			else
				push_b(stack);
		}
		while (stack->size_b > 0)
			push_a(stack);
	}
}
