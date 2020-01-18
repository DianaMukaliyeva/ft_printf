/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diana <diana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:26 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/18 19:07:20 by diana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

typedef struct		s_flag
{
	int	left_align;
	int	sign;
	int	space;
	int	zero;
	int	hash;
}					t_flag;

typedef struct		s_amount_char
{
	int	is_exist;
	int	num;
	int	asterisk;
}					t_amount_char;

typedef struct		s_modifier
{
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	big_l;
}					t_modifier;

typedef struct		s_tag
{
	t_flag			flags;
	t_amount_char	width;
	t_amount_char	precision;
	t_modifier		modifier;
}					t_tag;

int					ft_printf(const char *format, ...);
char				*ft_strchr(const char *str, int ch);
int					ft_strlen(const char *str);
int					parse_specifiers(va_list list, const char *format, int *i);
int					print_arg(char modifier, t_tag *tags, va_list list);
int					print_char(t_tag *tags, char c);
int					print_double_with_big_e(t_tag *tags, va_list list);
int					print_double_with_e(t_tag *tags, va_list list);
int					print_double(t_tag *tags, va_list list);
int					print_hex(uintmax_t num, int big);
int					print_int3(t_tag *tags, va_list list);
int					print_int2(t_tag *tags, va_list list);
int					print_int(t_tag *tags, va_list list);
int					print_memory(t_tag *tags, va_list list);
int					print_percent(void);
int					print_str(t_tag *tags, va_list list);
int					print_str2(t_tag *tags, va_list list);
int					print_unsigned_int(t_tag *tags, va_list list);
int					print_unsigned_low_hex(t_tag *tags, va_list list);
int					print_octal(t_tag *tags, va_list list);
int					print_unsigned_upper_hex(t_tag *tags, va_list list);
int					printf_putchar(char c);
int					printf_putnbr(uintmax_t n, int base);
int					printf_putstr(char const *str);
int					refill_tags(t_tag *tags, char symbol, va_list list);

#endif
