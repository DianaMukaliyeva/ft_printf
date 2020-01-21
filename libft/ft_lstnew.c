/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:09:17 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/28 16:32:54 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;
	char	*temp;

	res = (t_list*)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	if (!content)
	{
		res->content = NULL;
		res->content_size = 0;
	}
	else
	{
		if (!(temp = malloc(content_size)))
			return (NULL);
		res->content = ft_memcpy(temp, content, content_size);
		res->content_size = content_size;
	}
	res->next = NULL;
	return (res);
}
