/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:19:43 by david             #+#    #+#             */
/*   Updated: 2025/02/03 19:24:17 by dle-fur          ###   ########.fr       */
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
/*
int	check_args(t_stacks *stack, int argc, char **argv)
{
	int		i;
	char	**numbers;

	if (argc < 2)
	{
		ft_printf("Error : invalid argument number\n");
		return (1);
	}
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (numbers == NULL || numbers[0] == NULL)
		{
			ft_printf("Error : invalid argument number\n");
			free_split(numbers);
			return (1);
		}
		i = 0;
		while (numbers[i] != NULL)
		{
			printf("numbers[%d] = %s\n", i, numbers[i]);
			i++;
		}
		stack->size_a = i; // Mettre la bonne taille !
		if (check_number(i, numbers) || check_duplicate(i, numbers))
		{
			free_split(numbers);
			return (1);
		}
		return (0);
	}
	else
	{
		if (check_number(argc, argv) || check_duplicate(argc, argv))
			return (1);
		return (0);
	}
}
*/
int check_args(t_stacks *stack, int argc, char **argv)
{
    int i;
    char **numbers;

    if (argc < 2)
    {
        ft_printf("Error: invalid argument number\n");
        return (1);
    }

    // Si argc == 2, il faut diviser le seul argument (les nombres séparés par des espaces)
    if (argc == 2)
    {
        numbers = ft_split(argv[1], ' ');  // Séparer les nombres dans argv[1]
        if (numbers == NULL || numbers[0] == NULL)  // Vérifier l'échec de split
        {
            ft_printf("Error: invalid argument number\n");
            free_split(numbers);  // Libérer la mémoire de numbers
            return (1);
        }

        // Compter le nombre d'éléments séparés
        i = 0;
        while (numbers[i] != NULL)
        {
            printf("numbers[%d] = %s\n", i, numbers[i]);  // Vérification de l'élément
            i++;
        }

        stack->size_a = i;  // Définir correctement la taille de la pile A
        printf("stack->size_a = %d\n", stack->size_a);  // Vérifier la taille de stack->size_a

        // Vérifier les nombres et les doublons
        if (check_number(i, numbers) || check_duplicate(i, numbers))
        {
            free_split(numbers);  // Libérer la mémoire de numbers
            return (1);
        }

        // Libérer la mémoire de numbers après l'utilisation
        free_split(numbers);
        return (0);  // Les arguments sont corrects
    }
    else
    {
        // Si argc > 2, vérifier les nombres et doublons pour chaque argument
        if (check_number(argc, argv) || check_duplicate(argc, argv))
            return (1);
        return (0);
    }
}
