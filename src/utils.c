/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:07:39 by david             #+#    #+#             */
/*   Updated: 2025/01/25 13:17:46 by david            ###   ########.fr       */
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
