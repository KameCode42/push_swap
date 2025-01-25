/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:38:46 by david             #+#    #+#             */
/*   Updated: 2025/01/25 14:17:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_two(t_stacks *stack)
{
	if (stack == NULL || stack->a == NULL)
		return (1);
	if (stack->size_a == 0 || stack->size_a == 1)
		return (1);
	else if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
		else
			ft_printf("The stack is already sorted\n");
	}
	return (0);
}

int	sort_three(t_stacks *stack)
{
	if (stack == NULL || stack->a == NULL)
		return (1);
	if (stack->size_a == 0 || stack->size_a == 1)
		return (1);
	else if (stack->size_a == 3)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
		if (stack->a[1] > stack->a[2])
			swap_a(stack);
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
		else
			ft_printf("The stack is already sorted\n");
	}
	return (0);
}
