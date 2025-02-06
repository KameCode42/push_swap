/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:52:32 by david             #+#    #+#             */
/*   Updated: 2025/02/03 19:40:36 by dle-fur          ###   ########.fr       */
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

	if (check_args(&stack, argc, argv) != 0)
		return (1);
	create_stack(&stack, argc, argv);
	printf("Stack A contents:\n");
    for (int i = 0; i < stack.size_a; i++) {
        printf("stack->a[%d] = %d\n", i, stack.a[i]);
	}
	create_index(&stack);
	int j = 0;
	printf("Stack A contents: ");
	while (j < stack.size_a)
	{
    	printf("%d ", stack.a[j]);
    	j++;
	}
	printf("\n");
	check_sort(&stack);
	sort(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
