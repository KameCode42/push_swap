/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/02/07 10:36:25 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(int argc, char **argv)
{
	int		i;
	char	*end;

	i = 0;
	while (i < argc)
	{
		convert_number(argv[i], &end);
		if (*end != '\0')
		{
			write(2, "Error\n", 6);
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

	i = 0;
	while (i < argc)
	{
		nbr_i = convert_number(argv[i], NULL);
		j = i + 1;
		while (j < argc)
		{
			nbr_j = convert_number(argv[j], NULL);
			if (nbr_i == nbr_j)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	split_args(char **argv, t_stacks *stack)
{
	int		i;
	char	**numbers;
	int		result;

	numbers = ft_split(argv[1], ' ');
	if (numbers == NULL || numbers[0] == NULL)
	{
		write(2, "Error\n", 6);
		free_split(numbers);
		return (1);
	}
	i = 0;
	while (numbers[i] != NULL)
		i++;
	if (check_number(i, numbers) || check_duplicate(i, numbers))
	{
		free_split(numbers);
		exit (1);
	}
	result = create_stack_split(stack, numbers, i);
	return (result);
}

int	check_args(int argc, char **argv, t_stacks *stack)
{
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
	{
		if (split_args(argv, stack) == 0)
			return (0);
		else
		{
			create_stack(stack, argc, argv);
			return (0);
		}
	}
	else
	{
		if (check_number(argc - 1, argv + 1)
			|| check_duplicate(argc - 1, argv + 1))
			return (1);
		create_stack(stack, argc, argv);
		return (0);
	}
}
