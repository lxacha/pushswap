/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:59:14 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/25 03:24:51 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	double	disorder;

	disorder = 0;
	if (!argv[1])
		return 0;
	list = from_args_to_list(argv);
	
	/*while (list != NULL)
	{
		printf("%d\n",list->number);
		list = list->next;
	}
	//printlist
	*/
	disorder = calculate_disorder(list);
}
