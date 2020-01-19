/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:26 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/20 01:41:49 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>


#include <stdio.h>

typedef struct		s_flag
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	hash;
	int	width_exist;
	int	width_asterisk;
	int	width_num;
	int	precision_exist;
	int	precision_asterisk;
	int	precision_num;
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	big_l;
}					t_flag;

int					ft_printf(const char *format, ...);
char				*ft_strchr(const char *str, int ch);
int					ft_strlen(const char *str);
int					parse_flags(va_list list, const char *format, int *i);
int					print_arg(char modifier, t_flag flags, va_list list);
int					print_char(t_flag flags, char c);
int					print_double_with_big_e(t_flag flags, va_list list);
int					print_double_with_e(t_flag flags, va_list list);
int					print_double(t_flag flags, va_list list);
int					print_hex(uintmax_t num, int big);
int					print_int3(t_flag flags, va_list list);
int					print_memory(t_flag flags, va_list list);
int					print_percent(void);
int					print_str2(t_flag flags, va_list list);
int					print_unsigned_int(t_flag flags, va_list list);
int					print_unsigned_low_hex(t_flag flags, va_list list);
int					print_octal(t_flag flags, va_list list);
int					print_unsigned_upper_hex(t_flag flags, va_list list);
int					printf_putchar(char c);
int					printf_putnbr(uintmax_t n, int base);
int					printf_putstr(char const *str);

#endif
