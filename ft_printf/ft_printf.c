/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timbert <timbert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 17:15:58 by timbert           #+#    #+#             */
/*   Updated: 2026/11/11 01:45:12 by timbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_caract(char c, va_list *args)
{
	if (c == 'c')
		return (print_char(va_arg(*args, int)));
	else if (c == 's')
		return (print_str(va_arg(*args, char *)));
	else if (c == 'i' || c == 'd')
		return (print_nb(va_arg(*args, int)));
	else if (c == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (print_hexa(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (print_hexa(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (print_ptr(va_arg(*args, unsigned long), "0123456789abcdef"));
	else if (c == '%')
		return (write (1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				return (count);
			count += check_caract(str[i + 1], &args);
			i++;
		}
		else
			count += write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
