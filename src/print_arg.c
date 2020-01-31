/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/28 17:17:05 by dmukaliy         ###   ########.fr       */
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

int			print_arg(char modifier, t_flag flags, va_list list)
{
	flags.ident = modifier;
	if (modifier == '\0')
		return (0);
	else if (ft_strchr("boOuUxX", modifier))
		return (find_base(modifier, flags, va_arg(list, uintmax_t)));
	else if (modifier == 'f')
		return (print_double(flags, list));
	else if (modifier == 'p')
	{
		flags.ident = modifier;
		return (print_memory(flags, va_arg(list, void *)));
	}
	else if (modifier == 's')
		return (print_str(flags, va_arg(list, char*)));
	else if (modifier == 'c')
		return (print_char(flags, va_arg(list, int)));
	else if (modifier == 'd' || modifier == 'i')
		return (print_int(flags, list));
	else
		return (print_char(flags, modifier));
}
