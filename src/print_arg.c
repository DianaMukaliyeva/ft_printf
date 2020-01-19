/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:00:47 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/20 01:15:41 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg1(char modifier, t_flag flags, va_list list)
{
	int	res;

	res = 0;
	if (modifier == 's')
		res += print_str2(flags, list);
	else if (modifier == 'c')
		res += print_char(flags, va_arg(list, int));
	else if (modifier == 'p')
		res += print_memory(flags, list);
	return (res);
}

static int	print_arg2(char modifier, t_flag flags, va_list list)
{
	int	res;

	res = 0;
	if (modifier == 'o')
		res += print_octal(flags, list);
	else if (modifier == 'd' || modifier == 'i')
		res += print_int3(flags, list);
	else if (modifier == 'u')
		res += print_unsigned_int(flags, list);
	else if (modifier == 'x')
		res += print_unsigned_low_hex(flags, list);
	else if (modifier == 'X')
		res += print_unsigned_upper_hex(flags, list);
	return (res);
}

static int	print_arg3(char modifier, t_flag flags, va_list list)
{
	int	res;

	res = 0;
	if (modifier == 'f')
		res += print_double(flags, list);
	else if (modifier == 'e')
		res += print_double_with_e(flags, list);
	else if (modifier == 'E')
		res += print_double_with_big_e(flags, list);
	else if (modifier == 'g')
		res += print_double(flags, list);
	else if (modifier == '%')
		res += print_char(flags, '%');
	return (res);
}

int			print_arg(char modifier, t_flag flags, va_list list)
{
	int	res;

	res = 0;
	if (ft_strchr("csp", modifier))
		res += print_arg1(modifier, flags, list);
	else if (ft_strchr("diouxX", modifier))
		res += print_arg2(modifier, flags, list);
	else if (ft_strchr("feEg%%", modifier))
		res += print_arg3(modifier, flags, list);
	return (res);
}
