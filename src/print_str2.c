/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:07:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/20 00:42:59 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_str_left(t_flag flags, char *str)
{
	int	res;
	int	len;
	int	width;

	width = flags.width_num;
	if (flags.precision_exist)
		len = flags.precision_num;
	else
		len = ft_strlen(str);
	res = 0;
	while (len-- > 0 && *str)
		res += printf_putchar(*str++);
	width -= res;
	while (width-- > 0)
		res += printf_putchar(' ');
	return (res);
}

static int	calculate_and_print(t_flag flags, char *str)
{
	int	res;
	int	precision;
	int	len;

	len = ft_strlen(str);
	if (!str)
		len = 6;
	res = 0;
	if (flags.precision_exist)
		precision = flags.precision_num;
	else
		precision = len;
	if (precision < len)
	{
		if (flags.zero)
			while (flags.width_num-- > precision)
				res += printf_putchar('0');
		else
			while (flags.width_num-- > precision)
				res += printf_putchar(' ');
		flags.width_num++;
		res += print_str_left(flags, str);
	}
	else
	{
		if (flags.zero)
			while (flags.width_num-- > len)
				res += printf_putchar('0');
		else
			while (flags.width_num-- > len)
				res += printf_putchar(' ');
		res += printf_putstr(str);
	}
	return (res);
}

int			print_str2(t_flag flags, va_list list)
{
	char	*str;

	str = va_arg(list, char*);
	if (!str)
		str = "(null)";
	if (flags.width_num == 0 || flags.minus)
		return (print_str_left(flags, str));
	else
		return (calculate_and_print(flags, str));
}
