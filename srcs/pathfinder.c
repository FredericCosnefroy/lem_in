/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 20:08:02 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 19:51:15 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static int	stop_if_end(t_mat matrix, t_list **path_list, t_list *path,
		int index)
{
	t_int	i;

	if (matrix.adj[index][matrix.end])
	{
		i.nb = matrix.end;
		path = list_add(&path, &i, sizeof(int));
		get_paths(matrix, path_list, path, matrix.end);
		path = list_remove(&path);
		return (1);
	}
	return (0);
}

void		get_paths(t_mat matrix, t_list **path_list, t_list *path, int index)
{
	t_int	i;
	int		j;

	if (index == matrix.end)
	{
		*path_list = list_add_first(path_list, list_copy(path), sizeof(t_list));
		return ;
	}
	if (stop_if_end(matrix, path_list, path, index))
		return ;
	j = 0;
	while (j < matrix.size)
	{
		if (matrix.adj[index][j] && !matrix.adj[j][j])
		{
			i.nb = j;
			matrix.adj[j][j] = 1;
			path = list_add(&path, &i, sizeof(int));
			get_paths(matrix, path_list, path, j);
			path = list_remove(&path);
			matrix.adj[j][j] = 0;
		}
		j++;
	}
}

t_list		*find_paths(t_mat matrix)
{
	t_list	*path_list;
	t_list	*init;
	t_int	index;

	path_list = NULL;
	init = NULL;
	index.nb = matrix.start;
	matrix.adj[matrix.start][matrix.start] = 1;
	init = list_add(&init, &index, sizeof(t_int));
	get_paths(matrix, &path_list, init, index.nb);
	return (path_list);
}
