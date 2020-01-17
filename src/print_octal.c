/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:01:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 13:39:57 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_len_without_sign(intmax_t num)
{
	int	len;

	len = 1;
	
	if (num / 8 > 0)
		len += get_len_without_sign(num / 8);
	return (len);
}

static int	get_print_len(intmax_t num, t_tag *tags)
{
	int	len;

	len = get_len_without_sign(num);
	if (num == 0 && tags->precision.is_exist && tags->precision.num == 0)
		len--;
	else
		if (tags->precision.num > len)
			len = tags->precision.num;
	if (tags->flags.hash && !tags->precision.is_exist)
		len++;
	return (len);
}

static int	print_digit_precision(intmax_t num, t_tag *tags)
{
	int	res;
	int	len;

	res = 0;
	len = get_len_without_sign(num);
	if (len < tags->precision.num)
		while (len++ < tags->precision.num)
			res += printf_putchar('0');
	if (!tags->precision.is_exist || tags->precision.num > 0 || num != 0)
		res += printf_putnbr(num, 8);
	return (res);
}

static int	print_sign(t_tag *tags)
{
	if (tags->flags.hash && (!tags->precision.num))
		return (printf_putchar('0'));
	return (0);
}

static int	print_with_flags(intmax_t num, t_tag *tags, int print_len)
{
	int	res;
	int	width;

	width = tags->width.num;
	res = 0;
	if (width > print_len)
	{
		if (tags->flags.left_align)
		{
			res += print_sign(tags);
			res += print_digit_precision(num, tags);
			width -= res;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else
		{
			if (tags->flags.zero && !tags->precision.is_exist)
			{
				res += print_sign(tags);
				while (width-- > print_len)
					res += printf_putchar('0');
				res += print_digit_precision(num, tags);
			}
			else
			{
				while (width-- > print_len)
					res += printf_putchar(' ');
				res += print_sign(tags);
				res += print_digit_precision(num, tags);
			}
		}
	}
	else
	{
		res += print_sign(tags);
		res += print_digit_precision(num, tags);
	}
	
	return (res);
}

int			print_octal(t_tag *tags, va_list list)
{
	int			res;
	intmax_t	num;
	int			print_len;

	res = 0;
	if (tags->modifier.h)
		num = (unsigned short int)va_arg(list, int);
	else if (tags->modifier.hh)
		num = (unsigned char)va_arg(list, int);
	else if (tags->modifier.l)
		num = (unsigned long) va_arg(list, long);
	else if (tags->modifier.ll)
		num = (unsigned long long) va_arg(list, intmax_t);
	else
		num = (unsigned int) va_arg(list, int);
	print_len = get_print_len(num, tags);
	res += print_with_flags(num, tags, print_len);
	return (res);
}
