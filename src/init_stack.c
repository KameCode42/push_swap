/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:25:04 by david             #+#    #+#             */
/*   Updated: 2025/01/26 16:51:05 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction qui permet d allouer les stack a et b
static int	alloc_stack(t_stacks *stack, int argc)
{
	if (stack == NULL)
		return (1);
	stack->size_a = argc - 1;
	stack->size_b = 0;
	stack->a = malloc(sizeof(int) * stack->size_a);
	stack->b = malloc(sizeof(int) * stack->size_a);
	if ((stack->a == NULL) || (stack->b == NULL))
	{
		free(stack->a);
		free(stack->b);
		return (1);
	}
	return (0);
}

//fonction qui permet de remplir la stack a
void	init_stack(t_stacks *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	if (stack == NULL)
		exit(1);
	if (alloc_stack(stack, argc) != 0)
	{
		free(stack);
		exit(1);
	}
	while (i < stack->size_a)
	{
		stack->a[i] = convert_number(argv[i + 1], NULL);
		i++;
	}
}
