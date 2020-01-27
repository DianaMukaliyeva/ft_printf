/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:30:08 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/27 15:01:49 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strncpy(char *dest, const char *src, size_t len);
int					ft_atoi(const char *str);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrev(char *str);
char				*ft_itoa(intmax_t n);

#endif
