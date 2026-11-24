/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 00:20:46 by timbert           #+#    #+#             */
/*   Updated: 2026/11/03 00:20:46 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count = print_hexa(nbr / 16, base);
	write (1, &base[nbr % 16], 1);
	return (count + 1);
}
