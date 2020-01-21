/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:45:49 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/22 16:43:50 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	const char	*copy;
	long		result;
	long		sign;
	long		prev_result;

	sign = 1;
	result = 0;
	copy = str;
	while ((*copy >= 9 && *copy <= 13) || *copy == 32)
		copy++;
	if (*copy == '-' || *copy == '+')
		sign = *copy++ == '-' ? -1 : 1;
	while (*copy >= 48 && *copy <= 57)
	{
		prev_result = result;
		result = result * 10 + (*copy - 48);
		if (prev_result > result)
			return (sign == 1 ? -1 : 0);
		copy++;
	}
	return ((int)result * sign);
}
