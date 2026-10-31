/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:51:31 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:51:32 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_prnt(char c, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += ft_putchar(c);
		n--;
	}
	return (count);
}

int	ft_putchar_bonus(char c, t_flags f)
{
	int	count;

	count = 0;
	if (!f.minus)
		count += ft_prnt(' ', f.width - 1);
	count += ft_putchar(c);
	if (f.minus)
		count += ft_prnt(' ', f.width - 1);
	return (count);
}
