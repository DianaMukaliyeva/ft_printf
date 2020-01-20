/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:46:33 by diana             #+#    #+#             */
/*   Updated: 2020/01/20 16:30:44 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	get_print_len(intmax_t num, t_flag flags)
{
	int	len;

	len = get_len_without_sign(num);
	if (num == 0 && flags.precision_exist && flags.precision_num == 0)
		len--;
	else if (flags.precision_num > len)
		len = flags.precision_num;
	if (num < 0 || flags.space || flags.plus)
		len++;
	return (len);
}

static int	print_digit_precision(intmax_t num, t_flag flags)
{
	int	res;
	int	len;

	res = 0;
	if (num < 0)
		num *= -1;
	len = get_len_without_sign(num);
	if (len < flags.precision_num)
		while (len++ < flags.precision_num)
			res += printf_putchar('0');
	if (!flags.precision_exist || flags.precision_num > 0 || num != 0)
		res += printf_putnbr(num, 10);
	return (res);
}

static int	print_sign(intmax_t num, t_flag flags)
{
	if (num < 0)
		return (printf_putchar('-'));
	if (flags.plus)
		return (printf_putchar('+'));
	if (flags.space)
		return (printf_putchar(' '));
	return (0);
}

static int	print_with_flags(intmax_t num, t_flag flags, int print_len)
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

int			print_int3(t_flag flags, va_list list)
{
	int			res;
	intmax_t	num;
	int			print_len;

	res = 0;
	if (flags.z)
		num = (size_t)va_arg(list, intmax_t);
	else if (flags.j)
		num = va_arg(list, intmax_t);
	else if (flags.l)
		num = (long int)va_arg(list, intmax_t);
	else if (flags.ll)
		num = (long long int)va_arg(list, intmax_t);
	else if (flags.h)
		num = (short int)va_arg(list, intmax_t);
	else if (flags.hh)
		num = (char)va_arg(list, intmax_t);
	else
		num = va_arg(list, int);
	print_len = get_print_len(num, flags);
	res += print_with_flags(num, flags, print_len);
	return (res);
}
