/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:43:56 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/17 18:43:57 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*result;
	char	*temp;

	temp = (char*)s2;
	result = s1;
	while (*result)
		result++;
	while (*temp && n > 0)
	{
		n--;
		*result++ = *temp++;
	}
	*result = '\0';
	return (s1);
}
