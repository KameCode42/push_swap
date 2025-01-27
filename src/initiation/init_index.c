/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:14:34 by dle-fur           #+#    #+#             */
/*   Updated: 2025/01/27 19:15:19 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//calcule la taille d un index en fontion du nombre de chiffre
void	create_index(t_stacks *stack)
{
	int	*index_a;
	int	i;
	int	j;
	int	count;

	i = -1;
	index_a = malloc(sizeof(int) * stack->size_a);
	if (index_a == NULL)
		free(stack);
	while (++i < stack->size_a)
	{
		count = 0;
		j = -1;
		while (++j < stack->size_a)
		{
			if (stack->a[i] > stack->a[j])
				count++;
		}
		index_a[i] = count;
	}
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = index_a[i];
	free(index_a);
}
