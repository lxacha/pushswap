/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:59:14 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/25 21:38:15 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**list;
	double	disorder;

	disorder = 0;
	list = malloc(how_many_args(argv) * sizeof(t_node));
	if (!argv[1])
		return 0;
	(*list) = from_args_to_list(argv);	
	
	//printlist
	
	t_node	*tmp; 
	tmp = *list;  
	while (tmp)
	{
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
	//printlist
	
	disorder = calculate_disorder(*list);
	
	
	return (0);
}

