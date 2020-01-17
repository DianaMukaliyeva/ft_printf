/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_upper_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:13:30 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 19:13:02 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_len_without_sign(uintmax_t num)
{
	int	len;

	len = 1;
	
	if (num / 16 > 0)
		len += get_len_without_sign(num / 16);
	return (len);
}

static int	get_print_len(uintmax_t num, t_tag *tags)
{
	int	len;

	len = get_len_without_sign(num);
	if (num == 0 && tags->precision.is_exist && tags->precision.num == 0)
		len--;
	else
		if (tags->precision.num > len)
			len = tags->precision.num;
	if (tags->flags.hash)
		len += 2;
	return (len);
}

static int	print_digit_precision(uintmax_t num, t_tag *tags)
{
	int	res;
	int	len;

	res = 0;
	len = get_len_without_sign(num);
	if (len < tags->precision.num)
		while (len++ < tags->precision.num)
			res += printf_putchar('0');
	if (!tags->precision.is_exist || tags->precision.num > 0 || num != 0)
		res += print_hex(num, 1);
	return (res);
}

static int	print_sign(t_tag *tags, uintmax_t num)
{
	if (tags->flags.hash && num != 0)
		return (printf_putstr("0X"));
	return (0);
}

static int	print_with_flags(uintmax_t num, t_tag *tags, int print_len)
{
	int	res;
	int	width;

	width = tags->width.num;
	res = 0;
	if (width > print_len)
	{
		if (tags->flags.left_align)
		{
			res += print_sign(tags, num);
			res += print_digit_precision(num, tags);
			width -= res;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else
		{
			if (tags->flags.zero && !tags->precision.is_exist)
			{
				res += print_sign(tags, num);
				while (width-- > print_len)
					res += printf_putchar('0');
				res += print_digit_precision(num, tags);
			}
			else
			{
				while (width-- > print_len)
					res += printf_putchar(' ');
				res += print_sign(tags, num);
				res += print_digit_precision(num, tags);
			}
		}
	}
	else
	{
		res += print_sign(tags, num);
		res += print_digit_precision(num, tags);
	}
	
	return (res);
}

int			print_unsigned_upper_hex(t_tag *tags, va_list list)
{
	int			res;
	uintmax_t	num;
	int			print_len;

	res = 0;
	if (tags->modifier.h)
		num = (unsigned short int)va_arg(list, uintmax_t);
	else if (tags->modifier.hh)
		num = (unsigned char)va_arg(list, uintmax_t);
	else if (tags->modifier.l)
		num = (unsigned long) va_arg(list, uintmax_t);
	else if (tags->modifier.ll)
		num = (unsigned long long) va_arg(list, uintmax_t);
	else
		num = (unsigned int) va_arg(list, uintmax_t);
	print_len = get_print_len(num, tags);
	res += print_with_flags(num, tags, print_len);
	return (res);
}
