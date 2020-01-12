/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_identifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 21:45:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 22:15:55 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_flags(t_identifier *identifiers, char symbol)
{
	if (symbol == '-')
		identifiers->flags.left_align = 1;
	else if (symbol == '+')
		identifiers->flags.sign = 1;
	else if (symbol == ' ')
		identifiers->flags.space = 1;
	else if (symbol == '#')
		identifiers->flags.hash = 1;
	else if (symbol == '0')
		if (!(identifiers->precision.is_precision) &&\
		!(identifiers->width.is_width) && !(identifiers->flags.left_align))
			identifiers->flags.zero = 1;
}

static void		fill_modifiers(t_identifier *identifiers, char symbol)
{
	if (symbol == 'h')
	{
		if (identifiers->modifier.h == 1)
		{
			identifiers->modifier.h = 0;
			identifiers->modifier.hh = 1;
		}
		else
			identifiers->modifier.h = 1;
	}
	else if (symbol == 'l')
	{
		if (identifiers->modifier.l == 1)
		{
			identifiers->modifier.l = 0;
			identifiers->modifier.ll = 1;
		}
		else
			identifiers->modifier.l = 1;
	}
	else if (symbol == 'L')
		identifiers->modifier.big_l = 1;
}

static void		fill_precision(t_identifier *identifiers, char symbol, va_list list)
{
	if (symbol == '*')
	{
		identifiers->precision.asterisk = 1;
		identifiers->precision.num = va_arg(list, int);
	}
}

static void		fill_width(t_identifier *identifiers, char symbol, va_list list)
{
	if (symbol == '*')
	{
		identifiers->width.asterisk = 1;
		identifiers->width.width = va_arg(list, int);
	}
}

int				fill_identifiers(t_identifier *identifiers, char symbol, va_list list)
{
	const char	*flags = "+- 0#";
	const char	*numbers = "1234567890*";
	const char	*modifiers = "hlL";

	if (ft_strchr(flags, symbol))
		fill_flags(identifiers, symbol);
	else if (ft_strchr(modifiers, symbol))
		fill_modifiers(identifiers, symbol);
	else if (symbol == '.')
		identifiers->precision.is_precision = 1;
	else if (ft_strchr(numbers, symbol))
		if (identifiers->precision.is_precision == 1)
			fill_precision(identifiers, symbol, list);
		else
			fill_width(identifiers, symbol, list);
	else
		return (0);
	return (1);
}
