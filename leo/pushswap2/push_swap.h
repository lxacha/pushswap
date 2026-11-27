/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:56:14 by timbert           #+#    #+#             */
/*   Updated: 2026/11/27 20:15:09 by leolefeb         ###   ########.fr       */
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

//int		create_stack(char **argv, t_stack *stack);
t_node		*pop_back(t_stack *stack);
t_node		*pop_front(t_stack *stack);
void		push_front(t_node *node, t_stack *stack);
void		push_back(t_node *node, t_stack *stack);
void		pa(t_stack *stack_b, t_stack *stack_a, t_count *count);
void		pb(t_stack *stack_a, t_stack *stack_b, t_count *count);
void		ra(t_stack *stack_a, int i, t_count *count);
void		rb(t_stack *stack_b, int i, t_count *count);
void		rr(t_stack *stack_a, t_stack *stack_b, t_count *count);
void		rra(t_stack *stack_a, int i, t_count *count);
void		rrb(t_stack *stack_b, int i, t_count *count);
void		rrr(t_stack *stack_a, t_stack *stack_b, t_count *count);
void		sa(t_stack *stack_a, int i, t_count *count);
void		sb(t_stack *stack_b, int i, t_count *count);
void		ss(t_stack *stack_a, t_stack *stack_b, t_count *count);
void		free_all(t_stack *stack);
t_node		*new_node(int nb, t_stack *stack);
int			is_duplicate(t_stack *stack, t_node *new);
int			get_position(t_node *node, t_stack *stack);
void		get_rank(t_stack *stack);
t_node		*get_min(t_stack *stack);
t_node		*get_max(t_stack *stack);
int			is_bottom(t_node *min, t_stack *stack);
void		calcul_total_ops(t_count *count);
void		simple_algo(t_stack *stack_a, t_stack *stack_b, t_count *count);
void		butterfly(t_stack *stack_a, t_stack *stack_b, t_count *count);

int		is_there_duplicates(t_stack *stack_a);
long long	ft_atoi(const char *nptr);
int			how_many_args(char **argv);
int			skip_shit(char *argv);
int			how_many_args(char **argv);
int			ft_strlen(char *a);
int			atoi_stop(const char *a);
char		*re_process(char *a);
void		from_args_to_list(char **argv, t_stack *stack);

void		error(char *a);
// double	calculate_disorder(t_list *list);

// int	*linked_to_list(t_list **a, int nb_args);
// t_list	*from_args_to_list(char **argv);
// void	append_to_node(t_list **cursor, int value);
// t_list	*create_node(int value);

#endif
