/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:24:16 by dle-fur           #+#    #+#             */
/*   Updated: 2025/01/24 12:25:49 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stack)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	if (stack->size_a == 0 || stack->a[i] == 1)
		return ;
	if (stack->a[i] > stack->a[i + 1])
	{
		tmp = stack->a[i];
		stack->a[i] = stack->a[i + 1];
		stack->a[i + 1] = tmp;
	}
	ft_printf("sa\n");
}

void	swap_b(t_stacks *stack)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	if (stack->size_b == 0 || stack->b[i] == 1)
		return ;
	if (stack->b[i] > stack->b[i + 1])
	{
		tmp = stack->b[i];
		stack->b[i] = stack->b[i + 1];
		stack->b[i + 1] = tmp;
	}
	ft_printf("sb\n");
}

void	swap_a_and_b(t_stacks *stack)
{
	int	tmp;
	int	i;

	tmp = 0;
	i = 0;
	if ((stack->size_a == 0 || stack->a[i] == 1)
		|| (stack->size_b == 0 || stack->b[i] == 1))
		return ;
	if ((stack->a[i] > stack->a[i + 1]) && (stack->b[i] > stack->b[i + 1]))
	{
		tmp = stack->a[i];
		stack->a[i] = stack->a[i + 1];
		stack->a[i + 1] = tmp;
		tmp = stack->b[i];
		stack->b[i] = stack->b[i + 1];
		stack->b[i + 1] = tmp;
	}
	ft_printf("ss\n");
}
