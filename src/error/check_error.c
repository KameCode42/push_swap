/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/02/06 19:31:20 by dle-fur          ###   ########.fr       */
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
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int split_args(char **argv, t_stacks *stack)
{
    int     i;
    int     j;
    char    **numbers;

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
    
    // Vérification des nombres et des doublons
    if (check_number(i, numbers) || check_duplicate(i, numbers))
    {
        free_split(numbers);
        exit (1);
    }

    /* Allocation du tableau d'entiers dans stack->a */
    stack->a = malloc(sizeof(int) * i);
	stack->b = malloc(sizeof(int) * i);
    if (!stack->a)
    {
        write(2, "Error\n", 6);
        free_split(numbers);
        return (1);
    }
	if (!stack->b)
    {
        write(2, "Error\n", 6);
        free_split(numbers);
        return (1);
    }
    stack->size_a = i; // si vous avez ce champ dans votre structure
	stack->size_b = 0;
    /* Conversion des chaînes en entiers et enregistrement dans stack->a */
    j = 0;
    while (j < i)
    {
        stack->a[j] = convert_number(numbers[j], NULL);  // ou atoi, en faisant attention aux débordements
        j++;
    }

    free_split(numbers);

    return (0);
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
			return 0;
		else
		{
			create_stack(stack, argc, argv);
			return 0;
		}
	}
	else
	{
		if (check_number(argc - 1, argv + 1) || check_duplicate(argc - 1, argv + 1))// pas de plus et de moins avant
			return (1);
		create_stack(stack, argc, argv);
		return 0;
	}
}
