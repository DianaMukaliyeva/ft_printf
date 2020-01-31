/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:02:40 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/31 20:16:10 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*put_num_to_str(char *res, long double drob, int precision, int len)
{
	char		*temp;
	char		*temp2;
	int			prec_copy;
	// int			count;

	// if (precision > 18)
	// {
	// 	prec_copy = 18;
	// 	count = 0;
	// }
	// else
		prec_copy = precision;
	if (len < prec_copy)
	{
		if (!(temp = ft_strnew(prec_copy - len)))
			return (NULL);
		temp = ft_memset(temp, '0', prec_copy - len);
		temp2 = ft_strdup(res);
		free(res);
		res = ft_strjoin(temp2, temp);
		ft_strdel(&temp);
		ft_strdel(&temp2);
	}
	if (drob > 0)
	{
		temp = ft_itoa((uintmax_t)drob);
		temp2 = ft_strdup(res);
		free(res);
		res = ft_strjoin(temp2, temp);
		ft_strdel(&temp);
		ft_strdel(&temp2);
	}
	// if (precision > 18)
	// {
	// 	drob = drob - (uintmax_t)drob;
	// 	while (precision != prec_copy)
	// 	{
	// 		drob *= 10;
	// 		precision--;
	// 		count++;
	// 	}
	// 	if (drob > 0)
	// 		res = put_num_to_str(res, drob, count, get_len_num((uintmax_t)drob));
	// 	else
	// 		res = put_num_to_str(res, drob, count, 0);

	// }
	return (res);
}

static char	*get_drob_part(char *res, long double drob, int precision, int hash)
{
	char		*temp;
	int			len_after_comma;

	if (((uintmax_t)drob > 0) || precision > 0)
	{
		temp = ft_strdup(res);
		free(res);
		res = ft_strjoin(temp, ".");
		ft_strdel(&temp);
		if (drob > 0)
			len_after_comma = get_len_num((uintmax_t)drob);
		else
			len_after_comma = 0;
		res = put_num_to_str(res, drob, precision, len_after_comma);
	}
	if (precision == 0 && hash)
	{
		temp = ft_strdup(res);
		free(res);
		res = ft_strjoin(temp, ".");
		ft_strdel(&temp);
	}
	return (res);
}

static char	*itoa_double_with_prec(long double num, int precision, int hash)
{
	char		*res;
	long double	drob;
	long double	copy_drob;
	intmax_t	num_before;
	int			prec_copy;

	// if (precision > 18)
	// 	prec_copy = 18;
	// else
		prec_copy = precision;
	num_before = (intmax_t)num;
	drob = (num - (uintmax_t)num);
	while (drob > 0 && prec_copy-- > 0)
		drob *= 10;
		copy_drob = drob + 0.5;
	if (((int)copy_drob > (int)drob && get_len_num((int)copy_drob) > precision)\
		|| ((int)copy_drob > 0 && (int)(copy_drob - (int)copy_drob) >= 0.9))
	{
		num_before++;
		copy_drob = 0;
	}
	res = ft_itoa(num_before);
	if (!res)
		return (NULL);
		// printf(" double = %Lf\n", drob);
	if (drob > 0)
		res = get_drob_part(res, copy_drob, precision, hash);
	else
		res = get_drob_part(res, drob, precision, hash);
	return (res);
}

static char	*get_str_with_precision(long double num, t_flag flags)
{
	char	*str;

	if (num < 0)
		num *= -1;
	if (num == 0 && flags.precision_exist && flags.precision_num == 0)
		str = ft_strnew(1);
	else
		str = itoa_double_with_prec(num, flags.precision_num, flags.hash);
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
