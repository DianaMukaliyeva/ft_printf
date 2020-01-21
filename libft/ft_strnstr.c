/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:45:03 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/17 18:45:04 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*temp;

	temp = needle;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && *temp && len > 0)
	{
		if (*temp == *haystack)
			temp++;
		else
			temp = needle;
		haystack++;
		len--;
	}
	if (*temp == '\0')
		return ((char *)haystack - ft_strlen(needle));
	else
		return (NULL);
}
