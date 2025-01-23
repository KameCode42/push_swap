/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:25:04 by david             #+#    #+#             */
/*   Updated: 2025/01/23 20:12:30 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	alloc_stack(t_stacks *stack, int argc)
{
	if (stack == NULL)
		return ;
	stack->size_a = argc - 1;
	stack->size_b = 0;
	stack->stack_a = malloc(sizeof(int) * stack->size_a);
	stack->stack_b = malloc(sizeof(int) * stack->size_a);
	if ((stack->stack_a == NULL) || (stack->stack_b == NULL))
	{
		free(stack->stack_a);
		free(stack->stack_b);
		return ;
	}
}

int	init_stack(t_stacks *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	if (stack == NULL)
		return (1);
	alloc_stack(stack, argc);
	if (check_args(argc, argv) != 0)
	{
		free(stack->stack_a);
		free(stack->stack_b);
		return (1);
	}
	while (i < stack->size_a)
	{
		stack->stack_a[i] = ft_atol(argv[i + 1], NULL);
		//ft_printf("%d\n", stack->stack_a[i]);
		i++;
	}
	return (0);
}
