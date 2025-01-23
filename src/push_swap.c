/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:52:32 by david             #+#    #+#             */
/*   Updated: 2025/01/23 20:14:39 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (init_stack(&stack, argc, argv) != 0)
		return (1);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
