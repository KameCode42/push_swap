/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:50:35 by david             #+#    #+#             */
/*   Updated: 2025/01/23 18:52:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libraries/libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}		t_stacks;

//utils
int	ft_atol(const char *str, char **end);

//check_error
int	check_number(int argc, char **argv);
int	check_duplicate(int argc, char **argv);
int	check_args(int argc, char **argv);

//init_stack
int	init_stack(t_stacks *stack, int argc, char **argv);

#endif