/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:44:52 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/21 19:36:05 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*temp;
	const char	*str;

	temp = needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		str = haystack;
		while (*str && *temp)
		{
			if (*temp == *str)
				temp++;
			else
				temp = needle;
			str++;
		}
		if (*temp == '\0')
			return ((char *)str - ft_strlen(needle));
		haystack++;
	}
	return (NULL);
}
