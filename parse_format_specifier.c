/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format_specifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 21:11:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 21:44:15 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			is_type(char c)
{
	const char	*flags = "cspdiouxXf";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

static t_identifier	*create_identifier(void)
{
	t_identifier	*identifiers;

	identifiers = malloc(sizeof(t_identifier));
	identifiers->flags.hash = 0;
	identifiers->flags.left_align = 0;
	identifiers->flags.sign = 0;
	identifiers->flags.space = 0;
	identifiers->flags.zero = 0;
	identifiers->modifier.h = 0;
	identifiers->modifier.hh = 0;
	identifiers->modifier.l = 0;
	identifiers->modifier.ll = 0;
	identifiers->modifier.big_l = 0;
	identifiers->precision.is_precision = 0;
	identifiers->precision.asterisk = 0;
	identifiers->precision.num = 0;
	identifiers->width.is_width = 0;
	identifiers->width.asterisk = 0;
	identifiers->width.width = 0;
	return (identifiers);
}

int					parse_specifiers(va_list list, const char *format, int *i)
{
	t_identifier	*identifiers;
	int				res;

	res = 0;
	identifiers = create_identifier();
	while (format[++(*i)])
	{
		if (is_type(format[*i]))
			res += print_arg(format[*i], identifiers, list);
		else if (fill_identifiers(identifiers, format[*i], list))
			continue ;
		else
			res += printf_putchar(format[*i]);
		break ;
	}
	free(identifiers);
	return (res);
}
