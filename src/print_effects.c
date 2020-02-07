/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_effects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:38:36 by diana             #+#    #+#             */
/*   Updated: 2020/02/07 15:01:27 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_abbr(const char *str, int *i)
{
	int		len;
	char	*effect;
	int		index;
	int		i_value;

	i_value = *i;
	index = 0;
	len = 3;
	effect = ft_strnew(len + 1);
	while (str[i_value] && index < len)
	{
		effect[index] = str[i_value];
		i_value = i_value + 1;
		index++;
	}
	return (effect);
}

static int	turn_on_color(char *effect, int fd)
{
	if (!ft_strcmp(effect, "<D>"))
		write(fd, "\x1b[30m", 5);
	else if (!ft_strcmp(effect, "<R>"))
		write(fd, "\x1b[31m", 5);
	else if (!ft_strcmp(effect, "<G>"))
		write(fd, "\x1b[32m", 5);
	else if (!ft_strcmp(effect, "<Y>"))
		write(fd, "\x1b[33m", 5);
	else if (!ft_strcmp(effect, "<B>"))
		write(fd, "\x1b[34m", 5);
	else if (!ft_strcmp(effect, "<M>"))
		write(fd, "\x1b[35m", 5);
	else if (!ft_strcmp(effect, "<C>"))
		write(fd, "\x1b[36m", 5);
	else if (!ft_strcmp(effect, "<W>"))
		write(fd, "\x1b[37m", 5);
	return (5);
}

static int	turn_on_bckgrnd(char *effect, int fd)
{
	if (!ft_strcmp(effect, "<d>"))
		write(fd, "\x1b[40m", 5);
	else if (!ft_strcmp(effect, "<r>"))
		write(fd, "\x1b[41m", 5);
	else if (!ft_strcmp(effect, "<g>"))
		write(fd, "\x1b[42m", 5);
	else if (!ft_strcmp(effect, "<y>"))
		write(fd, "\x1b[43m", 5);
	else if (!ft_strcmp(effect, "<b>"))
		write(fd, "\x1b[44m", 5);
	else if (!ft_strcmp(effect, "<m>"))
		write(fd, "\x1b[45m", 5);
	else if (!ft_strcmp(effect, "<c>"))
		write(fd, "\x1b[46m", 5);
	else if (!ft_strcmp(effect, "<w>"))
		write(fd, "\x1b[47m", 5);
	else if (!ft_strcmp(effect, "<o>"))
		write(fd, "\x1b[27m", 5);
	return (5);
}

static int	turn_on_effect(char *effect, int fd)
{
	if (!ft_strcmp(effect, "<0>"))
		write(fd, "\x1b[0m", 4);
	else if (!ft_strcmp(effect, "<f>"))
		write(fd, "\x1b[1m", 4);
	else if (!ft_strcmp(effect, "<i>"))
		write(fd, "\x1b[3m", 4);
	else if (!ft_strcmp(effect, "<_>"))
		write(fd, "\x1b[4m", 4);
	else if (!ft_strcmp(effect, "<r>"))
		write(fd, "\x1b[7m", 4);
	else if (!ft_strcmp(effect, "<n>"))
		write(fd, "\x1b[8m", 4);
	return (4);
}

int			print_effect(const char *str, int *i, int fd)
{
	char	*effect;
	int		res;

	effect = get_abbr(str, i);
	if (ft_strchr("RGYBMCWD", str[*i + 1]))
		res = turn_on_color(effect, fd);
	else if (ft_strchr("_ifnq0", str[*i + 1]))
		res = turn_on_effect(effect, fd);
	else if (ft_strchr("rgybmcwdo", str[*i + 1]))
		res = turn_on_bckgrnd(effect, fd);
	else
	{
		free(effect);
		return (0);
	}
	free(effect);
	*i = *i + 2;
	return (res);
}
