/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:26 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/10 19:20:06 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	/* data */
}				t_flag;


int		ft_printf(const char *format, ...);
void	start(va_list list, const char *format);
int	is_flag(char c);
int	is_width(char c);
int	is_precision(char c, const char *format, int i);
int	is_modifier(char c);
int	is_type(char c);

#endif