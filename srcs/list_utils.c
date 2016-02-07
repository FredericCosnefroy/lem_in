/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:34:35 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/06 19:35:07 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

int		is_in_list(t_list *lst, int id)
{
	while (lst)
	{
		if (((t_int *)lst->content)->nb == id)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*list_copy(t_list *list)
{
	t_list	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list_add(&tmp, list->content, list->content_size);
		list = list->next;
	}
	return (tmp);
}
