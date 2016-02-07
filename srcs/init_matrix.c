/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:30:08 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 19:45:46 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static int		count_rooms(t_list *data)
{
	int		cpt;

	cpt = 0;
	data = data->next;
	while (data)
	{
		if (!is_link(data->content) && ((char *)data->content)[0] != '#')
			cpt++;
		data = data->next;
	}
	return (cpt);
}

static void		add_link(t_list **data, t_mat *matrix, t_list *tmp)
{
	char	**split;
	int		ind[2];

	if (((char *)tmp->content)[0] != '#')
	{
		split = ft_strsplit(tmp->content, '-');
		ind[0] = get_room_by_name(*data, split[0]);
		ind[1] = get_room_by_name(*data, split[1]);
		if (ind[0] < 0 || ind[1] < 0)
			ft_error();
		matrix->adj[ind[0]][ind[1]] = 1;
		matrix->adj[ind[1]][ind[0]] = 1;
		ft_arraydel(&split);
	}
}

static void		fill_matrix(t_list **data, t_mat *matrix)
{
	t_list	*tmp;

	tmp = (*data)->next;
	while (tmp && (!is_link(tmp->content) || ((char *)tmp->content)[0] == '#'))
	{
		((char *)tmp->content)[ft_strchri(tmp->content, ' ')] = '\0';
		tmp = tmp->next;
	}
	while (tmp)
	{
		add_link(data, matrix, tmp);
		tmp = tmp->next;
	}
	matrix->start = get_start_room(*data);
	matrix->end = get_end_room(*data);
	if (matrix->start < 0 || matrix->end < 0 || matrix->start == matrix->end)
		ft_error();
}

t_mat			init_matrix(t_list *data)
{
	t_mat	matrix;
	int		i;
	int		j;

	i = 0;
	matrix.size = count_rooms(data);
	matrix.adj = (char **)malloc(sizeof(char *) * (matrix.size));
	while (i < matrix.size)
	{
		j = 0;
		matrix.adj[i] = (char *)malloc(sizeof(char) * (matrix.size));
		while (j < matrix.size)
		{
			matrix.adj[i][j] = 0;
			j++;
		}
		i++;
	}
	fill_matrix(&data, &matrix);
	return (matrix);
}
