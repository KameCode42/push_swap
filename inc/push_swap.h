/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:50:35 by david             #+#    #+#             */
/*   Updated: 2025/01/24 12:25:59 by dle-fur          ###   ########.fr       */
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
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stacks;

//utils
int		ft_atol(const char *str, char **end);

//check_error
int		check_number(int argc, char **argv);
int		check_duplicate(int argc, char **argv);
int		check_args(int argc, char **argv);

//swap
void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stacks);
void	swap_a_and_b(t_stacks *stack);

//init_stack
int		init_stack(t_stacks *stack, int argc, char **argv);

#endif