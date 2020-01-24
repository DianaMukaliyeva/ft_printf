/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:38 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/24 16:13:58 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_size(intmax_t n)
{
	int	size;
	int	sign;

	sign = n < 0 ? 1 : 0;
	if (n + 1 == -9223372036854775807)
		return (19);
	n = sign == 0 ? n : n * -1;
	size = 0;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size + sign);
}

char	*ft_itoa(intmax_t n)
{
	intmax_t	num;
	char		*res;
	int			size;

	size = get_size(n);
	num = n;
	if (!(res = ft_strnew(size + 1)))
		return (NULL);
	if (num + 1 == -9223372036854775807)
		res = "-9223372036854775808";
	if (num < 0)
		num *= -1;
	while (num >= 10)
	{
		res[size--] = num % 10 + '0';
		num /= 10;
	}
	res[size--] = num + '0';
	if (n < 0)
		res[size] = '-';
	return (res);
}
