/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browsing_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:08:17 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/06 19:09:43 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

int			get_room_by_number(t_list *data, int nb)
{
	int		cpt;

	cpt = -1;
	data = data->next;
	while (data && cpt != nb)
	{
		if (!is_link(data->content) && ((char *)data->content)[0] != '#')
			cpt++;
		data = data->next;
	}
	return (cpt);
}

char		*get_name_by_number(t_list *data, int nb)
{
	int		cpt;

	cpt = -1;
	data = data->next;
	while (data && cpt != nb)
	{
		if (!is_link(data->content) && ((char *)data->content)[0] != '#')
			cpt++;
		if (cpt == nb)
			return (data->content);
		data = data->next;
	}
	return (NULL);
}

int			get_room_by_name(t_list *data, char *name)
{
	int		cpt;

	cpt = -1;
	data = data->next;
	while (data)
	{
		if (!is_link(data->content) && ((char *)data->content)[0] != '#')
		{
			cpt++;
			if (ft_strequ(name, data->content))
				return (cpt);
		}
		data = data->next;
	}
	return (-1);
}

int			get_start_room(t_list *data)
{
	t_list	*tmp;

	tmp = data;
	while (tmp && !ft_strequ(((char *)tmp->content), "##start"))
		tmp = tmp->next;
	while (tmp && !is_link(tmp->content))
	{
		if (((char *)tmp->content)[0] != '#')
			return (get_room_by_name(data, tmp->content));
		tmp = tmp->next;
	}
	return (-1);
}

int			get_end_room(t_list *data)
{
	t_list	*tmp;

	tmp = data;
	while (tmp && !ft_strequ(((char *)tmp->content), "##end"))
		tmp = tmp->next;
	while (tmp && !is_link(tmp->content))
	{
		if (((char *)tmp->content)[0] != '#')
			return (get_room_by_name(data, tmp->content));
		tmp = tmp->next;
	}
	return (-1);
}
