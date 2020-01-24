/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/24 18:49:46 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_base(char modifier, t_flag flags, uintmax_t number)
{
	int	base;
	int	is_big_x;

	base = 10;
	is_big_x = modifier == 'X' ? 1 : 0;
	if (modifier == 'o' || modifier == 'O')
		base = 8;
	else if (modifier == 'x' || modifier == 'X')
		base = 16;
	if (modifier == 'U' || modifier == 'O')
		flags.l = 1;
	return (print_unsigned_num(flags, number, base, is_big_x));
}

int			print_arg(char modifier, t_flag flags, va_list list)
{
	if (modifier == '\0')
		return (0);
	else if (ft_strchr("oOuUxX", modifier))
		return (find_base(modifier, flags, va_arg(list, uintmax_t)));
	else if (modifier == 'f')
		return (print_double(flags, list));
	else if (modifier == 's')
		return (print_str(flags, va_arg(list, char*)));
	else if (modifier == 'c')
		return (print_char(flags, va_arg(list, int)));
	else if (modifier == 'p')
		return (print_memory(flags, va_arg(list, void *)));
	else if (modifier == 'd' || modifier == 'i')
		return (print_int(flags, list));
	else
		return (print_char(flags, modifier));
}
