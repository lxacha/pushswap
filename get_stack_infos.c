/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:39:07 by timbert           #+#    #+#             */
/*   Updated: 2026/11/28 12:51:04 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_node *node, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 1;
	tmp = stack->head;
	while (tmp->value != node->value)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	get_rank(t_stack *stack)
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

t_node	*get_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	node = stack->head;
	min = stack->head;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

t_node	*get_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	node = stack->head;
	max = stack->head;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

int	is_bottom(t_node *node, t_stack *stack)
{
	if (get_position(node, stack) > (stack->size / 2))
		return (1);
	return (0);
}

int	is_bottom_range(t_stack *stack, int min, int max)
{
	t_node	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	tmp = stack->head;
	while (tmp != NULL && tmp->rank <= min && tmp->rank >= max)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = stack->tail;
	while (tmp != NULL && tmp->rank <= min && tmp->rank >= max)
	{
		tmp = tmp->prev;
		j++;
	}
	if (j < i)
		return (1);
	else
		return (0);
}