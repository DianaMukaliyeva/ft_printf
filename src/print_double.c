/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:02:40 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/20 00:55:27 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len_without_sign(uintmax_t num)
{
	int	len;

	len = 1;
	
	if (num / 10 > 0)
		len += get_len_without_sign(num / 10);
	return (len);
}

static int	get_print_len(long double num, t_flag flags)
{
	int	len;
	int	len_before_comma;
	int	len_after_comma;
	long double	ko;
	int	prec;

	len = 0;
	prec = flags.precision_num;
	if (num < 0 || flags.space || flags.plus)
	{
		num *= -1;
		len++;
	}
	len_before_comma = get_len_without_sign((int)num);
	ko = (num - (int)num);
	while (prec-- > 0)
		ko *= 10;
	len_after_comma = get_len_without_sign((int)ko);
	// if (num == 0 && flags->precision.is_exist && flags.precision_num == 0)
	// 	len--;
	if (flags.precision_num > len_after_comma)
		len_after_comma = flags.precision_num;
	len = len + len_before_comma + len_after_comma;
	return (len);
}

static int	print_digit_precision(long double num, t_flag flags)
{
	int	res;
	long double	ko;
	int	prec;

	res = 0;
	if (num < 0)
		num *= -1;
	
	res += printf_putnbr((uintmax_t)num, 10);
	prec = flags.precision_num;
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
	// if (num < 0 || flags.space || flags.plus)
	// 	len--;
	// if (len < flags.precision_num)
	// 	while (len++ < flags.precision_num)
	// 		res += printf_putchar('0');
	// if (!flags->precision.is_exist || flags.precision_num > 0 || num != 0)
	// 	res += printf_putnbr(num, 10);
	return (res);
}

static int	print_sign(long double num, t_flag flags)
{
	if (num < 0)
		return (printf_putchar('-'));
	if (flags.plus)
		return (printf_putchar('+'));
	if (flags.space)
		return (printf_putchar(' '));
	return (0);
}

static int	print_with_flags(long double num, t_flag flags, int print_len)
{
	int	res;
	int	width;

	width = flags.width_num;
	res = 0;
	if (width > print_len)
	{
		if (flags.minus)
		{
			res += print_sign(num, flags);
			res += print_digit_precision(num, flags);
			width -= res;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else
		{
			if (flags.zero && !flags.precision_exist)
			{
				res += print_sign(num, flags);
				while (width-- > print_len)
					res += printf_putchar('0');
				res += print_digit_precision(num, flags);
			}
			else
			{
				while (width-- > print_len)
					res += printf_putchar(' ');
				res += print_sign(num, flags);
				res += print_digit_precision(num, flags);
			}
		}
	}
	else
	{
		res += print_sign(num, flags);
		res += print_digit_precision(num, flags);
	}
	
	return (res);
}

int			print_double(t_flag flags, va_list list)
{
	int			res;
	long double	num;
	int			print_len;

	res = 0;
	if (flags.big_l)
		num = (long double)va_arg(list, long double);
	else
		num = va_arg(list, double);
	if (flags.precision_num == 0)
		flags.precision_num = 6;
	print_len = get_print_len(num, flags);
	res += print_with_flags(num, flags, print_len);
	return (res);
}
