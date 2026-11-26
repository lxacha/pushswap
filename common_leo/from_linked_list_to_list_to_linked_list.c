/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_linked_list_to_list_to_linked_list.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 03:40:33 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/26 04:23:07 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parse_disorder.h"

int	*linked_to_list(t_list **a, int nb_args)
{
	int	i;
	int	*list;
	t_list	*tmp;

	i = 0;
	tmp = (*a);
	list = malloc(nb_args * sizeof(int));
	while (tmp != NULL)
	{
		list[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (list);
}
