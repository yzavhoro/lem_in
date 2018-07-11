/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:28:01 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/21 20:28:04 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		if_comment(char *s)
{
	return (*s == '#' && ft_strcmp(s, "##start") && ft_strcmp(s, "##end"));
}

int		is_room(char *s)
{
	return (*s != '#' && count_char(s, ' ') == 2);
}

int		is_link(char *s)
{
	return (*s != '#' && ft_strchr(s, '-'));
}

void	join_input(char **input, char *line)
{
	*input = ft_strjoin(*input, line);
	*input = ft_strjoin(*input, "\n");
}

int		val_links(char **lnks, t_valid *v)
{
	int flag;
	int i;

	flag = 0;
	i = -1;
	if (v->rooms[0])
		while (v->rooms[++i][0] != '\0')
			if (!ft_strcmp(lnks[0], v->rooms[i])
				|| !ft_strcmp(lnks[1], v->rooms[i]))
				flag++;
	return (flag);
}
