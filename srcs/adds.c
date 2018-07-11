/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:27:44 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/21 20:27:48 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_error(int i)
{
	if (i == 0)
		ft_putstr("ERROR: links declaration missing\n");
	else if (i == 1)
		ft_putstr("ERROR: two rooms with the same name or coords\n");
	else if (i == 2)
		ft_putstr("ERROR: invalid number of ants\n");
	else if (i == 3)
		ft_putstr("ERROR: unknown command\n");
	else if (i == 4)
		ft_putstr("ERROR: invalid ##start or ##end command\n");
	else if (i == 5)
		ft_putstr("ERROR: ##start or ##end command missing\n");
	else if (i == 6)
		ft_putstr("ERROR: room's name can't contain 'L' nor '-' character\n");
	else if (i == 7)
		ft_putstr("ERROR: invalid room declaration\n");
	else if (i == 8)
		ft_putstr("ERROR: invalid link declaration\n");
	else if (i == 9)
		ft_putstr("ERROR: start and end rooms are not connected\n");
	exit(0);
}

void	init_val(t_valid *v)
{
	v->ants = 0;
	v->i = 0;
	v->start = ft_strnew(0);
	v->end = ft_strnew(0);
	v->coords = NULL;
	v->coords = NULL;
}

void	lstadd(t_coords **alst, t_coords *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	check_unique(t_coords *coords)
{
	t_coords *tmp;

	tmp = coords;
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->room, tmp->next->room) ||
			(tmp->x == tmp->next->x && tmp->y == tmp->next->y))
			print_error(1);
		tmp = tmp->next;
	}
}

int		check_coords(char *x, char *y, t_valid *v, char *room)
{
	int			i;
	t_coords	*new;

	new = (t_coords*)malloc(sizeof(t_coords));
	i = (x[0] == '-');
	while (x[i])
		if (!ft_isdigit(x[i++]))
			return (0);
	i = (y[0] == '-');
	while (y[i])
		if (!ft_isdigit(y[i++]))
			return (0);
	new->y = ft_atoi(y);
	new->x = ft_atoi(x);
	new->room = ft_strdup(room);
	new->next = NULL;
	lstadd(&v->coords, new);
	check_unique(v->coords);
	return (1);
}
