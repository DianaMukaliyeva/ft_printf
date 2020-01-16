/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:43:24 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/16 17:47:58 by diana            ###   ########.fr       */
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
	if (num < 0)
	{
		res += printf_putchar('-');
		num *= -1;
		tags->precision.num++;
	}
	else if (num == 0 && tags->flags.left_align == 0 && (tags->flags.sign || tags->flags.space))
		tags->precision.num--;
	if (len < tags->precision.num)
		while (len++ < tags->precision.num)
			res += printf_putchar('0');
	if (tags->precision.num > 0 || num != 0)
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


static int	print_calculate(t_tag *tags, intmax_t num)
{
	int	res;
	int	len;
	int	width;

	res = 0;
	len = get_len(num, tags, 1);
	width = tags->width.num;
	if (tags->precision.is_exist)
	{
		if (tags->flags.left_align)//est minus i precision
		{
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
				if (len < tags->precision.num)
					while (width-- > tags->precision.num)
						res += printf_putchar(' ');
				else
					while (width-- > len)
						res += printf_putchar(' ');
				if (tags->width.num != 0 && tags->precision.num == 0 && num == 0)
					res += printf_putchar(' ');
			}
		}
		else//net minusa, est precision
		{
			if (tags->flags.sign)//+*.*
			{
				// len = get_len(num, tags, 0);
				width--;
				if (len < tags->precision.num)
					while (width-- > tags->precision.num)
						res += printf_putchar(' ');
				else
					while (width-- >= len)
						res += printf_putchar(' ');
				res += print_sign_or_space(&num, '+', 0);
				res = print_digit_precision(num, res, tags, len - 1);
				if (tags->precision.num == 0 && num == 0)
					res += printf_putchar(' ');
			}
			else if (tags->flags.space)// *.*
			{
				width--;
				if (len < tags->precision.num)
					while (width-- > tags->precision.num)
						res += printf_putchar(' ');
				else
					while (width-- >= len)
						res += printf_putchar(' ');
				res += print_sign_or_space(&num, ' ', 0);
				res = print_digit_precision(num, res, tags, len - 1);
				if (tags->precision.num == 0 && num == 0)
					res += printf_putchar(' ');
			}
			else//*.*
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
					if (tags->width.num && tags->precision.num == 0 && num == 0)
						res += printf_putchar(' ');
				}
				else
				{
					width--;
					if (len > tags->precision.num)
						while (width-- >= len)
							res += printf_putchar(' ');
					else
						while (width-- > tags->precision.num)
							res += printf_putchar(' ');
					res += printf_putchar('-');
					num *= -1;
					res = print_digit_precision(num, res, tags, len - 1);
				}
			}
		}
	}
	else//точности нету
	{
		if (tags->flags.left_align)//-
		{
			if (tags->flags.sign)
				res += print_sign_or_space(&num, '+', 1);
			else if (tags->flags.space)
				res += print_sign_or_space(&num, ' ', 1);
			else
				res += printf_putnbr(num);
			width -= res;
			while (width-- > 0)
				res += printf_putchar(' ');
		}
		else//точности нету, просто ширина
		{
			if (tags->flags.zero)//0*
			{
				if (tags->flags.sign)//0+*
				{
					width--;
					res += print_sign_or_space(&num, '+', 0);
					len = get_len(num, tags, 0);
					while (width-- > len)
						res += printf_putchar('0');
					res += printf_putnbr(num);
				}
				else if (tags->flags.space)//0 *
				{
					width--;
					res += print_sign_or_space(&num, ' ', 0);
					len = get_len(num, tags, 0);
					while (width-- > len)
						res += printf_putchar('0');
					res += printf_putnbr(num);
				}
				else//0*
				{
					if (num >= 0)
					{
						while (width-- > len)
							res += printf_putchar('0');
						res += printf_putnbr(num);
					}
					else
					{
						res += printf_putchar('-');
						while (width-- > len)
							res += printf_putchar('0');
						num *= -1;
						res += printf_putnbr(num);
					}
				}
			}
			else// 1| +*||||2| *||||3|*
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
				else
				{
					while (width-- > len)
						res += printf_putchar(' ');
					res += printf_putnbr(num);
				}
			}
		}
	}
	return (res);
}

int			print_int(t_tag *tags, va_list list)
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
		num = va_arg(list, intmax_t);
	else
		num = va_arg(list, int);
	if (tags->width.is_exist || tags->precision.is_exist)
		res += print_calculate(tags, num);
	else if (tags->flags.sign)
		res += print_sign_or_space(&num, '+', 1);
	else if (tags->flags.space)
		res += print_sign_or_space(&num, ' ', 1);
	else
		res += printf_putnbr(num);
	return (res);
}
