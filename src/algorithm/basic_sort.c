/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:38:46 by david             #+#    #+#             */
/*   Updated: 2025/02/03 19:05:49 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sort(t_stacks *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		printf("Comparing stack->a[%d] = %d and stack->a[%d] = %d\n", i, stack->a[i], i + 1, stack->a[i + 1]);
		if (stack->a[i] > stack->a[i + 1])
		{
			 printf("Array is NOT sorted! Exiting check_sort...\n");
			 return ;
		}
		i++;
	}
	ft_printf("stack sorted\n");
	free(stack->a);
	free(stack->b);
	exit (1);
}

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

void	sort_five(t_stacks *stack)
{
	while (stack->size_b <= 1)
	{
		if (stack->a[0] == 3 || stack->a[0] == 4)
			push_b(stack);
		else
			rotate_a(stack);
	}
	sort_three(stack);
	push_a(stack);
	push_a(stack);
	if (stack->a[0] == 4)
		swap_a(stack);
	rotate_a(stack);
	rotate_a(stack);
}
