/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 20:28:43 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/21 20:28:46 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clean_leaks(char **arr)
{
	int a;

	a = 0;
	while (arr[a])
		free(arr[a++]);
	free(arr[a]);
	free(arr);
}

int		main(void)
{
	char	*input;
	int		**matrix;
	t_valid v;

	init_val(&v);
	validator(&input, &v, 0);
	matrix = create_matrix(input, &v);
	fill_distance(matrix, &v, v.end_i, 1);
	check_path(matrix, &v);
	ft_putstr(input);
	ft_putstr("\n");
	sort_ants(matrix, &v, 0, 0);
	return (0);
}
