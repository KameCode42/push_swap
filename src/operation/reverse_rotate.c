/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:17:26 by david             #+#    #+#             */
/*   Updated: 2025/01/25 12:11:50 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//deplace tous les elements de la pile a
//le dernier element devient le premier
void	reverse_rotate_a(t_stacks *stack)
{
	int	i;
	int	tmp;

	tmp = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	ft_printf("rra\n");
}

//deplace tous les elements de la pile b
//le dernier element devient le premier
void	reverse_rotate_b(t_stacks *stack)
{
	int	i;
	int	tmp;

	tmp = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];//decale les element vers le bas
		i--;
	}
	stack->b[0] = tmp;
	ft_printf("rrb\n");
}

void	rrr_a_and_b(t_stacks * stack)
{
	int	i;
	int	j;
	int	tmp_a;
	int	tmp_b;

	i = stack->size_a - 1;
	j = stack->size_b - 1;
	tmp_a = stack->a[stack->size_a - 1];
	tmp_b = stack->b[stack->size_b - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	while (j > 0)
	{
		stack->b[j] = stack->b[j - 1];
		j--;
	}
	stack->a[0] = tmp_a;
	stack->b[0] = tmp_b;
	ft_printf("rrr\n");
}
