/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:59:14 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/24 22:21:29 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	index;
	int	index_list_ints;
	int	args;
	
	index = 1;
	index_list_ints = 1;
	args = 0;
	if (!argv[1])
		return 0;
	//printf("\n %d ",args = how_many_args(argv));
	args = how_many_args(argv);
	int	numbers[args];
	while (argv[index])
	{
		if (skip_shit(argv[index]) == TRUE)
		{
			index++;
			continue ;
		}
		numbers[index_list_ints] = ft_atoi(argv[index]);
		printf("%d \n",numbers[index]);
		index++;
		index_list_ints++;
	}

}
