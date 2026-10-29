/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:54:30 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 17:42:17 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrs(int nb)
{
	int	count;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbrs(nb / 10);
	count += ft_print_char((nb % 10) + '0');
	return (count);
}
