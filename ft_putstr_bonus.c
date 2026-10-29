/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:52:14 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:52:15 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_putnstr(char *s, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < n)
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

int	ft_putstr_bonus(char *s, t_flags f)
{
	int	count;
	int	len;

	if (!s)
	{
		if (f.prec >= 0 && f.prec < 6)
			s = "";
		else
			s = "(null)";
	}
	len = ft_strlen(s);
	if (f.prec >= 0 && f.prec < len)
		len = f.prec;
	count = 0;
	if (!f.minus)
		count += ft_prnt(' ', f.width - len);
	count += ft_putnstr(s, len);
	if (f.minus)
		count += ft_prnt(' ', f.width - len);
	return (count);
}
