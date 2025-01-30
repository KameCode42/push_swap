/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:59:22 by david             #+#    #+#             */
/*   Updated: 2025/01/30 10:18:55 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stack)
{
	int	i;
	int	tmp;

	tmp = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = tmp;
	ft_printf("ra\n");
}

void	rotate_b(t_stacks *stack)
{
	int	i;
	int	tmp;

	tmp = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = tmp;
	ft_printf("rb\n");
}

void	rotate_a_and_b(t_stacks *stack)
{
	int	i;
	int	j;
	int	tmp_a;
	int	tmp_b;

	i = 0;
	j = 0;
	tmp_a = stack->a[0];
	tmp_b = stack->b[0];
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	while (j < stack->size_b - 1)
	{
		stack->b[j] = stack->b[j + 1];
		j++;
	}
	stack->a[stack->size_a - 1] = tmp_a;
	stack->b[stack->size_b - 1] = tmp_b;
	ft_printf("rr\n");
}
