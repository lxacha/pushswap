/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 19:56:14 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 01:16:48 by timbert          ###   ########.fr       */
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

t_node	*pop_back(t_stack *stack);
t_node	*pop_front(t_stack *stack);
void	push_front(t_node *node, t_stack *stack);
void	push_back(t_node *node, t_stack *stack);
int		create_stack(int *tab, int size, t_stack *stack);

#endif