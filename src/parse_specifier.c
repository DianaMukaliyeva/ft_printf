/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 21:11:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/19 17:24:17 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_type(char c)
{
	const char	*flags = "cspdiouxXf%%";

	if (ft_strchr(flags, c) != NULL)
		return (1);
	return (0);
}

static t_tag	*create_tag(void)
{
	t_tag	*tags;

	tags = malloc(sizeof(t_tag));
	tags->flags.hash = 0;
	tags->flags.left_align = 0;
	tags->flags.sign = 0;
	tags->flags.space = 0;
	tags->flags.zero = 0;
	tags->modifier.h = 0;
	tags->modifier.hh = 0;
	tags->modifier.l = 0;
	tags->modifier.ll = 0;
	tags->modifier.big_l = 0;
	tags->precision.is_exist = 0;
	tags->precision.asterisk = 0;
	tags->precision.num = 0;
	tags->width.is_exist = 0;
	tags->width.asterisk = 0;
	tags->width.num = 0;
	return (tags);
}

int				parse_specifiers(va_list list, const char *format, int *i)
{
	t_tag	*tags;
	int		res;

	res = 0;
	tags = create_tag();
	//etu funkciyu mozhno sovmestit' s refill tags
	while (format[++(*i)])
	{
		if (is_type(format[*i]))
			res += print_arg(format[*i], tags, list);
		else if (refill_tags(tags, format[*i], list))
			continue ;
		else
			res += print_char(tags, format[*i]);
		break ;
	}
	free(tags);
	return (res);
}
