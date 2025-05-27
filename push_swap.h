/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenriqu <ghenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:37:49 by ghenriqu          #+#    #+#             */
/*   Updated: 2025/05/22 18:26:36 by ghenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> //malloc, free
# include <unistd.h> //read, write, exit
# include <limits.h> //int_min, int_max

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}					t_stack;

// utils
int		is_sorted(t_stack *stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);

// input check
int		is_correct_input(char **argv);

// indexation
void	assign_index(t_stack *stack_a, int size);

// stack
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*fill_stack_values(int argc, char **argv);

// swap
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

// push
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);

// rotate
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

// reverse rotate
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

// tiny
void	sort_tiny(t_stack **stack);

#endif
