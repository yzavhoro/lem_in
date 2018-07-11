/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:28:22 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/21 20:28:25 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_distance(int **matrix, t_valid *v, int i, int dist)
{
	int j;

	j = 0;
	while (j < v->i)
	{
		if (i == v->start_i || dist >= v->i)
			return ;
		else if (j == i || (j != v->end_i && matrix[i][j] == 0))
			;
		else if (j != v->end_i && matrix[i][j] > 0)
			if (matrix[i][j] > dist)
			{
				matrix[i][j] = dist;
				matrix[j][i] = dist;
				fill_distance(matrix, v, j, dist + 1);
			}
		j++;
	}
}

int		find_smallest_free(int *s, int i, int len, t_valid *v)
{
	int a;
	int w_len;

	a = 0;
	w_len = find_smallest(s, len);
	while (a < len)
	{
		if (s[a] == w_len && (s[a] == 1 || v->help[a] == 1))
		{
			if (s[a] != 1)
				v->help[a] = 0;
			v->help[i] = 1;
			return (a);
		}
		a++;
	}
	return (-1);
}

int		find_smallest(int *s, int len)
{
	int a;
	int sm;

	a = -1;
	sm = 0;
	while (++a < len)
		if (s[a])
			sm = (!sm || s[a] < sm) ? s[a] : sm;
	return (sm);
}

void	sort_ants(int **matrix, t_valid *v, int counter, int id)
{
	int i;
	int dist;
	int flag;

	while (counter != v->ants)
	{
		id = 0;
		counter = 0;
		flag = 0;
		while (id < v->ants)
		{
			i = v->ant[id];
			if (i != v->end_i &&
				(dist = find_smallest_free(matrix[i], i, v->i, v)) != -1)
			{
				flag++ ? ft_putstr(" ") : NULL;
				ft_printf("L%d-%s", id + 1, v->rooms[dist]);
				v->ant[id] = dist;
			}
			if (v->ant[id] == v->end_i)
				counter++;
			id++;
		}
		ft_putstr("\n");
	}
}
