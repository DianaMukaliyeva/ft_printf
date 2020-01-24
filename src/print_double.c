/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:02:40 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/24 15:34:26 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len_without_sign(uintmax_t num)
{
	int	len;

	len = 1;
	if (num / 10 > 0)
		len += get_len_without_sign(num / 10);
	return (len);
}

static char	*itoa_double_with_precision(long double num, int precision, int hash)
{
	char		*res;
	char		*temp;
	char		*temp2;
	long double	drob;
	long double	copy_drob;
	int			len_after_comma;
	intmax_t	num_before;
	int			prec_copy;

	prec_copy = precision;
	num_before = (intmax_t)num;
	drob = (num - (uintmax_t)num);
	while (drob > 0 && prec_copy-- > 0)
		drob *= 10;
	copy_drob = drob + 0.5;
	// if (get_len_without_sign((uintmax_t)copy_drob) > precision && precision != 0)
	if ((uintmax_t)copy_drob > (uintmax_t)drob && get_len_without_sign((uintmax_t)copy_drob) > precision)
	{
		num_before++;
		// prec_copy = precision - 1;
		copy_drob = 0;
	}
	// printf("\n'%jd\n", (uintmax_t)drob);
	// printf("\n'%d'\n", (int)drob);
	if (((uintmax_t)copy_drob > 0 && (uintmax_t)(copy_drob - (uintmax_t)copy_drob) >= 0.9))
	{
		copy_drob = 0;
		prec_copy = precision - 1;
		num_before++;
	}
	// printf("prec = %d\n", precision);
	res = ft_itoa(num_before);
	if (((uintmax_t)copy_drob > 0) || precision > 0)
	{
		temp = ft_strdup(res);
		free(res);
		res = ft_strjoin(temp, ".");
		ft_strdel(&temp);
		if (copy_drob > 0)
			len_after_comma = get_len_without_sign((uintmax_t)copy_drob);
		else
			len_after_comma = 0;
		if (len_after_comma < precision)
		{
			if (!(temp = ft_strnew(precision - len_after_comma)))
				return (NULL);
			temp = ft_memset(temp, '0', precision - len_after_comma);
			temp2 = ft_strdup(res);
			free(res);
			res = ft_strjoin(temp2, temp);
			ft_strdel(&temp);
			ft_strdel(&temp2);
		}
		if (copy_drob > 0)
		{
			temp = ft_itoa((uintmax_t)copy_drob);
			temp2 = ft_strdup(res);
			free(res);
			res = ft_strjoin(temp2, temp);
			ft_strdel(&temp);
			ft_strdel(&temp2);
		}
	}
	// printf("\n'%Lf\n", drob);
	if (precision == 0 && hash)
	{
		temp = ft_strdup(res);
		free(res);
		res = ft_strjoin(temp, ".");
		ft_strdel(&temp);
	}
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
		str = itoa_double_with_precision(num, flags.precision_num, flags.hash);
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
