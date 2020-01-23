/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 21:11:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/23 22:20:43 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_other_flags(t_flag *flags, char symbol)
{
	if (ft_strchr("-+ #", symbol))
		flags->precision_num = 0;
	if (symbol == '-')
		flags->minus = 1;
	else if (symbol == '+')
		flags->plus = 1;
	else if (symbol == ' ')
		flags->space = 1;
	else if (symbol == '#')
		flags->hash = 1;
	else if (symbol == 'h')
	{
		if (flags->h == 1)
		{
			flags->h = 0;
			flags->hh = 1;
		}
		else
			flags->h = 1;
	}
	else if (symbol == 'l')
	{
		// flags->h = 0;
		// flags->hh = 0;
		if (flags->l == 1)
		{
			flags->l = 0;
			flags->ll = 1;
		}
		else
			flags->l = 1;
	}
	else if (symbol == 'L')
	// {
	// 	flags->h = 0;
	// 	flags->hh = 0;
	// 	flags->l = 0;
	// 	flags->ll = 0;
		flags->big_l = 1;
	// }
	symbol == 'j' ? flags->j = 1 : 0;
	symbol == 'z' ? flags->z = 1 : 0;
	/* else if (symbol == 'j')
		flags->j = 1;
	else if (symbol == 'z')
		flags->z = 1; */
	// else if (!ft_strchr("$t", symbol))
	// 	return (0);
	// return (1);
}

static void	fill_numbers(t_flag *flags, char symbol, va_list list)
{
	int	num;

	if (symbol == '0' && !flags->precision_exist && !flags->width_num)
		flags->zero = 1;
	else if (symbol == '*')
	{
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
	// return (1);
}

/* static int		fill_flags(t_flag *flags, char symbol, va_list list)
{
	if (symbol == '.')
	{
		flags->precision_exist = 1;
		flags->precision_num = 0;
		return (1);
	}
	else if (ft_strchr("1234567890*", symbol))
		return (fill_numbers(flags, symbol, list));
	else
		return (fill_other_flags(flags, symbol));
} */

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
	// flags.width_exist = 0;
	flags.width_asterisk = 0;
	flags.width_num = 0;
	return (flags);
}

int				parse_flags(va_list list, const char *format, int *i)
{
	t_flag	flags;
	int		res;

	flags = get_empty_flags();
	/* while (format[++(*i)] && fill_flags(&flags, format[(*i)], list))
		continue ;
	if (format[(*i)])
		res = print_arg(format[*i], flags, list); */
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
			break;
	}
	res = print_arg(format[*i], flags, list);
	/* while (format[++(*i)])
	{
		if (fill_flags(&flags, format[*i], list))
			continue ;
		else
			res = print_arg(format[*i], flags, list);
		break ;
	} */
	return (res);
}
