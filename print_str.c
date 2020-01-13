/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:07:18 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/13 12:55:18 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_str(t_tag *tags, va_list list)
{
	int		res;
	char	*str;
	int		width;
	int		precision;
	int		len;

	res = 0;
	width = 0;
	precision = 0;
	str = va_arg(list, char*);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (tags->width.is_exist)
		width = tags->width.num;
	if (tags->precision.is_exist)
		precision = tags->precision.num;
	if (width == 0 && precision == 0)
		res += printf_putstr(str);
	else if (width == 0 || width < len)
	{
		while (precision > 0 && *str)
		{
			res += printf_putchar(*str);
			str++;
			precision--;
		}
	}
	else if (precision == 0)
	{
		if (tags->flags.left_align)
		{
			res += printf_putstr(str);
			width -= len;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
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
	}
	else
	{
		if (tags->flags.left_align)
		{
			while (precision > 0 && *str)
			{
				res += printf_putchar(*str);
				str++;
				precision--;
				width--;
			}
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else if (tags->flags.zero)
		{
			if (precision < len)
			{
				while (width-- > precision)
					res += printf_putchar('0');
				while (width-- >= 0)
				{
					res += printf_putchar(*str);
					str++;
				}
			}
			else
			{
				while (width-- > len)
					res += printf_putchar('0');
				res += printf_putstr(str);
			}
		}
		else
		{
			if (precision < len)
			{
				while (width-- > precision)
					res += printf_putchar(' ');
				while (width-- >= 0)
				{
					res += printf_putchar(*str);
					str++;
				}
			}
			else
			{
				while (width-- > len)
					res += printf_putchar(' ');
				res += printf_putstr(str);
			}
		}
	}
	return (res);
}
