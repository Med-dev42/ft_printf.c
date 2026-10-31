/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:49:34 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/31 01:31:25 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_print_point(va_arg(*args, void *)));
	if (c == 'd')
		return (ft_putnbrs(va_arg(*args, int)));
	if (c == 'i')
		return (ft_putnbrs(va_arg(*args, int)));
	if (c == 'u')
		return (ft_unsigned_nbr(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_puthexa(va_arg(*args, unsigned int), c));
	if (c == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), c));
	if (c == '%')
		return (ft_print_sign());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			count += ft_check(format[i], &args);
		}
		else
			count += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
