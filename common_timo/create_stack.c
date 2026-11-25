/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:37:59 by timbert           #+#    #+#             */
/*   Updated: 2026/11/25 20:45:49 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(t_stack *stack)
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

static t_node	*new_node(int nb, t_stack *stack)
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

static int	is_duplicate(t_stack *stack, t_node *new)
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

static void	get_rank(t_stack *stack)
{
	t_node	*node;
	t_node	*cmp;

	cmp = stack->head;
	node = stack->head;
	while (node)
	{
		while (cmp)
		{
			if (cmp->value < node->value)
				node->rank++;
			cmp = cmp->next;
		}
		cmp = stack->head;
		node = node->next;
	}
}

int	create_stack(char **argv, t_stack *stack)
{
	t_node	*new;
	int		index;

	index = 1;
	while (argv[index])
	{
		if (skip_shit(argv[index]) == TRUE)
		{
			index++;
			continue ;
		}
		new = new_node(ft_atoi(argv[index]), stack);
		if (is_duplicate(stack, new))
		{
			printf("Error\n");
			return (0);
		}
		push_back(new, stack);
		index++;
	}
	get_rank(stack);
	return (1);
}
