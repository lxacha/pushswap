/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolefeb <leolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:10:21 by leolefeb          #+#    #+#             */
/*   Updated: 2026/11/25 00:24:57 by leolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

int	skip_shit(char *argv)
{
	int	true_or_nah;
	int	index;

	index = 0;
	true_or_nah = TRUE;
	while(argv[index])
	{
		if (argv[index] >= '0' && argv[index] <= '9')
			return (FALSE);
		if (argv[index] == '+' || argv[index] == '-' || argv[index] == ' ' || (argv[index] >= 9 && argv[index] <= 13))
		{
			index++;	
			continue ;
		}
		else
			return (TRUE);

	}

}

int	how_many_args(char **argv)
{
	int	args;
	int	number_of_valid_args;
	
	args = 1;
	number_of_valid_args = 0;
	while (argv[args])
	{
		if (skip_shit(argv[args]) == FALSE)
			number_of_valid_args++;
		args++;
	}
	return number_of_valid_args;
}

t_list	*from_args_to_list(char **argv)
{

}
