/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:37:29 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 14:24:11 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop_back(t_stack *stack)
{
	t_node *node;
	
	if (!stack || !stack->tail)
		return (NULL);
	node = stack->tail;
	stack->tail = node->prev;
	if (stack->tail)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

t_node	*pop_front(t_stack *stack)
{
	t_node *node;
	
	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

void	push_back(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return ;
	node->prev = stack->tail;
	if (stack->tail)
		stack->tail->next = node;
	else
		stack->head = node;
	stack->tail = node;
	stack->size++;
}

void	push_front(t_node *node, t_stack *stack)
{
	if (!stack || !node)
		return ;
	node->next = stack->head;
	if (stack->head)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->head = node;
	stack->size++;
}
