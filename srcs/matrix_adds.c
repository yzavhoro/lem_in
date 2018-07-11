/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_adds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:28:55 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/21 20:28:58 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_room_id(char *rm, char **rooms)
{
	int i;

	i = 0;
	while (rooms[i][0])
	{
		if (!ft_strcmp(rm, rooms[i]))
			return (i);
		i++;
	}
	return (i);
}

void	linked_rooms(int **matrix, char **src, t_valid *v)
{
	int		a;
	int		b;
	char	**rooms;

	while (*src)
	{
		if (is_link(*src))
		{
			rooms = ft_strsplit(*src, '-');
			a = find_room_id(rooms[0], v->rooms);
			b = find_room_id(rooms[1], v->rooms);
			matrix[a][b] = 2147483647;
			matrix[b][a] = 2147483647;
			clean_leaks(rooms);
		}
		src++;
	}
}

int		**create_matrix(char *src, t_valid *v)
{
	int		**matrix;
	int		a;
	char	**lines;

	lines = ft_strsplit(src, '\n');
	a = 0;
	matrix = (int**)malloc(sizeof(int*) * v->i);
	while (a < v->i)
		matrix[a++] = (int*)malloc(sizeof(int) * v->i);
	a = -1;
	while (++a < v->i)
		int_set(matrix[a], 0, v->i);
	linked_rooms(matrix, lines, v);
	clean_leaks(lines);
	return (matrix);
}

void	check_path(int **matrix, t_valid *v)
{
	int j;
	int flag;

	j = 0;
	flag = 0;
	while (j < v->i)
	{
		if (matrix[v->start_i][j] > 0 && matrix[v->start_i][j] < v->i)
			flag++;
		j++;
	}
	if (!flag)
		print_error(9);
	v->ways = flag;
	v->help = (int*)malloc(sizeof(int) * v->i);
	v->ant = (int*)malloc(sizeof(int) * v->ants);
	int_set(v->help, 1, v->i);
	int_set(v->ant, v->start_i, v->ants);
	flag = 0;
	j = 0;
}

int		amount_of_ants(char *s, t_valid *v)
{
	int i;

	i = 0;
	while (s[i])
		if (!ft_isdigit(s[i++]))
			print_error(2);
	v->ants = ft_atoi(s);
	if (v->ants <= 0)
		print_error(2);
	return (1);
}
