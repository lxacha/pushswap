/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 19:40:37 by timbert           #+#    #+#             */
/*   Updated: 2026/11/11 01:37:23 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		count = write (1, "(null)", 6);
	else
	{
		while (str[i])
		{
			count += write (1, &str[i], 1);
			i++;
		}
	}
	return (count);
}
