/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:52:32 by david             #+#    #+#             */
/*   Updated: 2025/01/26 18:26:05 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (check_args(argc, argv) != 0)
		return (1);
	init_stack(&stack, argc, argv);
	init_index(&stack);
	//check sort
	sort_three(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
*/

int main(int argc, char **argv)
{
    t_stacks    stack;

    if (check_args(argc, argv) != 0)
        return (1);
    init_stack(&stack, argc, argv);
    init_index(&stack);


    // Affiche la pile avant le tri
    //printf("Avant sort : ");
    //for (int i = 0; i < stack.size_a; i++)
        //printf("%d ", stack.a[i]);
    //printf("\n");

    sort_four(&stack);

    // Affiche la pile après le tri
    //printf("Après sort : ");
    //for (int i = 0; i < stack.size_a; i++)
        //printf("%d ", stack.a[i]);
    //printf("\n");

    free(stack.a);
    free(stack.b);
    return (0);
}