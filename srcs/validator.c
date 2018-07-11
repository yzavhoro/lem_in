/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:29:05 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/21 20:29:08 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_links(char *s, t_valid *v, int f)
{
	char	**lnks;

	if ((count_char(s, '-') > 1 || count_char(s, ' ')) && f)
		return (0);
	else if (count_char(s, '-') > 1 || count_char(s, ' '))
		print_error(8);
	lnks = ft_strsplit(s, '-');
	if (array_size(lnks) != 2)
	{
		clean_leaks(lnks);
		if (f)
			return (0);
		print_error(8);
	}
	if (val_links(lnks, v) != 2)
	{
		if (f)
			return (0);
		print_error(8);
	}
	clean_leaks(lnks);
	return (1);
}

int		check_rooms(char *s, t_valid *v, int i, int *flag)
{
	char **rms;

	if (ft_strchr(s, '-') && check_links(s, v, 1))
	{
		*flag = 2;
		return (0);
	}
	rms = ft_strsplit(s, ' ');
	free(v->rooms[i]);
	v->rooms[i] = ft_strdup(rms[0]);
	v->rooms[i + 1] = ft_strnew(0);
	if (array_size(rms) != 3 || !check_coords(rms[1], rms[2], v, rms[0])
		|| count_char(s, ' ') != 2)
		print_error(7);
	if (rms[0][0] == 'L' || ft_strchr(rms[0], '-'))
		print_error(6);
	clean_leaks(rms);
	return (1);
}

void	fill_st_en(t_valid *v, char *line, int flag, int i)
{
	if (flag == 1)
	{
		v->start_i = i;
		free(v->start);
		v->start = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	}
	else
	{
		v->end_i = i;
		free(v->end);
		v->end = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	}
}

void	start_end(char *s, t_valid *v, int *flag, char **input)
{
	char	*line;

	get_next_line(0, &line);
	while (if_comment(line) && *line)
	{
		join_input(input, line);
		free(line);
		get_next_line(0, &line);
	}
	if (!line[0])
		print_error(4);
	join_input(input, line);
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		print_error(4);
	if (!check_rooms(line, v, v->i, flag))
		print_error(4);
	if (s[2] == 's' && !*v->start)
		fill_st_en(v, line, 1, v->i);
	else if (s[2] == 'e' && !*v->end)
		fill_st_en(v, line, 2, v->i);
	else
		print_error(4);
	v->i++;
	free(line);
}

void	validator(char **input, t_valid *v, int flag)
{
	*input = ft_strnew(0);
	while (get_next_line(0, &(v->line)) == 1 && *v->line)
	{
		join_input(input, v->line);
		if (!if_comment(v->line))
		{
			if (!flag && amount_of_ants(v->line, v))
				flag++;
			else if (flag == 1 && (!ft_strcmp(v->line, "##start")
				|| !ft_strcmp(v->line, "##end")))
				start_end(v->line, v, &flag, input);
			else if (flag == 1)
				check_rooms(v->line, v, v->i++, &flag);
			else if (flag && check_links(v->line, v, 0))
				flag = 2;
			else
			{
				free(v->line);
				print_error(3);
			}
		}
		free(v->line);
	}
	if (!*v->start || !*v->end || flag != 2)
		print_error((!*v->start || !*v->end) ? 5 : 0);
}
