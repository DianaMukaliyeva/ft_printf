/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:46:33 by diana             #+#    #+#             */
/*   Updated: 2020/01/23 17:55:42 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len_without_sign(intmax_t num)
{
	int	len;

	len = 1;
	if (num < 0)
		num *= -1;
	if (num + 1 == -9223372036854775807)
		return (19);
	if (num / 10 > 0)
		len += get_len_without_sign(num / 10);
	return (len);
}

static char	*itoa_positive(intmax_t num)
{
	char	*str;

	if (num + 1 == -9223372036854775807)
		str = ft_strdup("9223372036854775808");
	else
	{
		num < 0 ? num *= -1 : 0;
		str = ft_itoa(num);
		if (!str)
			return (NULL);
	}
	return (str);
}

static char	*get_str_with_precision(intmax_t num, t_flag flags)
{
	char	*str;
	char	*temp;
	char	*str_temp;
	int		len;

	len = get_len_without_sign(num);
	if (num == 0 && flags.precision_exist && flags.precision_num == 0)
		str = ft_strnew(1);
	else
		str = itoa_positive(num);
	if (!str)
		return (NULL);
	if (flags.precision_num > len)
	{
		if (!(temp = ft_strnew(flags.precision_num - len)))
			return (NULL);
		temp = ft_memset(temp, '0', flags.precision_num - len);
		if (!(str_temp = ft_strjoin(temp, str)))
			return (NULL);
		free(str);
		free(temp);
		return (str_temp);
	}
	return (str);
}

int			print_int(t_flag flags, va_list list)
{
	int			res;
	intmax_t	num;
	char		*print_str;

	res = 0;
	if (flags.z)
		num = (size_t)va_arg(list, intmax_t);
	else if (flags.j)
		num = va_arg(list, intmax_t);
	else if (flags.l)
		num = (long int)va_arg(list, intmax_t);
	else if (flags.ll)
		num = (long long int)va_arg(list, intmax_t);
	else if (flags.h)
		num = (short int)va_arg(list, intmax_t);
	else if (flags.hh)
		num = (char)va_arg(list, intmax_t);
	else
		num = va_arg(list, int);
	print_str = get_str_with_precision(num, flags);
	if (!print_str)
		return (-1);
	res = print_number_with_flags(print_str, flags, num < 0 ? 1 : 0);
	free(print_str);
	return (res);
}
