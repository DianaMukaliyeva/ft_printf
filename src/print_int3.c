/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:46:33 by diana             #+#    #+#             */
/*   Updated: 2020/01/17 18:24:53 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_len_without_sign(intmax_t num)
{
	int	len;

	len = 1;
	
	if (num < 0)
		num *= -1;
	if (num + 1 == -9223372036854775807)
		return (19);
	if (num / 10 > 0)
		len += get_len_without_sign(num / 10);
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
	if (num < 0 || tags->flags.space || tags->flags.sign)
		len++;
	return (len);
}

static int	print_digit_precision(intmax_t num, t_tag *tags)
{
	int	res;
	int	len;

	res = 0;
	if (num < 0)
		num *= -1;
	len = get_len_without_sign(num);
	if (len < tags->precision.num)
		while (len++ < tags->precision.num)
			res += printf_putchar('0');
	if (!tags->precision.is_exist || tags->precision.num > 0 || num != 0)
		res += printf_putnbr(num, 10);
	return (res);
}

static int	print_sign(intmax_t num, t_tag *tags)
{
	if (num < 0)
		return (printf_putchar('-'));
	if (tags->flags.sign)
		return (printf_putchar('+'));
	if (tags->flags.space)
		return (printf_putchar(' '));
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
			res += print_sign(num, tags);
			res += print_digit_precision(num, tags);
			width -= res;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else
		{
			if (tags->flags.zero && !tags->precision.is_exist)
			{
				res += print_sign(num, tags);
				while (width-- > print_len)
					res += printf_putchar('0');
				res += print_digit_precision(num, tags);
			}
			else
			{
				while (width-- > print_len)
					res += printf_putchar(' ');
				res += print_sign(num, tags);
				res += print_digit_precision(num, tags);
			}
		}
	}
	else
	{
		res += print_sign(num, tags);
		res += print_digit_precision(num, tags);
	}
	
	return (res);
}

int			print_int3(t_tag *tags, va_list list)
{
	int			res;
	intmax_t	num;
	int			print_len;

	res = 0;
	if (tags->modifier.h)
		num = (short int)va_arg(list, int);
	else if (tags->modifier.hh)
		num = (char)va_arg(list, int);
	else if (tags->modifier.l)
		num = va_arg(list, long);
	else if (tags->modifier.ll)
		num = va_arg(list, intmax_t);
	else
		num = va_arg(list, int);
	print_len = get_print_len(num, tags);
	res += print_with_flags(num, tags, print_len);
	return (res);
}
