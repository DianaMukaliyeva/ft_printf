/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 21:11:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/24 18:07:03 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_other_flags(t_flag *flags, char symbol)
{
	if (ft_strchr("-+ #", symbol))
		flags->precision_num = 0;
	symbol == '-' ? flags->minus = 1 : 0;
	symbol == '+' ? flags->plus = 1 : 0;
	symbol == ' ' ? flags->space = 1 : 0;
	symbol == '#' ? flags->hash = 1 : 0;
	if (symbol == 'h')
	{
		flags->hh = flags->h == 1 ? 1 : 0;
		flags->h = flags->h == 1 ? 0 : 1;
	}
	else if (symbol == 'l')
	{
		flags->big_l = 0;
		flags->ll = flags->l == 1 ? 1 : 0;
		flags->l = flags->l == 1 ? 0 : 1;
	}
	else if (symbol == 'L')
		flags->big_l = (flags->big_l || flags->l) ? 0 : 1;
	symbol == 'j' ? flags->j = 1 : 0;
	symbol == 'z' ? flags->z = 1 : 0;
}

static void		fill_wildcard(t_flag *flags, va_list list)
{
	int	num;

	num = va_arg(list, int);
	if (flags->precision_exist)
	{
		flags->precision_asterisk = 1;
		if (num >= 0)
			flags->precision_num = num;
		else
		{
			flags->precision_exist = 0;
			flags->precision_num = 0;
		}
	}
	else
	{
		if (num < 0)
		{
			num *= -1;
			flags->minus = 1;
		}
		flags->width_asterisk = 1;
		flags->width_num = num;
	}
}

static void		fill_numbers(t_flag *flags, char symbol, va_list list)
{
	if (symbol == '0' && !flags->precision_exist && !flags->width_num)
		flags->zero = 1;
	else if (symbol == '*')
		fill_wildcard(flags, list);
	else if (flags->precision_exist)
	{
		if (flags->precision_asterisk == 1)
		{
			flags->precision_asterisk = 0;
			flags->precision_num = 0;
		}
		flags->precision_num = flags->precision_num * 10 + symbol - 48;
	}
	else
	{
		if (flags->width_asterisk == 1)
		{
			flags->width_asterisk = 0;
			flags->width_num = 0;
		}
		flags->width_num = flags->width_num * 10 + symbol - 48;
	}
}

static t_flag	get_empty_flags(void)
{
	t_flag	flags;

	flags.hash = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.big_l = 0;
	flags.j = 0;
	flags.z = 0;
	flags.precision_exist = 0;
	flags.precision_asterisk = 0;
	flags.precision_num = 0;
	flags.width_asterisk = 0;
	flags.width_num = 0;
	return (flags);
}

int				parse_flags(va_list list, const char *format, int *i, int fd)
{
	t_flag	flags;
	int		res;

	flags = get_empty_flags();
	flags.fd = fd;
	while (format[++(*i)])
	{
		if (format[(*i)] == '.')
		{
			flags.precision_exist = 1;
			flags.precision_num = 0;
		}
		else if (ft_strchr("1234567890*", format[(*i)]))
			fill_numbers(&flags, format[(*i)], list);
		else if (ft_strchr("-+ #hlLjzt$", format[(*i)]))
			fill_other_flags(&flags, format[(*i)]);
		else
			break ;
	}
	res = print_arg(format[*i], flags, list);
	return (res);
}
