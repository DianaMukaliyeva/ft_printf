/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:43:43 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/27 15:59:00 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*result;
	char	*temp;

	temp = (char*)s2;
	result = s1;
	while (*result)
		result++;
	while (*temp)
	{
		*result = *temp;
		temp++;
		result++;
	}
	*result = '\0';
	return (s1);
}
