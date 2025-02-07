/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:25:04 by david             #+#    #+#             */
/*   Updated: 2025/02/07 10:36:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alloc_stack(t_stacks *stack, int argc)
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

void	create_stack(t_stacks *stack, int argc, char **argv)
{
	int	i;

	i = 0;
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

int	create_stack_split(t_stacks *stack, char **numbers, int size)
{
	stack->a = malloc(sizeof(int) * size);
	stack->b = malloc(sizeof(int) * size);
	if (stack->a == NULL || stack->b == NULL)
	{
		write(2, "Error\n", 6);
		free_split(numbers);
		return (1);
	}
	stack->size_a = size;
	stack->size_b = 0;
	while (--size >= 0)
		stack->a[size] = convert_number(numbers[size], NULL);
	free_split(numbers);
	return (0);
}
