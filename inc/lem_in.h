/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzavhoro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:38:21 by yzavhoro          #+#    #+#             */
/*   Updated: 2018/05/22 15:38:24 by yzavhoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct		s_coords
{
	int				x;
	int				y;
	char			*room;
	struct s_coords	*next;
}					t_coords;

typedef	struct		s_valid
{
	char			*start;
	char			*end;
	int				ants;
	int				start_i;
	int				end_i;
	char			*line;
	char			*rooms[60000];
	int				i;
	int				ways;
	int				*help;
	int				*ant;
	struct s_coords	*coords;
}					t_valid;

int					find_room_id(char *rm, char **rooms);
void				linked_rooms(int **matrix, char **src, t_valid *v);
int					**create_matrix(char *src, t_valid *v);
void				check_path(int **matrix, t_valid *v);
void				fill_distance(int **matrix, t_valid *v, int i, int dist);
int					find_smallest_free(int *s, int i, int len, t_valid *v);
int					find_smallest(int *s, int len);
void				sort_ants(int **matrix, t_valid *v, int counter, int id);
void				clean_leaks(char **arr);
int					check_links(char *s, t_valid *v, int f);
int					check_rooms(char *s, t_valid *v, int i, int *flag);
void				fill_st_en(t_valid *v, char *line, int flag, int i);
void				start_end(char *s, t_valid *v, int *flag, char **input);
int					amount_of_ants(char *s, t_valid *v);
void				validator(char **input, t_valid *v, int flag);
int					if_comment(char *s);
int					is_room(char *s);
int					is_link(char *s);
void				join_input(char **input, char *line);
int					val_links(char **lnks, t_valid *v);
void				print_error(int i);
void				init_val(t_valid *v);
void				lstadd(t_coords **alst, t_coords *new);
void				check_unique(t_coords *coords);
int					check_coords(char *x, char *y, t_valid *v, char *room);

#endif
