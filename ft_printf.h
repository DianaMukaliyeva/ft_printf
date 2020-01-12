/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 17:39:26 by dmukaliy          #+#    #+#             */
/*   Updated: 2020/01/12 21:48:25 by dmukaliy         ###   ########.fr       */
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

typedef struct	s_width
{
	int	is_width;
	int	width;
	int	asterisk;
}				t_width;

typedef struct	s_precision
{
	int	is_precision;
	int	num;
	int	asterisk;
}				t_precision;

typedef struct	s_modifier
{
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	big_l;
}				t_modifier;

typedef struct	s_identifier
{
	t_flag		flags;
	t_width		width;
	t_precision	precision;
	t_modifier	modifier;
}				t_identifier;

int		ft_printf(const char *format, ...);
void	start(va_list list, const char *format);
int		ft_strlen(const char *str);
void	ft_putstr(char const *str);
int	printf_putnbr(int n);
int	printf_putchar(char c);
void	ft_putchar(char c);
int	print_arg(char modifier, t_identifier *identifiers, va_list list);
int	fill_identifiers(t_identifier *identifiers, char symbol, va_list list);
int	parse_specifiers(va_list list, const char *format, int *i);
int	print_int(t_identifier *identifiers, va_list list);
char	*ft_strchr(const char *str, int ch);

#endif
