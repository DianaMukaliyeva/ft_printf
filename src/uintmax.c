/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uintmax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:47:07 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/23 13:03:27 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len_without_sign(uintmax_t num, int base)
{
	int	len;

	len = 1;
	if (num / base > 0)
		len += get_len_without_sign(num / base, base);
	return (len);
}

static void	ft_itoa_base(uintmax_t num, char *str, uintmax_t base, int is_big_x, int *i)
{
	char	*big_hex;
	char	*small_hex;

	big_hex = "0123456789ABCDEF";
	small_hex = "0123456789abcdef";
	if (num == 0)
		str[*i] = '0';
	else if (num >= base)
	{
		ft_itoa_base(num / base, str, base, is_big_x, i);
	}
	if (is_big_x && num != 0)
		str[(*i)++] = big_hex[num % base];
	else if (num != 0)
		str[(*i)++] = small_hex[num % base];
}

static char	*get_str_with_precision(uintmax_t num, t_flag flags, int base, int is_big_x)
{
	char	*str;
	char	*temp;
	char	*str_temp;
	int		len;
	int		i;

	i = 0;
	len = get_len_without_sign(num, base);
	if (num == 0 && flags.precision_exist && flags.precision_num == 0 && base != 8)
		str = ft_strnew(1);
	else if (!flags.hash && num == 0 && flags.precision_exist && flags.precision_num == 0)
		str = ft_strnew(1);
	else
	{
		str = ft_strnew(len + 1);
		ft_itoa_base(num, str, base, is_big_x, &i);
	}
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

int			print_unsigned_num(t_flag flags, uintmax_t num, int base, int is_big_x)
{
	int			res;
	char		*print_str;

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
	print_str = get_str_with_precision(num, flags, base, is_big_x);
	if (!print_str)
		return (-1);
	res = print_unsigned_number(print_str, flags, base, num, is_big_x);
	free(print_str);
	return (res);
}
