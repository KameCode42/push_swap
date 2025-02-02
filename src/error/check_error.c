/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/02/02 16:14:30 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
	{
		ft_printf("Error : invalid argument number\n");
		return (1);
	}
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == ' ')
				return (0);
		}
		ft_printf("Error : no numbers to sort\n");
		return (1);
	}
	if ((check_number(argc, argv)) || (check_duplicate(argc, argv)))
		return (1);
	return (0);
}
