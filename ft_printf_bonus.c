/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:49:10 by mlazar            #+#    #+#             */
/*   Updated: 2026/10/29 15:49:15 by mlazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_init_flags(t_flags *f)
{
	f->minus = 0;
	f->zero = 0;
	f->plus = 0;
	f->space = 0;
	f->hash = 0;
	f->width = 0;
	f->prec = -1;
}

static int	ft_flag(char c, t_flags *f)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '+')
		f->plus = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '#')
		f->hash = 1;
	else
		return (0);
	return (1);
}

static int	ft_parse(const char *s, t_flags *f)
{
	int	i;

	i = 0;
	ft_init_flags(f);
	while (ft_flag(s[i], f))
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		f->width = f->width * 10 + s[i++] - '0';
	if (s[i] == '.')
	{
		i++;
		f->prec = 0;
		while (s[i] >= '0' && s[i] <= '9')
			f->prec = f->prec * 10 + s[i++] - '0';
	}
	return (i);
}

static int	ft_dispatch(char c, va_list *args, t_flags f)
{
	if (c == 'c')
		return (ft_putchar_bonus(va_arg(*args, int), f));
	if (c == 's')
		return (ft_putstr_bonus(va_arg(*args, char *), f));
	if (c == 'p')
		return (ft_print_ptr_bonus(va_arg(*args, void *), f));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_bonus(va_arg(*args, int), f));
	if (c == 'u')
		return (ft_putunsigned_bonus(va_arg(*args, unsigned int), f));
	if (c == 'x' || c == 'X')
		return (ft_puthex_bonus(va_arg(*args, unsigned int), f, c));
	if (c == '%')
		return (ft_putchar_bonus('%', f));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	f;
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
			i += ft_parse(&format[i], &f);
			if (!format[i])
				break ;
			count += ft_dispatch(format[i], &args, f);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
