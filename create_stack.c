/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:37:59 by timbert           #+#    #+#             */
/*   Updated: 2026/11/26 18:09:59 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stack)
{
	t_node *node;

	node = stack->head;
	while (node)
	{
		stack->head = node->next;
		free (node);
		node = stack->head;
	}
	stack->tail = NULL;
	stack->size = 0;
}

t_node	*new_node(int nb, t_stack *stack)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
	{
		free_all(stack);
		return (NULL);
	}
	new->value = nb;
	new->rank = 1;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int	is_duplicate(t_stack *stack, t_node *new)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (new->value == node->value)
		{
			free_all(stack);
			return (1);
		}
		node = node->next;
	}
	return (0);
}
