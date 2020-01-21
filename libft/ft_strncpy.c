/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:43:31 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/24 19:05:58 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*temp;
	char	*result;

	result = dest;
	temp = (char*)src;
	while (*temp && len > 0)
	{
		*result++ = *temp++;
		len--;
	}
	while (len > 0)
	{
		*result = '\0';
		result++;
		len--;
	}
	return (dest);
}
