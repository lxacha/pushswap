/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:56:14 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 22:38:20 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h> // A SUPPRIMER

typedef struct s_node
{
	int				value;
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
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int total;
}	t_count;

int		create_stack(int *tab, t_stack *stack, int size);
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
int		get_indice(t_node *node, t_stack *stack);
void	simple_algo(t_stack *stack_a, t_stack *stack_b);

#endif