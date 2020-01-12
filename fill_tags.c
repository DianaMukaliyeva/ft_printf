/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:58:35 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 22:59:14 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		fill_flags(t_tag *tags, char symbol)
{
	if (symbol == '-')
		tags->flags.left_align = 1;
	else if (symbol == '+')
		tags->flags.sign = 1;
	else if (symbol == ' ')
		tags->flags.space = 1;
	else if (symbol == '#')
		tags->flags.hash = 1;
	else if (symbol == '0')
		if (!(tags->precision.is_exist) &&\
		!(tags->width.is_exist) && !(tags->flags.left_align))
			tags->flags.zero = 1;
}

static void		fill_modifiers(t_tag *tags, char symbol)
{
	if (symbol == 'h')
	{
		if (tags->modifier.h == 1)
		{
			tags->modifier.h = 0;
			tags->modifier.hh = 1;
		}
		else
			tags->modifier.h = 1;
	}
	else if (symbol == 'l')
	{
		if (tags->modifier.l == 1)
		{
			tags->modifier.l = 0;
			tags->modifier.ll = 1;
		}
		else
			tags->modifier.l = 1;
	}
	else if (symbol == 'L')
		tags->modifier.big_l = 1;
}

static void		fill_amount(t_amount_char *amount, char symbol, va_list list)
{
	amount->is_exist = 1;
	if (symbol == '*')
	{
		amount->asterisk = 1;
		amount->num = va_arg(list, int);
	}
	else
		amount->num = amount->num * 10 + symbol - 48;
}

int				fill_tags(t_tag *tags, char symbol, va_list list)
{
	const char	*flags = "+- 0#";
	const char	*numbers = "1234567890*";
	const char	*modifiers = "hlL";

	if (ft_strchr(numbers, symbol))
		if (tags->precision.is_exist == 1)
			fill_amount(&tags->precision, symbol, list);
		else if (tags->width.is_exist == 0 && symbol == '0')
			fill_flags(tags, symbol);
		else
			fill_amount(&tags->width, symbol, list);
	else if (ft_strchr(flags, symbol))
		fill_flags(tags, symbol);
	else if (ft_strchr(modifiers, symbol))
		fill_modifiers(tags, symbol);
	else if (symbol == '.')
		tags->precision.is_exist = 1;
	else
		return (0);
	return (1);
}
