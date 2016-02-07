/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 13:40:34 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 20:36:57 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# define ABS(x) ((x < 0) ? -x : x)

typedef struct	s_int
{
	int			nb;
}				t_int;

typedef struct	s_pt
{
	int			i;
	int			j;
}				t_pt;

typedef struct	s_gar
{
	int			*i;
	int			*id;
	int			*ants;
}				t_gar;

typedef struct	s_mat
{
	int			ants;
	int			size;
	int			start;
	int			end;
	char		**adj;
}				t_mat;

typedef struct	s_path
{
	int			size;
	int			ants;
}				t_path;

typedef struct	s_final
{
	t_path		*paths;
	t_list		*combination;
	int			turns;
	int			size;
}				t_final;

typedef struct	s_node
{
	int			ant_no;
	char		*room_name;
}				t_node;

int				get_room_by_number(t_list *data, int nb);
char			*get_name_by_number(t_list *data, int nb);
int				get_room_by_name(t_list *data, char *name);
int				get_start_room(t_list *data);
int				get_end_room(t_list *data);
int				paths_are_compatible(t_list *p1, t_list *p2);
int				count_combination_size(t_list *combination);
t_list			*get_complete_combinations(t_list *compatible, t_list *paths,
				int max_path);
t_list			*get_compatible_paths(t_list *paths, int max_path);
t_mat			init_matrix(t_list *data);
int				is_in_list(t_list *lst, int id);
t_list			*list_copy(t_list *list);
t_final			find_optimal_path(t_list *paths, int ants);
t_list			*parse_data(t_list **raw_data);
int				is_command(char *string);
int				is_link(char *string);
int				is_room(char *string);
int				is_antnumber(char *string);
void			ft_error(void);
void			get_paths(t_mat matrix, t_list **path_list, t_list *path,
				int index);
t_list			*find_paths(t_mat matrix);
void			move_ants(t_node **sender, t_final optimal, int ants);
t_node			**init_sender(t_final optimal, t_list *data);
int				ft_strchri(const char *s, int c);
int				get_max_path(t_mat matrix);
void			print_move(int ant_no, char *room_name, int *printed);

#endif
