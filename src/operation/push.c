/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:31:08 by dle-fur           #+#    #+#             */
/*   Updated: 2025/01/25 10:09:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//prend le premier element en dessus de b et le met sur a
void	push_a(t_stacks *stack)
{
	int	i;
	int	tmp;

	tmp = stack->b[0];
	i = stack->size_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1]; //decale la pile a pour faire de la place
		i--;
	}
	stack->a[0] = tmp;
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1]; //decale les nbr vers le haut
		i++;
	}
	stack->size_b--;
	stack->size_a++;
	ft_printf("pa\n");
}

//prend le premier element en dessus de a et le met sur b
void	push_b(t_stacks *stack)
{
	int	i;
	int	tmp;

	tmp = stack->a[0];
	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1]; //decale la pile b pour faire de la place
		i--;
	}
	stack->b[0] = tmp;
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1]; // decale les nbr vers le haut
		i++;
	}
	stack->size_a--;
	stack->size_b++;
	ft_printf("pb\n");
}
