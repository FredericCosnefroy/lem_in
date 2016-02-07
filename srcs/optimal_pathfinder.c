/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_pathfinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:35:40 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 20:34:52 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static int			max_turn(t_path *paths, int size)
{
	int		mem;
	int		max;
	int		i;

	i = 0;
	max = INT_MIN;
	while (i < size)
	{
		if (paths[i].ants && (mem = (paths[i].size + paths[i].ants - 1)) > max)
			max = mem;
		i++;
	}
	return (max);
}

static t_path		*swap_ants(t_path *paths, int res, int *i, int *j)
{
	if (res > 0)
	{
		paths[*i].ants--;
		paths[*j].ants++;
	}
	else
	{
		paths[*i].ants++;
		paths[*j].ants--;
	}
	*i = 0;
	*j = 0;
	return (paths);
}

static t_path		*spread_ants(t_path *paths, int size)
{
	int		res;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			while (paths[i].ants && paths[j].ants &&
					ABS((res = ((paths[i].size + paths[i].ants - 1) -
								(paths[j].size + paths[j].ants - 1)))) > 1)
				swap_ants(paths, res, &i, &j);
			j++;
		}
		i++;
	}
	return (paths);
}

static t_final		find_turn_number(t_list *combination, int ants)
{
	t_list	*tmp;
	t_path	*paths;
	int		size;
	int		i;

	i = 0;
	size = count_combination_size(combination);
	paths = (t_path *)malloc(sizeof(t_path) * size);
	tmp = combination;
	while (tmp)
	{
		paths[i] = (t_path){count_combination_size(tmp->content) - 1,
			ants / size};
		i++;
		tmp = tmp->next;
	}
	paths[0].ants += ants % size;
	paths = spread_ants(paths, size);
	return ((t_final){paths, combination, max_turn(paths, size), size});
}

t_final				find_optimal_path(t_list *paths, int ants)
{
	t_list	*tmp;
	t_final	pending;
	t_final	optimal;

	tmp = paths;
	optimal = (t_final){NULL, NULL, INT_MAX, 0};
	while (tmp)
	{
		pending = find_turn_number(tmp->content, ants);
		if (pending.turns < optimal.turns)
			optimal = pending;
		tmp = tmp->next;
	}
	return (optimal);
}
