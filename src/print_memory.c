/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:11:35 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/19 14:40:20 by diana            ###   ########.fr       */
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

static int	get_print_len(uintmax_t num, t_tag *tags)
{
	int	len;

	len = get_len_without_sign(num);
	if (num == 0 && tags->precision.is_exist && tags->precision.num == 0)
		len--;
	else if (tags->precision.num > len)
		len = tags->precision.num;
	if (tags->flags.hash && num != 0)
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
		res += print_hex(num, 0);
	return (res);
}

static int	print_sign(t_tag *tags, uintmax_t num)
{
	if (tags->flags.hash && num != 0)
		return (printf_putstr("0x"));
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

int	print_memory(t_tag *tags, va_list list)
{
	int		res;
	void	*p;
	uintmax_t	address;
	int			print_len;

	res = 0;
	p = va_arg(list, void *);
	address = (uintmax_t)p;
	tags->flags.hash = 1;
	print_len = get_print_len(address, tags);
	res += print_with_flags(address, tags, print_len);
	return (res);
}
