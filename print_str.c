/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:07:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 17:14:20 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_str_of_len(int len, char *str)
{
	int	res;

	res = 0;
	while (len-- > 0 && *str)
	{
		res += printf_putchar(*str);
		str++;
	}
	return (res);
}

static int	print_without_align(char *str, t_tag *tags, int len, char c)
{
	int	res;
	int	width;
	int	precision;

	res = 0;
	width = tags->width.num;
	precision = tags->precision.num;
	if (precision < len)
	{
		while (width-- > precision)
			res += printf_putchar(c);
		print_str_of_len(width + 1, str);
	}
	else
	{
		while (width-- > len)
			res += printf_putchar(c);
		res += printf_putstr(str);
	}
	return (res);
}

static int	calculate_and_print(t_tag *tags, char *str, int len)
{
	int	width;
	int	precision;
	int res;

	res = 0;
	width = tags->width.num;
	precision = tags->precision.num;
	if (tags->flags.left_align)
	{
		print_str_of_len(precision, str);
		width -= precision;
		while (width-- > 0)
			res += printf_putchar(' ');
	}
	else if (tags->flags.zero)
		res += print_without_align(str, tags, len, '0');
	else
		res += print_without_align(str, tags, len, ' ');
	return (res);
}

static int	print_without_precision(t_tag *tags, char *str)
{
	int	res;
	int	len;
	int	width;

	res = 0;
	len = ft_strlen(str);
	width = tags->width.num;
	if (tags->flags.left_align)
		while (width-- > len)
			res += printf_putchar(' ');
	else if (tags->flags.zero)
	{
		while (width-- > len)
			res += printf_putchar('0');
		res += printf_putstr(str);
	}
	else
	{
		while (width-- > len)
			res += printf_putchar(' ');
		res += printf_putstr(str);
	}
	return (res);
}

int			print_str(t_tag *tags, va_list list)
{
	int		res;
	char	*str;
	int		width;
	int		precision;
	int		len;

	str = va_arg(list, char*);
	if (!str)
		str = "(null)";
	res = 0;
	len = ft_strlen(str);
	width = tags->width.num;
	precision = tags->precision.num;
	if (width == 0 && precision == 0)
		res += printf_putstr(str);
	else if (width == 0 || width < len)
		res += print_str_of_len(precision, str);
	else if (precision == 0)
		res += print_without_precision(tags, str);
	else
		res += calculate_and_print(tags, str, len);
	return (res);
}
