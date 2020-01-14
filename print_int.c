/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:43:24 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/14 16:41:25 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_len(long long num)
{
	int	len;

	len = 1;
	if (num < 0)
	{
		len++;
		if (num == -2147483648)
		{
			len++;
			num = -147483648;
		}
		num *= -1;
	}
	if (num / 10 > 0)
		len += get_len(num / 10);
	return (len);
}

static int	print_digit(long long num, int res, t_tag *tags, int len)
{
	if (len < tags->precision.num)
	{
		while (len++ < tags->precision.num)
			res += printf_putchar('0');
		res += print_digit(num, res, tags, len);
	}
	else
	{
		if (num < 0)
		{
			res += printf_putchar('-');
			tags->precision.num--;
			if (num == -2147483648 && tags->precision.num > 0)
			{
				res += printf_putchar('2');
				tags->precision.num--;
				num = -147483648;
			}
			num *= -1;
		}
		else
		{
			if (tags->flags.sign)
			{
				res += printf_putchar('+');
				tags->precision.num--;
			}
			else if (tags->flags.space)
			{
				res += printf_putchar(' ');
				tags->precision.num--;
			}
		}
		if (num / 10 > 0)
			res += print_digit(num / 10, res, tags, len);
		if (tags->precision.num > 0)
		{
			res += printf_putchar((num % 10) + '0');
			tags->precision.num--;
		}
	}
	
	return (res);
}

static int	print_int_with_sign(long long num)
{
	int	res;

	res = 0;
	if (num >= 0)
		res += printf_putchar('+');
	res += printf_putnbr(num);
	return (res);
}

static int	print_int_with_space(long long num)
{
	int	res;

	res = 0;
	if (num > 0)
		res += printf_putchar(' ');
	res += printf_putnbr(num);
	return (res);
}

static int print_int_with_width(t_tag *tags, long long num)
{
	int	res;
	int	len;
	int	width;

	res = 0;
	len = get_len(num);
	width = tags->width.num;
	if (num > 0 && (tags->flags.sign || tags->flags.space))
		len++;
	if (tags->precision.is_exist)
	{
		res += printf_putnbr(num);
	}
	else
	{
		if (tags->flags.left_align)
		{
			if (tags->flags.sign)
				res += print_int_with_sign(num);
			else if(tags->flags.space)
				res += print_int_with_space(num);
			else
				res += printf_putnbr(num);
			width -= res;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else
		{
			if (tags->flags.zero)
			{
				if (tags->flags.sign)
				{
					if (num >= 0)
					{
						res += printf_putchar('+');
						width--;
					}
					else
					{
						res += printf_putchar('-');
						width--;
						//proverit', esli eto long long samaya bolshaya
						num *= -1;
					}
					len = get_len(num);
					while (width-- > len)
						res += printf_putchar('0');
					res += printf_putnbr(num);
				}
				else if (tags->flags.space)
				{
					if (num >= 0)
					{
						res += printf_putchar(' ');
						width--;
					}
					else
					{
						res += printf_putchar('-');
						width--;
						//proverit', esli eto long long samaya bolshaya
						num *= -1;
					}
					len = get_len(num);
					while (width-- > len)
						res += printf_putchar('0');
					res += printf_putnbr(num);
				}
			}
			else
			{
				if (tags->flags.sign)
				{
					while (width-- > len)
						res += printf_putchar(' ');
					if (num >= 0)
						res += printf_putchar('+');
					res += printf_putnbr(num);
				}
				else if (tags->flags.space)
				{
					while (width-- > len)
						res += printf_putchar(' ');
					if (num >= 0)
						res += printf_putchar(' ');
					res += printf_putnbr(num);
				}
			}
		}
	}
	return (res);
}

static int print_int_with_precision(t_tag *tags, long long num)
{
	int	res;
	int	len;

	res = 0;
	len = get_len(num);
	if (num > 0 && (tags->flags.sign || tags->flags.space))
		len++;
	if (tags->precision.num)
		res += print_digit(num, res, tags, len);
	else if (num != 0)
		res += printf_putnbr(num);
	return (res);
}

int	print_int(t_tag *tags, va_list list)
{
	int			res;
	long long	num;

	res = 0;
	if (tags->modifier.h)
		num = (short int)va_arg(list, int);
	else if (tags->modifier.hh)
		num = (char)va_arg(list, int);
	else if (tags->modifier.l)
		num = (long)va_arg(list, int);
	else if (tags->modifier.ll)
		num = (long long)va_arg(list, int);
	else
		num = va_arg(list, int);
	if (tags->width.is_exist)
		res += print_int_with_width(tags, num);
	else if(tags->precision.is_exist)
		res += print_int_with_precision(tags, num);
	else if (tags->flags.sign)
		res += print_int_with_sign(num);
	else if(tags->flags.space)
		res += print_int_with_space(num);
	else
		res += printf_putnbr(num);
	return (res);
}
