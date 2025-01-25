/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/01/25 13:18:34 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction qui permet de check si un nbr est valide
//exemple 123abc ou 12bchd2 = non valide
int	check_number(int argc, char **argv)
{
	int		i;
	char	*end;

	i = 1;
	while (i < argc)
	{
		convert_number(argv[i], &end);
		if (*end != '\0')
		{
			ft_printf("Error : invalid number: %s\n", argv[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

//fonction qui check si il n y a pas de doublon
int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;
	int	nbr_i;
	int	nbr_j;

	i = 1;
	while (i < argc)
	{
		nbr_i = convert_number(argv[i], NULL);
		j = i + 1;
		while (j < argc)
		{
			nbr_j = convert_number(argv[j], NULL);
			if (nbr_i == nbr_j)
			{
				ft_printf("Error : duplicate detected\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

//fonction qui check les argument et inclus les fonctions
//check_number et check_dup
int	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error : invalid argument number\n");
		return (1);
	}
	if (argc == 2)
	{
		ft_printf("Error : no numbers to sort\n");
		return (1);
	}
	if ((check_number(argc, argv)) || (check_duplicate(argc, argv)))
		return (1);
	return (0);
}
