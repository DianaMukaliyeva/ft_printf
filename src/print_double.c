/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:02:40 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/19 14:25:15 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_len_without_sign(uintmax_t num)
{
	int	len;

	len = 1;
	
	if (num / 10 > 0)
		len += get_len_without_sign(num / 10);
	return (len);
}

static int	get_print_len(long double num, t_tag *tags)
{
	int	len;
	int	len_before_comma;
	int	len_after_comma;
	long double	ko;
	int	prec;

	len = 0;
	prec = tags->precision.num;
	if (num < 0 || tags->flags.space || tags->flags.sign)
	{
		num *= -1;
		len++;
	}
	len_before_comma = get_len_without_sign((int)num);
	ko = (num - (int)num);
	while (prec-- > 0)
		ko *= 10;
	len_after_comma = get_len_without_sign((int)ko);
	// if (num == 0 && tags->precision.is_exist && tags->precision.num == 0)
	// 	len--;
	if (tags->precision.num > len_after_comma)
		len_after_comma = tags->precision.num;
	len = len + len_before_comma + len_after_comma;
	return (len);
}

static int	print_digit_precision(long double num, t_tag *tags)
{
	int	res;
	long double	ko;
	int	prec;

	res = 0;
	if (num < 0)
		num *= -1;
	
	res += printf_putnbr((uintmax_t)num, 10);
	prec = tags->precision.num;
	ko = (num - (int)num);
	while (prec-- > 0)
	{
		ko *= 10;

	}
	// printf("!%Lf, %d\n", ko, prec);
	// printf("\n[%d]\n", (int) ko);
	res += printf_putchar('.');
	res += printf_putnbr((uintmax_t)ko + 1, 10);
	// len_after_comma = get_len_without_sign((int)(num % (int)num));
	// if (num < 0 || tags->flags.space || tags->flags.sign)
	// 	len--;
	// if (len < tags->precision.num)
	// 	while (len++ < tags->precision.num)
	// 		res += printf_putchar('0');
	// if (!tags->precision.is_exist || tags->precision.num > 0 || num != 0)
	// 	res += printf_putnbr(num, 10);
	return (res);
}

static int	print_sign(long double num, t_tag *tags)
{
	if (num < 0)
		return (printf_putchar('-'));
	if (tags->flags.sign)
		return (printf_putchar('+'));
	if (tags->flags.space)
		return (printf_putchar(' '));
	return (0);
}

static int	print_with_flags(long double num, t_tag *tags, int print_len)
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

int			print_double(t_tag *tags, va_list list)
{
	int			res;
	long double	num;
	int			print_len;

	res = 0;
	if (tags->modifier.big_l)
		num = (long double)va_arg(list, long double);
	else
		num = va_arg(list, double);
	if (tags->precision.num == 0)
		tags->precision.num = 6;
	print_len = get_print_len(num, tags);
	res += print_with_flags(num, tags, print_len);
	return (res);
}
