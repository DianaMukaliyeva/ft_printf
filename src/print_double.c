/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:02:40 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/02/07 15:41:44 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_double(long double num, int precision)
{
	char	*res;
	char	*temp;
	char	*str_num;

	res = ft_strnew(1);
	while (precision > 0)
	{
		if (!res)
			return (NULL);
		temp = ft_strdup(res);
		free(res);
		num *= 10;
		str_num = ft_itoa((int)num);
		res = ft_strjoin(temp, str_num);
		free(temp);
		free(str_num);
		precision--;
		num = num - (int)num;
	}
	return (res);
}

static void	ft_rounding(long double *num, int precision)
{
	double		round;

	round = 0.5;
	while (precision-- > 0)
		round /= 10;
	*num = *num + round;
}

static char	*get_str_with_precision(long double num, t_flag flags)
{
	char		*str;
	char		*temp;
	char		*str_after_dot;

	if (num < 0)
		num *= -1;
	ft_rounding(&num, flags.precision_num);
	if (!(str = ft_itoa((intmax_t)num)))
		return (NULL);
	if (flags.precision_num == 0 && !flags.hash)
		return (str);
	temp = ft_strdup(str);
	free(str);
	str = ft_strjoin(temp, ".");
	free(temp);
	if (!str)
		return (NULL);
	str_after_dot = itoa_double(num - (intmax_t)num, flags.precision_num);
	temp = ft_strdup(str);
	free(str);
	str = ft_strjoin(temp, str_after_dot);
	free(str_after_dot);
	free(temp);
	return (str);
}

int			print_double(t_flag flags, va_list list)
{
	int			res;
	long double	num;
	char		*print_str;

	res = 0;
	if (flags.big_l)
		num = (long double)va_arg(list, long double);
	else
		num = (long double)va_arg(list, double);
	if (!flags.precision_exist && flags.precision_num == 0)
		flags.precision_num = 6;
	print_str = get_str_with_precision(num, flags);
	if (!print_str)
		return (-1);
	res = print_number_with_flags(print_str, flags, num < 0 ? 1 : 0);
	free(print_str);
	return (res);
}
