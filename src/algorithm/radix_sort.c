/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/02/02 15:03:27 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stacks *stack)
{
	int	max;
	int	exp;
	int	digit;
	int	i;

	max = stack->size_a - 1;//trouve l index max
	exp = 1;
	while (max / exp > 0)//exemple max = 1 12 / 1 % = 2 11 / 10 % = 1 12 / 100 < 0 boucle s arrete
	{
		digit = -1;
		while (++digit < 10)//compare avec un digit de 0 > 9
		{
			i = stack->size_a + 1;
			while (--i > 0)
			{
				if ((stack->a[0] / exp) % 10 == digit)//on verfie si l extraction et le digit courant sont = si oui on push dans pile b
					push_b(stack);
				else
					rotate_a(stack);//sinon on rotate dans la pile a jusqu a trouver
			}
		}
		while (stack->size_b > 0)//on rempli la pile a trier
			push_a(stack);
		exp *= 10;
	}
}
