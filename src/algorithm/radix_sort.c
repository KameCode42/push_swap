/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/02/02 14:21:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stacks *stack)
{
	int	max;
	int	exp;
	int	digit;
	int	i;
	int	current;
	int	current_digit;
	int original_size;

	max = max_value(stack);//trouve l index max
	exp = 1;
	printf("Max value: %d\n", max);
	while (max / exp > 0)//exemple max = 1 12 / 1 % = 2 11 / 10 % = 1 12 / 100 < 0 boucle s arrete
	{
		printf("\n---- Processing exp = %d ----\n", exp);
		digit = 0;
		while (digit < 10)//compare avec un digit de 0 > 9
		{
			printf("Checking digit: %d\n", digit);
			original_size = stack->size_a;// permet de garder la taille originale de la pile a
			i = 0;
			while (i < original_size)
			{
				current = stack->a[0];// on cheeck toujours l index 0
				current_digit = (current / exp) % 10;//on extrait le modulo de l index
				printf("stack->a[%d] = %d -> Extracted digit: %d\n", i, stack->a[i], digit);
				if (current_digit == digit)//on verfie si l extraction et le digit courant sont = si oui on push dans pile b
				{
					printf("Pushing %d to B\n", stack->a[i]);
					push_b(stack);
				}
				else
				{
					printf("Rotating A\n");
					rotate_a(stack);//sinon on rotate dans la pile a jusqu a trouver
				}
				i++;
			}
			while (stack->size_b > 0)//on rempli la pile a trier
			{
				push_a(stack);
			}
			digit++;
		}
		exp *= 10;
	}
	printf("\n✅ Final sorted stack->a: ");
	for (i = 0; i < stack->size_a; i++)
		printf("%d ", stack->a[i]);
	printf("\n");
}
