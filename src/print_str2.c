/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:07:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/17 19:37:35 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_str_left(t_tag *tags, char *str)
{
	int	res;
	int	len;
	int	width;

	width = tags->width.num;
	if (tags->precision.is_exist)
		len = tags->precision.num;
	else
		len = ft_strlen(str);
	res = 0;
	if (!str)
	{
		if (!tags->precision.is_exist)
			len = 6;
		if (len >= 6)
			res += printf_putstr("(null)");
		len = 0;
	}
	while (len-- > 0 && *str)
		res += printf_putchar(*str++);
	width -= res;
	while (width-- > 0)
		res += printf_putchar(' ');
	return (res);
}

static int	calculate_and_print(t_tag *tags, char *str)
{
	int	res;
	int	precision;
	int	len;

	len = ft_strlen(str);
	if (!str)
		len = 6;
	res = 0;
	if (tags->precision.is_exist)
		precision = tags->precision.num;
	else
		precision = len;
	if (precision < len)
	{
		while (tags->width.num-- > precision)
			res += printf_putchar(' ');
		tags->width.num++;
		res += print_str_left(tags, str);
	}
	else
	{
		if (tags->flags.zero)
			while (tags->width.num-- > len)
				res += printf_putchar('0');
		else
			while (tags->width.num-- > len)
				res += printf_putchar(' ');
		
		res += printf_putstr(str);
	}
	return (res);
}

int			print_str2(t_tag *tags, va_list list)
{
	char	*str;

	str = va_arg(list, char*);
	if (tags->width.num <= 0 || tags->flags.left_align)
		return (print_str_left(tags, str));
	else
		return (calculate_and_print(tags, str));
}
