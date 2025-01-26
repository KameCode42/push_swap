/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:07:39 by david             #+#    #+#             */
/*   Updated: 2025/01/26 16:46:02 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_space_and_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -(*sign);
		i++;
	}
	return (i);
}

//fonction qui permet de check si le nbr est un INT_MAX ou MIN
//convertit les nombres qui sont en str en int
int	convert_number(const char *str, char **end)
{
	int	i;
	int	sign;
	int	result;

	i = skip_space_and_sign(str, &sign);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (INT_MAX - (str[i] - 48)) / 10)
		{
			if (end != NULL)
				*end = (char *)&str[i];
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (end != NULL)
		*end = (char *)&str[i];
	return (result * sign);
}

void	init_index(t_stacks *stack)
{
	int	*index_a;
	int	i;
	int	j;
	int	count;

	i = -1;
	index_a = malloc(sizeof(int) * stack->size_a);
	if (index_a == NULL)
		free(stack);
	while (++i < stack->size_a)
	{
		count = 0;
		j = -1;
		while (++j < stack->size_a)
		{
			if (stack->a[i] > stack->a[j])
				count++;
		}
		index_a[i] = count;
	}
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = index_a[i];
	free(index_a);
}
