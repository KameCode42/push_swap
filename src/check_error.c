/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/01/23 13:40:51 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(int argc, char **argv)
{
	int		i;
	long	nbr;
	char	*end;

	i = 1;
	while (i < argc)
	{
		nbr = strtol(argv[i], &end, 10);
		if (*end != '\0')
		{
			ft_printf("Error : invalid number\n");
			return (1);
		}
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_printf("Error : the number does not fit into an integer\n");
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
		nbr_i = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			nbr_j = ft_atoi(argv[j]);
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

	i = 1;
	if (argc < 2)
	{
		ft_printf("Error : invalid argument number\n");
		return (1);
	}
	else if (argc == 2)
	{
		ft_printf("Error : no numbers to sort\n");
		return (1);
	}
	while (i < argc)
	{
		if (check_number(argc, argv))
			return (1);
		if (check_duplicate(argc, argv))
			return (1);
		i++;
	}
	return (0);
}
