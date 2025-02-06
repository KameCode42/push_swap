/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:52:32 by david             #+#    #+#             */
/*   Updated: 2025/02/06 15:54:52 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stacks *stack)
{
	if (stack->size_a == 2)
		sort_two(stack);
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a == 4)
		sort_four(stack);
	else if (stack->size_a == 5)
		sort_five(stack);
	else
		radix(stack);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (check_args(argc, argv, &stack) != 0)
		return (1);
	create_index(&stack);
	check_sort(&stack);
	sort(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
