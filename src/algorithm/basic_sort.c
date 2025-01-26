/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:38:46 by david             #+#    #+#             */
/*   Updated: 2025/01/26 17:22:53 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stack)
{
	if (stack->a[0] > stack->a[1])
		swap_a(stack);
}

void	sort_three(t_stacks *stack)
{
	if (stack->a[0] == 2)
		rotate_a(stack);
	if (stack->a[1] == 2)
		reverse_rotate_a(stack);
	if (stack->a[0] == 1)
		swap_a(stack);
}
