/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:56:14 by timbert           #+#    #+#             */
/*   Updated: 2026/11/25 19:52:08 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h> // A SUPPRIMER

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef struct s_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_count;

typedef struct s_chunk
{
	int	size;
	int	range_min;
	int	range_max;
}	t_chunk;

int		create_stack(char **argv, t_stack *stack);
t_node	*pop_back(t_stack *stack);
t_node	*pop_front(t_stack *stack);
void	push_front(t_node *node, t_stack *stack);
void	push_back(t_node *node, t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	ra(t_stack *stack_a, int i);
void	rb(t_stack *stack_b, int i);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int i);
void	rrb(t_stack *stack_b, int i);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a, int i);
void	sb(t_stack *stack_b, int i);
void	ss(t_stack *stack_a, t_stack *stack_b);
int		get_position(t_node *node, t_stack *stack);
void	simple_algo(t_stack *stack_a, t_stack *stack_b);

int	ft_atoi(const char *nptr);
int	how_many_args(char **argv);
int	skip_shit(char *argv);
//t_list	*from_args_to_list(char **argv);
//void	append_to_node(t_list **cursor, int value);
//t_list	*create_node(int value);
//double	calculate_disorder(t_list *list);

#endif