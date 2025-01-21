/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/01/21 19:27:12 by dle-fur          ###   ########.fr       */
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
		i++;
	}
	return (0);
}
