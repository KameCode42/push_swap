/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/02/06 14:40:26 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(int argc, char **argv)
{
	int		i;
	char	*end;

	i = 0;// 1 avant
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

	i = 0;// 1 avant
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

int	split_args(char **argv)
{
	int		i;
	char	**numbers;

	numbers = ft_split(argv[1], ' ');
	if (numbers == NULL || numbers[0] == NULL)
	{
		ft_printf("Error : invalid argument number\n");
		free_split(numbers);
		return (1);
	}
	i = 0;
	while (numbers[i] != NULL)
		i++;
	if (check_number(i, numbers) || check_duplicate(i, numbers))
	{
		free_split(numbers);
		return (1);
	}
	free_split(numbers);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error : invalid argument number\n");
		return (1);
	}
	if (argc == 2)
	{
		if (split_args(argv) != 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (check_number(argc - 1, argv + 1) || check_duplicate(argc - 1, argv + 1))// pas de plus et de moins avant
			return (1);
		return (0);
	}
}


/*
int	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error : invalid argument number\n");
		return (1);
	}
	if (check_number(argc, argv) || check_duplicate(argc, argv))
		return (1);
	
	return (0);
}
*/