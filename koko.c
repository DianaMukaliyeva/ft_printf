/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koko.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 19:46:07 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/15 20:02:18 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


static int	get_len(intmax_t num, t_tag *tags, int check_plus)
{
	int	len;

	len = 1;
	if (check_plus && num > 0 && (tags->flags.sign || tags->flags.space))
		len++;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	if (num / 10 > 0)
		len += get_len(num / 10, tags, 0);
	return (len);
}

static int	print_digit_precision(intmax_t num, int res, t_tag *tags, int len)
{
	if (len < tags->precision.num)
		while (len++ < tags->precision.num)
			res += printf_putchar('0');
	if (!(tags->precision.is_exist) || tags->precision.num != 0 || num != 0)
		res += printf_putnbr(num);
	return (res);
}

static int	print_sign_or_space(intmax_t *num, char c, int should_print_number)
{
	int			res;
	long long	n;

	n = *num;
	res = 0;
	if (should_print_number)
	{
		if (n >= 0)
			res += printf_putchar(c);
		res += printf_putnbr(n);
	}
	else
	{
		if (n >= 0)
			res += printf_putchar(c);
		else
		{
			res += printf_putchar('-');
			*num = n * -1;
		}
	}
	return (res);
}

static int	without_align(t_tag *tags, intmax_t num)
{
	int	res;
	int len;
	int width;

	width = tags->width.num;
	res = 0;
	len = get_len(num, tags, 1);
	if (tags->flags.sign)//+*.*
	{
		if (tags->flags.zero)
		{
			res += print_sign_or_space(&num, '+', 0);
			while (width-- > len)
				res += printf_putchar('0');
			// width--;
			res = print_digit_precision(num, res, tags, len - 1);
			// if (tags->precision.is_exist && tags->precision.num == 0 && num == 0)
			// 	res += printf_putchar(' ');
		}
		else
		{
			width--;
			while (width-- > len)
				res += printf_putchar(' ');
			res += print_sign_or_space(&num, '+', 0);
			res = print_digit_precision(num, res, tags, len - 1);
			if (tags->precision.is_exist && tags->precision.num == 0 && num == 0 && width > 0)
				res += printf_putchar(' ');
		}
	}
	else if (tags->flags.space)// *.*
	{
		width--;
		while (width-- > len)
			res += printf_putchar(' ');
		res += print_sign_or_space(&num, ' ', 0);
		res = print_digit_precision(num, res, tags, len - 1);
		if (tags->precision.is_exist && tags->precision.num == 0 && num == 0 && width > 0)
			res += printf_putchar(' ');
	}
	else//*.*
	{
		if (tags->flags.zero)
		{
			if (num >= 0)
			{
				if (len > tags->precision.num)
					while (width-- > len)
						res += printf_putchar('0');
				else
					while (width-- > tags->precision.num)
						res += printf_putchar(' ');
				res = print_digit_precision(num, res, tags, len);
				if (tags->precision.is_exist && tags->precision.num == 0 && num == 0  && width > 0)
					res += printf_putchar(' ');
			}
			else
			{
				res += printf_putchar('-');
				if (len > tags->precision.num)
					while (width-- > len)
						res += printf_putchar('0');
				else
					while (--width > tags->precision.num)
						res += printf_putchar(' ');
				width -= res;
				num *= -1;
				res = print_digit_precision(num, res, tags, len - 1);
			}
		}
		else
		{
			if (num >= 0)
			{
				if (len > tags->precision.num)
					while (width-- > len)
						res += printf_putchar(' ');
				else
					while (width-- > tags->precision.num)
						res += printf_putchar(' ');
				res = print_digit_precision(num, res, tags, len);
				// if (tags->precision.is_exist && tags->precision.num == 0 && num == 0)
				// 	res += printf_putchar(' ');
			}
			else
			{
				if (len > tags->precision.num)
					while (width-- > len)
						res += printf_putchar(' ');
				else
					while (width-- > tags->precision.num)
						res += printf_putchar(' ');
				width -= res;
				res += printf_putchar('-');
				num *= -1;
				res = print_digit_precision(num, res, tags, len - 1);
			}
		}
	}
	return (res);
}

static int	left_align(t_tag *tags, intmax_t num)
{
	int	res;
	int len;
	int width;

	width = tags->width.num;
	res = 0;
	len = get_len(num, tags, 1);
	if (tags->flags.sign)//-+*.*
	{
		res += print_sign_or_space(&num, '+', 0);
		len = get_len(num, tags, 0);
		res = print_digit_precision(num, res, tags, len);
		width -= res;
		while (width-- > 0)
			res += printf_putchar(' ');
	}
	else if (tags->flags.space)//- *.*
	{
		res += print_sign_or_space(&num, ' ', 0);
		len = get_len(num, tags, 0);
		res = print_digit_precision(num, res, tags, len);
		width -= res;
		while (width-- > 0)
			res += printf_putchar(' ');
	}
	else//-*.*
	{
		res = print_digit_precision(num, res, tags, len);
		width -= res;
		while (width-- > 0)
			res += printf_putchar(' ');
	}
	return (res);
}

int			print_int2(t_tag *tags, va_list list)
{
	int			res;
	intmax_t	num;

	res = 0;
	if (tags->modifier.h)
		num = (short int)va_arg(list, int);
	else if (tags->modifier.hh)
		num = (char)va_arg(list, int);
	else if (tags->modifier.l)
		num = va_arg(list, long);
	else if (tags->modifier.ll)
		num = va_arg(list, long long int);
	else
		num = va_arg(list, int);
	if (tags->flags.left_align)
		res += left_align(tags, num);
	else
		res += without_align(tags, num);
	return (res);
}