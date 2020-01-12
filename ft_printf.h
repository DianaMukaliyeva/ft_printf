/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:26 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 23:10:14 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int	left_align;
	int	sign;
	int	space;
	int	zero;
	int	hash;
}				t_flag;

typedef struct	s_amount_char
{
	int	is_exist;
	int	num;
	int	asterisk;
}				t_amount_char;

typedef struct	s_modifier
{
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	big_l;
}				t_modifier;

typedef struct		s_tag
{
	t_flag			flags;
	t_amount_char	width;
	t_amount_char	precision;
	t_modifier		modifier;
}					t_tag;

int		ft_printf(const char *format, ...);
void	start(va_list list, const char *format);
int		ft_strlen(const char *str);
int	printf_putnbr(int n);
int	printf_putchar(char c);
int	print_arg(char modifier, t_tag *tags, va_list list);
int	fill_tags(t_tag *tags, char symbol, va_list list);
int	parse_specifiers(va_list list, const char *format, int *i);
int	print_int(t_tag *tags, va_list list);
char	*ft_strchr(const char *str, int ch);
int	printf_putstr(char const *str);
int		print_str(t_tag *tags, va_list list);

#endif
