/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:20 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/28 19:15:10 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*res;
	unsigned int	start;
	unsigned int	end;
	unsigned char	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == '\n' || s[start] == ' ' || s[start] == '\t')
		start++;
	if (start == size)
		return ("");
	while (end > 0 && (s[end] == '\n' || s[end] == '\t' || s[end] == ' '))
		end--;
	res = (char*)ft_memalloc(end - start + 1);
	if (!res)
		return (NULL);
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
