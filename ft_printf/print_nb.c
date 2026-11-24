/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 00:20:50 by timbert           #+#    #+#             */
/*   Updated: 2026/11/03 00:20:50 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nb(long nbr)
{
	int		count;
	char	c;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count += write(1, "-", 1);
	}
	if (nbr > 9)
		count += print_nb((nbr / 10));
	c = (nbr % 10) + '0';
	write (1, &c, 1);
	return (count + 1);
}
