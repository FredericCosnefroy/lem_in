/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 16:47:50 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/03 16:50:25 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*list_add_first(t_list **list, void *content, size_t content_size)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = list_add(&tmp, content, content_size);
	tmp->next = *list;
	*list = tmp;
	return (*list);
}
