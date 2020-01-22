/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_low_hex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:12:55 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/22 19:56:57 by dmukaliy         ###   ########.fr       */
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

static int	get_print_len(uintmax_t num, t_flag flags)
{
	int	len;

	len = get_len_without_sign(num);
	if (num == 0 && flags.precision_exist && flags.precision_num == 0)
		len--;
	else if (flags.precision_num > len)
		len = flags.precision_num;
	if (flags.hash && !flags.precision_exist && num != 0)
		len += 2;
	return (len);
}

static int	print_digit_precision(uintmax_t num, t_flag flags)
{
	int	res;
	int	len;

	res = 0;
	len = get_len_without_sign(num);
	if (len < flags.precision_num)
		while (len++ < flags.precision_num)
			res += printf_putchar('0');
	if (!flags.precision_exist || flags.precision_num > 0 || num != 0)
		res += print_hex(num, 0);
	return (res);
}

static int	print_sign(t_flag flags, uintmax_t num)
{
	if (flags.hash && num != 0)
		return (print_with_flags("0x", 0, 0, 0));
	return (0);
}

static int	st_print_with_flags(uintmax_t num, t_flag flags, int print_len)
{
	int	res;
	int	width;

	width = flags.width_num;
	res = 0;
	if (width > print_len)
	{
		if (flags.minus)
		{
			res += print_sign(flags, num);
			res += print_digit_precision(num, flags);
			width -= res;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else
		{
			if (flags.zero && !flags.precision_num)
			{
				res += print_sign(flags, num);
				while (width-- > print_len)
					res += printf_putchar('0');
				res += print_digit_precision(num, flags);
			}
			else
			{
				while (width-- > print_len)
					res += printf_putchar(' ');
				res += print_sign(flags, num);
				res += print_digit_precision(num, flags);
			}
		}
	}
	else
	{
		res += print_sign(flags, num);
		res += print_digit_precision(num, flags);
	}
	
	return (res);
}

int			print_unsigned_low_hex(t_flag flags, va_list list)
{
	int			res;
	uintmax_t	num;
	int			print_len;

	res = 0;
	if (flags.z)
		num = (size_t)va_arg(list, intmax_t);
	else if (flags.j)
		num = va_arg(list, intmax_t);
	else if (flags.l)
		num = (unsigned long)va_arg(list, uintmax_t);
	else if (flags.ll)
		num = (unsigned long long)va_arg(list, uintmax_t);
	else if (flags.h)
		num = (unsigned short int)va_arg(list, uintmax_t);
	else if (flags.hh)
		num = (unsigned char)va_arg(list, uintmax_t);
	else
		num = (unsigned int)va_arg(list, uintmax_t);
	print_len = get_print_len(num, flags);
	res += st_print_with_flags(num, flags, print_len);
	return (res);
}
