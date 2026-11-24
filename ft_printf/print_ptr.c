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

int	print_ptr(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (!nbr)
		return (write (1, "(nil)", 5));
	else
	{
		count += write(1, "0x", 2);
		count += print_hexa(nbr, base);
		return (count);
	}
}
