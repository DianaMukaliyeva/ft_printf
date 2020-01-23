/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/23 21:42:03 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg1(char modifier, t_flag flags, va_list list)
{
	if (modifier == 's' || modifier == 'S')
		return (print_str(flags, list));
	else if (modifier == 'c' || modifier == 'C')
		return (print_char(flags, va_arg(list, int)));
	else if (modifier == 'p')
		return (print_memory(flags, va_arg(list, void *)));
	else if (modifier == 'd' || modifier == 'i')
		return (print_int(flags, list));
	return (0);
}

static int	print_arg2(char modifier, t_flag flags, va_list list)
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
	return (print_unsigned_num(flags, va_arg(list, uintmax_t), base, is_big_x));
}

static int	print_arg3(char modifier, t_flag flags, va_list list)
{
	if (modifier == 'f')
		return (print_double(flags, list));
	else if (modifier == 'e')
		return (print_double_with_e(flags, list));
	else if (modifier == 'E')
		return (print_double_with_big_e(flags, list));
	else if (modifier == 'g')
		return (print_double(flags, list));
	return (0);
}

int			print_arg(char modifier, t_flag flags, va_list list)
{
	if (ft_strchr("cCdisSp", modifier))
		return (print_arg1(modifier, flags, list));
	else if (ft_strchr("oOuUxX", modifier))
		return (print_arg2(modifier, flags, list));
	else if (ft_strchr("feEg", modifier))
		return (print_arg3(modifier, flags, list));
	else
		return (print_char(flags, modifier));
}
