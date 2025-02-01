/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 08:59:49 by david             #+#    #+#             */
/*   Updated: 2025/01/31 21:17:07 by dle-fur          ###   ########.fr       */
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

int	*init_radix(t_stacks *stack)
{
	int	*count; // Tableau count init à 0
	int	pass_max; // Nombre de passes à faire
	int	pass = 1; // Commence par le 1er pass
	int	power;
	int	digit;
	int	i;

	pass_max = count_pass(stack);
	count = malloc(pass_max * 10 * sizeof(int)); // Allouer dynamiquement
	if (!count)
		return (NULL); // Gestion d'erreur
	ft_memset(count, 0, 10 * sizeof(int)); // Init count à 0
	while (pass <= pass_max) // Boucle sur chaque passe
	{
		ft_memset(count + (10 * (pass - 1)), 0, 10 * sizeof(int));
		i = -1;
		power = ft_power(10, pass - 1); // Comme à l'index pass 0 qui est pass 1
		while (++i < stack->size_a) // Parcourt chaque élément de la pile A
		{
			digit = (stack->a[i] / power) % 10; // On extrait chaque chiffre
			count[digit + (10 * (pass - 1))]++;
		}
		pass++;
	}
	return (count); // Retourne le tableau alloué dynamiquement
}

//on fais tous cas de digit donc de 0 - 9
//ensuite on passe au pass suivant
void	push_to_b(t_stack *stack, int pass)
{
	int	*count;
	int	power;
	int	current;//contient le groupe avec les nombres
	int	digit;//chiffre qui sera compter de 0 a 9
	int	current_digit;//va contenir le chiffre qui a ete diviser unite dizaine etc

	count = init_radix(stack);
	power = ft_power(10, pass - 1);
	digit = 0;
	while (digit < 10)//on commence avec digit == 0 donc unite == 0
	{
		i = 0;
		while (i < count[digit + (10 * (pass - 1))])//on commence par les unite dans le pass 1
		{
			i++;
		}
		digit++;
	}
}

void	radix_sort(t_stacks *stack)