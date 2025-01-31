/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:52:32 by david             #+#    #+#             */
/*   Updated: 2025/01/31 10:40:04 by david            ###   ########.fr       */
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
	{
		//radix
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (check_args(argc, argv) != 0)
		return (1);
	create_stack(&stack, argc, argv);
	create_index(&stack);
	check_sort(&stack);
	sort(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}


/*
int main(int argc, char **argv)
{
    t_stacks    stack;

    if (check_args(argc, argv) != 0)
        return (1);
    create_stack(&stack, argc, argv);
    create_index(&stack);
	check_sort(&stack);


    // Affiche la pile avant le tri
    //printf("Avant sort : ");
    //for (int i = 0; i < stack.size_a; i++)
        //printf("%d ", stack.a[i]);
    //printf("\n");

    sort_five(&stack);

    // Affiche la pile après le tri
    //printf("Après sort : ");
    //for (int i = 0; i < stack.size_a; i++)
        //printf("%d ", stack.a[i]);
    //printf("\n");

    free(stack.a);
    free(stack.b);
    return (0);
}
*/