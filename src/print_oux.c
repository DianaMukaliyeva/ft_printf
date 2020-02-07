/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:40:59 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/27 15:33:30 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_oux(t_flag flags, uintmax_t num, int base)
{
	int		res;
	char	*print_str;

	res = 0;
	if (flags.z)
		num = (size_t)num;
	else if (flags.j)
		num = (uintmax_t)num;
	else if (flags.l)
		num = (unsigned long)num;
	else if (flags.ll)
		num = (unsigned long long)num;
	else if (flags.h)
		num = (unsigned short int)num;
	else if (flags.hh)
		num = (unsigned char)num;
	else
		num = (unsigned int)num;
	print_str = str_with_precision(num, flags, base);
	if (!print_str)
		return (-1);
	res = print_unsigned_num(print_str, flags, base, num);
	free(print_str);
	return (res);
}
