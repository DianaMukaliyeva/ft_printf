/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/02/02 16:20:22 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_base(char modifier, t_flag flags, uintmax_t number)
{
	int	base;

	base = 10;
	if (modifier == 'b')
		base = 2;
	else if (modifier == 'o' || modifier == 'O')
		base = 8;
	else if (modifier == 'x' || modifier == 'X')
		base = 16;
	if (modifier == 'U' || modifier == 'O')
		flags.l = 1;
	return (print_oux(flags, number, base));
}

int			print_arg(const char *format, int *i, t_flag flags, va_list list)
{
	char	modifier;

	modifier = format[*i];
	flags.ident = modifier;
	if (modifier == '\0')
		return (0);
	if (modifier == '<')
		if ((int)ft_strlen(format) >= *i + 3)
			return (print_effect(format, i, flags.fd));
	if (ft_strchr("boOuUxX", modifier))
		return (find_base(modifier, flags, va_arg(list, uintmax_t)));
	if (modifier == 'f')
		return (print_double(flags, list));
	if (modifier == 'p')
	{
		flags.ident = modifier;
		return (print_memory(flags, va_arg(list, void *)));
	}
	if (modifier == 's')
		return (print_str(flags, va_arg(list, char*)));
	if (modifier == 'c')
		return (print_char(flags, va_arg(list, int)));
	if (modifier == 'd' || modifier == 'i')
		return (print_int(flags, list));
	return (print_char(flags, modifier));
}
