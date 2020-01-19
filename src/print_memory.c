/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:11:35 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/20 00:49:33 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


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
	if (flags.hash && num != 0)
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
		return (printf_putstr("0x"));
	return (0);
}

static int	print_with_flags(uintmax_t num, t_flag flags, int print_len)
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
			if (flags.zero && !flags.precision_exist)
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

int	print_memory(t_flag flags, va_list list)
{
	int		res;
	void	*p;
	uintmax_t	address;
	int			print_len;

	res = 0;
	p = va_arg(list, void *);
	address = (uintmax_t)p;
	flags.hash = 1;
	print_len = get_print_len(address, flags);
	res += print_with_flags(address, flags, print_len);
	return (res);
}
