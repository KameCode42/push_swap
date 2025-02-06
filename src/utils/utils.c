/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:07:39 by david             #+#    #+#             */
/*   Updated: 2025/02/06 22:28:02 by david            ###   ########.fr       */
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
		if (str[i + 1] == '\0' || (str[i + 1] == ' '))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (str[i] == '-')
			*sign = -(*sign);
		i++;
	}
	return (i);
}

int	convert_number(const char *str, char **end)
{
	int			i;
	int			sign;
	long long	result;

	i = skip_space_and_sign(str, &sign);
	if (i == -1)
		return (1);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		{
			if (end != NULL)
				*end = (char *)&str[i];
			return (1);
		}
		i++;
	}
	if (end != NULL)
		*end = (char *)&str[i];

	return ((int)(result * sign));
}

int	ft_power(int base, int exposant)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i < exposant)
	{
		result = result * base;
		i++;
	}
	return (result);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
