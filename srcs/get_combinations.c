/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_combinations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:09:54 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 19:44:44 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static int		can_add_path(t_list *combination, t_list *path)
{
	while (combination)
	{
		if (!paths_are_compatible(combination->content, path))
			return (0);
		combination = combination->next;
	}
	return (1);
}

static t_list	*add_path_to_list(t_list **compatible, t_list *tmp1,
		t_list *tmp2)
{
	t_list *tmp3;

	tmp3 = NULL;
	if (can_add_path(tmp1->content, tmp2->content))
	{
		tmp3 = list_copy(tmp1->content);
		tmp3 = list_add(&tmp3, tmp2->content, tmp2->content_size);
		*compatible = list_add(compatible, tmp3, sizeof(t_list));
	}
	return (*compatible);
}

int				count_combination_size(t_list *combination)
{
	int		i;

	i = 0;
	while (combination)
	{
		i++;
		combination = combination->next;
	}
	return (i);
}

int				paths_are_compatible(t_list *p1, t_list *p2)
{
	t_list	*tmp;

	p1 = p1->next;
	while (p1->next)
	{
		tmp = p2->next;
		while (tmp->next)
		{
			if (((t_int *)p1->content)->nb == ((t_int *)tmp->content)->nb)
				return (0);
			tmp = tmp->next;
		}
		p1 = p1->next;
	}
	return (1);
}

t_list			*get_complete_combinations(t_list *compatible, t_list *paths,
		int max_path)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		size;

	tmp1 = compatible;
	while (tmp1)
	{
		size = count_combination_size(tmp1->content);
		if (size > 1 && size < max_path)
		{
			tmp2 = paths;
			while (tmp2)
			{
				compatible = add_path_to_list(&compatible, tmp1, tmp2);
				tmp2 = tmp2->next;
			}
		}
		tmp1 = tmp1->next;
	}
	return (compatible);
}
