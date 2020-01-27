/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:06:10 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/27 16:42:19 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_sign_to_str(char *str, t_flag flags, int base, uintmax_t num)
{
	char	*res;

	res = NULL;
	if (!str)
		return (NULL);
	if (flags.hash && num != 0 && base == 8)
		res = ft_strjoin("0", str);
	else if (flags.hash && !flags.precision_num && num != 0 && base != 16)
		res = ft_strjoin("0", str);
	else if (flags.hash && num != 0 && base == 16 && flags.ident == 'X')
		res = ft_strjoin("0X", str);
	else if ((flags.hash && num != 0 && base == 16) || flags.ident == 'p')
		res = ft_strjoin("0x", str);
	else
		res = ft_strdup(str);
	return (res);
}

static char	*newstr_fill(size_t zero, size_t len, int can_put_zero)
{
	char	*str;
	size_t	i;
	char	filler;

	if (zero && !can_put_zero)
		filler = '0';
	else
		filler = ' ';
	i = 0;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = filler;
	return (str);
}

static char	*get_full_str2(char *str, t_flag fl, int base, uintmax_t num)
{
	char	*res;
	char	*temp;
	char	*temp2;
	int		len;

	len = ft_strlen(str);
	if (fl.hash && num != 0 && ((!fl.precision_num && base != 16) || base == 8))
		len++;
	else if ((fl.hash && num != 0 && base == 16) || fl.ident == 'p')
		len += 2;
	temp = newstr_fill(fl.zero, fl.width_num - len, fl.precision_exist);
	if (fl.zero && !fl.precision_exist)
	{
		temp2 = ft_strjoin(temp, str);
		res = add_sign_to_str(temp2, fl, base, num);
	}
	else
	{
		temp2 = add_sign_to_str(str, fl, base, num);
		res = ft_strjoin(temp, temp2);
	}
	free(temp2);
	free(temp);
	return (res);
}

static char	*get_full_str(char *str, t_flag flags, int base, uintmax_t num)
{
	char	*res;
	char	*temp;
	char	*temp2;
	int		width;
	int		len;

	len = ft_strlen(str);
	width = flags.width_num;
	if (flags.hash && num != 0 && base == 8)
		len++;
	else if (flags.hash && !flags.precision_num && num != 0 && base != 16)
		len++;
	else if ((flags.hash && num != 0 && base == 16) || flags.ident == 'p')
		len += 2;
	if (flags.minus)
	{
		temp = newstr_fill(flags.zero, width - len, flags.minus);
		temp2 = add_sign_to_str(str, flags, base, num);
		res = ft_strjoin(temp2, temp);
		free(temp2);
		free(temp);
	}
	else
		res = get_full_str2(str, flags, base, num);
	return (res);
}

int			print_unsigned_num(char *str, t_flag flags, int base, uintmax_t num)
{
	int		len;
	int		width;
	char	*res;

	width = flags.width_num;
	len = ft_strlen(str);
	if (flags.hash && num != 0 && base == 8)
		len++;
	else if (flags.hash && !flags.precision_num && num != 0 && base != 16)
		len++;
	else if ((flags.hash && num != 0 && base == 16) || flags.ident == 'p')
		len += 2;
	if (width > len)
		res = get_full_str(str, flags, base, num);
	else
		res = add_sign_to_str(str, flags, base, num);
	if (!res)
		return (-1);
	len = ft_strlen(res);
	write(1, res, len);
	free(res);
	return (len);
}
