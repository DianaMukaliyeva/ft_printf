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
	}
	if (tags->precision.num != 0 || num != 0)
		res += printf_putnbr(num);
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
		if (tags->flags.left_align)//-*.*
		{
			if (tags->flags.sign)//-+*.*
			{
				width--;
				if (num >= 0)
					res += printf_putchar('+');
				else
				{
					res += printf_putchar('-');
					num *= -1;
				}
				len = get_len(num);
				res = print_digit(num, res, tags, len);
				width -= res;
				while (width-- >= 0)
					res += printf_putchar(' ');
			}
			else if(tags->flags.space)//- *.*
			{
				if (num >= 0)
					res += printf_putchar(' ');
				else
				{
					res += printf_putchar('-');
					num *= -1;
				}
				len = get_len(num);
				res = print_digit(num, res, tags, len);
				width -= res;
				while (width-- > 0)
					res += printf_putchar(' ');
			}
			else//-*.*
			{
				res = print_digit(num, res, tags, len);
				while (width-- > tags->precision.num)
					res += printf_putchar(' ');
			}
		}
		else
		{
			if (tags->flags.sign)//+*.*
			{
				width--;
				while (width-- > len)
					res += printf_putchar(' ');
				if (num >= 0)
					res += printf_putchar('+');
				else
				{
					res += printf_putchar('-');
					num *= -1;
				}
				res = print_digit(num, res, tags, len - 1);
				if (tags->precision.num == 0 && num == 0)
					res += printf_putchar(' ');
			}
			else if (tags->flags.space)// *.*
			{
				width--;
				while (width-- > len)
					res += printf_putchar(' ');
				if (num >= 0)
					res += printf_putchar(' ');
				else
				{
					res += printf_putchar('-');
					num *= -1;
				}
				res = print_digit(num, res, tags, len - 1);
				if (tags->precision.num == 0 && num == 0)
					res += printf_putchar(' ');
			}
			else//*.*
			{
				if (num >=0)
				{
					if (len > tags->precision.num)
						while (width-- > len)
							res += printf_putchar(' ');
					else
						while (width-- > tags->precision.num)
							res += printf_putchar(' ');
					res = print_digit(num, res, tags, len);
					if (tags->precision.num == 0 && num == 0)
						res += printf_putchar(' ');
				}
				else
				{
					width--;
					if (len > tags->precision.num)
						while (width-- > len)
							res += printf_putchar(' ');
					else
						while (width-- > tags->precision.num)
							res += printf_putchar(' ');
					res += printf_putchar('-');
					num *= -1;
					res = print_digit(num, res, tags, len - 1);
				}
			}
		}
	}
	else//точности нету
	{
		if (tags->flags.left_align)//-
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
		else//точности нету, просто ширина
		{
			if (tags->flags.zero)//0*
			{
				if (tags->flags.sign)//0+*
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
						num *= -1;
					}
					len = get_len(num);
					while (width-- > len)
						res += printf_putchar('0');
					res += printf_putnbr(num);
				}
				else if (tags->flags.space)//0 *
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
						num *= -1;
					}
					len = get_len(num);
					while (width-- > len)
						res += printf_putchar('0');
					res += printf_putnbr(num);
				}
				else//0*
				{
					if (num >=0)
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
			else//*
			{
				if (tags->flags.sign)//+*
				{
					while (width-- > len)
						res += printf_putchar(' ');
					if (num >= 0)
						res += printf_putchar('+');
					res += printf_putnbr(num);
				}
				else if (tags->flags.space)// *
				{
					while (width-- > len)
						res += printf_putchar(' ');
					if (num >= 0)
						res += printf_putchar(' ');
					res += printf_putnbr(num);
				}
				else//*
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

static int print_int_with_precision(t_tag *tags, long long num)
{
	int	res;
	int	len;

	res = 0;
	len = get_len(num);
	if (num > 0 && (tags->flags.sign || tags->flags.space))
		len++;
	if (tags->precision.num)
	{
		if (num < 0)
		{
			res += printf_putchar('-');
			num *= -1;
			res = print_digit(num, res, tags, len - 1);
		}
		else
			res = print_digit(num, res, tags, len);
	}
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
		num = va_arg(list, long);
	else if (tags->modifier.ll)
	{
		num = va_arg(list, long long);
		//podumat' chto sdelat'. mozhet voobshe otdel'nuyu funkciyu ili vezde dobavit kod gde umnozhayu na -1
		if (num + 1 == -9223372036854775807)
		{
			res += printf_putchar('-');
			res += printf_putchar('9');
			num = 223372036854775808;
		}
	}
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
