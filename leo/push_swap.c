/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 20:59:14 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/24 20:42:43 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	skip_start(const char *nptr, int *neg)
{
	int		i;

	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*neg = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		y;
	long	converted;
	int		neg;

	neg = 1;
	y = 1;
	converted = 0;
	i = skip_start(nptr, &neg);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		converted = (converted * y) + nptr[i] - '0';
		y = 10;
		i++;
	}
	return ((int)(converted * neg));
}


int	how_many_args(char **argv)
{
	int	args = 0;
	while (argv[args])
		args++;
	args--;
	return (args);
}


int	main(int argc, char **argv)
{
	int	index;
	int	index_list_ints;
	int	args;
	
	index = 1;
	index_list_ints = 0;
	args = 0;
	if (!argv[1])
		return 0;
	//printf("\n %d ",args = how_many_args(argv));
	args = how_many_args(argv);
	char	number[args];
	while (argv[index])
	{
		while (argv[index] <= '9' && argv[index] >= '0')
		{
			numbers
			index_list_ints++;
			index++;
		}
		index++;
	}

}
