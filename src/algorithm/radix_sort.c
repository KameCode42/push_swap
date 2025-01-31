/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/01/31 13:51:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rechercher le plus grand nombre du tableau
static int	max_value(t_stacks *stack)
{
	int	i;
	int	max_value;

	i = 0;
	max_value = stack->a[i];
	while (i < stack->size_a)
	{
		if (max_value < stack->a[i])
			max_value = stack->a[i];
		i++;
	}
	return (max_value);
}

//p contient le nombre de chiffres de nbr_max exemple 170 = 3 chiffre p = 3
//si le nombre suivant est 45, il est compter comme 045
static	int	count_pass(t_stacks *stack)
{
	int	p;
	int	nbr_max;

	p = 0;
	nbr_max = max_value(stack);
	while (nbr_max != 0)
	{
		nbr_max = nbr_max / 10;
		p += 1;
	}
	return (p);
}

void	radix_sort(t_stacks *stack)
{
	int	count[10];//tableau count init a 0
	int	pass_max;//nbr de passe a faire
	int	pass = 1;//commence par le 1er pass
	int	power;
	int	digit;
	int	i;

	ft_memset(count, 0, sizeof(count));//init count a 0
	pass_max = count_pass(stack);
	while (pass <= pass_max)
	{
		ft_memset(count, 0, sizeof(count));//a chaque pass on remet a 0
		i = 0;
		power = power(10, pass - 1);//comme a l index pass 0 qui est pass 1
		while (i < stack->size_a)
		{
			digit = (stack->a[i] / power) % 10;//on extrait chaque chiffre
			count[digit]++;
			i++;
		}
		pass++;
	}
}
