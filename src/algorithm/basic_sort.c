/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:38:46 by david             #+#    #+#             */
/*   Updated: 2025/01/27 19:32:22 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stack)
{
	if (stack->a[0] > stack->a[1])
		swap_a(stack);
}

void	sort_three(t_stacks *stack)
{
	if (stack->a[0] == 2)
		rotate_a(stack);
	if (stack->a[1] == 2)
		reverse_rotate_a(stack);
	if (stack->a[0] == 1)
		swap_a(stack);
}

void	sort_four(t_stacks *stack)
{
	while (stack->size_b == 0)
	{
		if (stack->a[0] == 3)
			push_b(stack);
		else
			rotate_a(stack);
	}
	sort_three(stack);
	push_a(stack);
	rotate_a(stack);
}

//5

//6+ == radix algo