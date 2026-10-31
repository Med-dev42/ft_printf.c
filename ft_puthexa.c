/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:43:51 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/30 16:32:16 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned int hex, char c)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	count = 0;
	if (hex >= 16)
		count += ft_put_hex(hex / 16, c);
	count += ft_print_char(base[hex % 16]);
	return (count);
}

int	ft_puthexa(unsigned int hex, char c)
{
	int	count;

	count = 0;
	count += ft_put_hex(hex, c);
	return (count);
}
