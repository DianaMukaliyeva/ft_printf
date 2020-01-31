/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_with_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:47:07 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/29 18:44:18 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len_without_sign(uintmax_t num, int base)
{
	int	len;

	len = 1;
	while ((num /= base) > 0)
		len++;
	return (len);
}

static void	ft_itoa_base(uintmax_t num, char *str, uintmax_t base, char ident)
{
	char	*big_hex;
	char	*small_hex;
	char	*temp;

	temp = str;
	big_hex = "0123456789ABCDEF";
	small_hex = "0123456789abcdef";
	if (num == 0)
	{
		*temp = '0';
		return ;
	}
	while (num > 0)
	{
		if (ident == 'X')
			*temp++ = big_hex[num % base];
		else
			*temp++ = small_hex[num % base];
		num = num / base;
	}
	str = ft_strrev(str);
}

static char	*get_str_with_precision(char *str, int precision, int len)
{
	char	*temp;
	char	*str_temp;

	temp = ft_strnew(precision - len);
	if (!temp)
		return (NULL);
	temp = ft_memset(temp, '0', precision - len);
	if (!(str_temp = ft_strjoin(temp, str)))
		return (NULL);
	free(str);
	free(temp);
	return (str_temp);
}

char		*str_with_precision(uintmax_t num, t_flag flags, int base)
{
	char	*str;
	int		len;

	len = get_len_without_sign(num, base);
	if (num == 0 && flags.precision_exist && flags.precision_num == 0\
	&& base != 8)
		str = ft_strnew(1);
	else if (!flags.hash && num == 0 && flags.precision_exist &&\
	flags.precision_num == 0)
		str = ft_strnew(1);
	else
	{
		str = ft_strnew(len + 1);
		if (!str)
			return (NULL);
		ft_itoa_base(num, str, base, flags.ident);
	}
	if (base == 8 && flags.hash && num != 0)
		len++;
	if (!str)
		return (NULL);
	if (flags.precision_num > len)
		return (get_str_with_precision(str, flags.precision_num, len));
	return (str);
}
