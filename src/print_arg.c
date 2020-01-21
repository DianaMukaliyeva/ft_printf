/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/21 12:31:43 by dmukaliy         ###   ########.fr       */
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
	if (modifier == 'o')
		return (print_octal(flags, list));
	else if (modifier == 'u')
		return (print_unsigned_int(flags, list));
	else if (modifier == 'U')
	{
		flags.l = 1;
		return (print_unsigned_int(flags, list));
	}
	else if (modifier == 'x')
		return (print_unsigned_low_hex(flags, list));
	else if (modifier == 'X')
		return (print_unsigned_upper_hex(flags, list));
	return (0);
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
	else if (ft_strchr("ouUxX", modifier))
		return (print_arg2(modifier, flags, list));
	else
		return (print_arg3(modifier, flags, list));
}
