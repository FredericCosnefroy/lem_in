/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_couples.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:17:57 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 19:45:26 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static int		add_path_if_compatible(t_list **compatible, t_list *checking,
		t_list *next)
{
	t_list	*couple;

	couple = NULL;
	if (((t_int *)((t_list *)checking->content)->next->content)->nb !=
			((t_int *)((t_list *)next->content)->next->content)->nb &&
			paths_are_compatible(checking->content, next->content))
	{
		couple = list_add(&couple, checking->content, sizeof(t_list));
		couple = list_add(&couple, next->content, sizeof(t_list));
		*compatible = list_add(compatible, couple, sizeof(t_list));
		couple = NULL;
		return (1);
	}
	return (0);
}

static void		get_couples(t_list **compatible, t_list *checking)
{
	t_list	*couple;
	t_list	*next;
	char	added;

	couple = NULL;
	while (checking->next)
	{
		added = 0;
		next = checking->next;
		while (next)
		{
			added |= add_path_if_compatible(compatible, checking, next);
			next = next->next;
		}
		if (!added)
		{
			couple = list_add(&couple, checking->content, sizeof(t_list));
			*compatible = list_add(compatible, couple, sizeof(t_list));
			couple = NULL;
		}
		checking = checking->next;
	}
}

t_list			*get_compatible_paths(t_list *paths, int max_path)
{
	t_list	*compatible;
	t_list	*couple;
	t_list	*checking;

	checking = paths;
	couple = NULL;
	compatible = NULL;
	if (!checking)
		ft_error();
	if (!checking->next)
	{
		couple = list_add(&couple, checking->content, sizeof(t_list));
		compatible = list_add(&compatible, couple, sizeof(t_list));
	}
	get_couples(&compatible, checking);
	return (get_complete_combinations(compatible, paths, max_path));
}
