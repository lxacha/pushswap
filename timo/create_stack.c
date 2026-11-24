/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:37:59 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 01:31:37 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*new_node(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = nb;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

static int	is_duplicate(t_stack *stack, t_node *new)
{
	t_node	*node;

	node = stack->head;
	while (node)
	{
		if (new->value == node->value)
			return (1);
		node = node->next;
	}
	return (0);
}

int	create_stack(int *tab, int size, t_stack *stack)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < size)
	{
		new = new_node(tab[i]);
		if (is_duplicate(stack, new))
		{
			printf("Error\n");
			return (0);
		}
		push_back(new, stack);
		i++;
	}
	return (1);
}
