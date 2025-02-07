/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:50:35 by david             #+#    #+#             */
/*   Updated: 2025/02/07 10:31:13 by david            ###   ########.fr       */
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

/***************************/
/*        OPERATION        */
/***************************/
//swap
void	swap_a(t_stacks *stack);
void	swap_b(t_stacks *stacks);
void	swap_a_and_b(t_stacks *stack);

//push
void	push_a(t_stacks *stack);
void	push_b(t_stacks *stack);

//rotate
void	rotate_a(t_stacks *stack);
void	rotate_b(t_stacks *stack);
void	rotate_a_and_b(t_stacks *stack);

//reverse_rotate
void	reverse_rotate_a(t_stacks *stack);
void	reverse_rotate_b(t_stacks *stack);
void	rrr_a_and_b(t_stacks *stack);

/*----------------------------------------------------------------------------*/

/***************************/
/*        ALGORITHM        */
/***************************/

//basic_sort
void	check_sort(t_stacks *stack);
void	sort_two(t_stacks *stack);
void	sort_three(t_stacks *stack);
void	sort_four(t_stacks *stack);
void	sort_five(t_stacks *stack);

//radix_sort
void	radix(t_stacks *stack);

/*----------------------------------------------------------------------------*/

//utils
int		convert_number(const char *str, char **end);
int		ft_power(int base, int exposant);
void	free_split(char **str);

//error
int		check_number(int argc, char **argv);
int		check_duplicate(int argc, char **argv);
int		split_args(char **argv, t_stacks *stack);
int		check_args(int argc, char **argv, t_stacks *stack);

//initiation
int		alloc_stack(t_stacks *stack, int argc);
void	create_stack(t_stacks *stack, int argc, char **argv);
int		create_stack_split(t_stacks *stack, char **numbers, int size);
void	create_index(t_stacks *stack);

//push_swap
void	sort(t_stacks *stack);

#endif