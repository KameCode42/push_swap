/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:50:35 by david             #+#    #+#             */
/*   Updated: 2025/01/27 19:30:01 by dle-fur          ###   ########.fr       */
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
void	sort_two(t_stacks *stack);
void	sort_three(t_stacks *stack);
void	sort_four(t_stacks *stack);

/*----------------------------------------------------------------------------*/

//utils
int		convert_number(const char *str, char **end);
void	check_sort(t_stacks *stack);

//error
int		check_number(int argc, char **argv);
int		check_duplicate(int argc, char **argv);
int		check_args(int argc, char **argv);

//initiation
void	create_stack(t_stacks *stack, int argc, char **argv);
void	create_index(t_stacks *stack);

#endif