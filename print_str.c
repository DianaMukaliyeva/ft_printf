/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:07:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/14 11:18:30 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_of_len(int len, char *str, int amount_of_spaces)
{
	int	res;

	res = 0;
	while (len-- > 0 && *str)
		res += printf_putchar(*str++);
	if (amount_of_spaces > 0)
		while (amount_of_spaces-- > 0)
			res += printf_putchar(' ');
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
		res += print_str_of_len(width + 1, str, 0);
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
	int res;
	int	width;
	int	precision;

	res = 0;
	width = tags->width.num;
	precision = tags->precision.num;
	if (tags->flags.left_align)
		if (precision <= len)
			res += print_str_of_len(precision, str, width - precision);
		else
			res += print_str_of_len(precision, str, width - len);
	else if (tags->flags.zero)
		res += print_without_align(str, tags, len, '0');
	else
		res += print_without_align(str, tags, len, ' ');
	return (res);
}

static int	print_without_precision(t_tag *tags, char *str)
{
	int	res;
	int	width;

	res = 0;
	width = tags->width.num;
	if (tags->flags.left_align)
	{
		res += printf_putstr(str);
		while (width-- > ft_strlen(str))
			res += printf_putchar(' ');
	}
	else if (tags->flags.zero)
	{
		while (width-- > ft_strlen(str))
			res += printf_putchar('0');
		res += printf_putstr(str);
	}
	else
	{
		while (width-- > ft_strlen(str))
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
		res += print_str_of_len(precision, str, 0);
	else if (precision == 0)
		res += print_without_precision(tags, str);
	else
		res += calculate_and_print(tags, str, len);
	return (res);
}
