/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:26:38 by timbert           #+#    #+#             */
/*   Updated: 2026/11/24 22:07:46 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_indice(t_node *node, t_stack *stack)
{
	int i;
	t_node *tmp;

	i = 1;
	tmp = stack->head;
	while (tmp->value != node->value)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
