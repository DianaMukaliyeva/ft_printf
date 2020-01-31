/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:26 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/28 16:46:17 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>//udalit'

typedef struct		s_flag
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		width_asterisk;
	int		width_num;
	int		precision_exist;
	int		precision_asterisk;
	int		precision_num;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		big_l;
	int		j;
	int		z;
	int		fd;
	char	ident;
}					t_flag;

int					ft_printf(const char *format, ...);
int					fd_printf(int fd, const char *format, ...);
int					parse_flags(va_list list, const char *format,\
					int *i, int fd);
int					print_arg(char modifier, t_flag flags, va_list list);
int					print_char(t_flag flags, char c);
int					print_double(t_flag flags, va_list list);
int					print_int(t_flag flags, va_list list);
int					print_memory(t_flag flags, void *p);
int					print_str(t_flag flags, char *str);
int					print_number_with_flags(char *str, t_flag flags,\
					int negative);
int					print_oux(t_flag flags, uintmax_t num, int base);
int					print_unsigned_num(char *str, t_flag flags,\
					int base, uintmax_t num);
int					printf_putchar(char c, int fd);
int					print_with_flags(char *str, int width, t_flag flags);
char				*str_with_precision(uintmax_t num, t_flag flags, int base);
int					get_len_num(intmax_t num);

#endif
