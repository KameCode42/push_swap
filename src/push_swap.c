/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:52:32 by david             #+#    #+#             */
/*   Updated: 2025/01/24 12:57:50 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (init_stack(&stack, argc, argv) != 0)
		return (1);
	swap_a(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
