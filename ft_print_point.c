/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:50:39 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:50:40 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_long_hex(unsigned long hex)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (hex >= 16)
		count += ft_put_long_hex(hex / 16);
	count += ft_print_char(base[hex % 16]);
	return (count);
}

int	ft_print_point(void *x)
{
	int	count;

	if (!x)
		return (ft_print_str("(nil)"));
	count = ft_print_str("0x");
	count += ft_put_long_hex((unsigned long)x);
	return (count);
}
