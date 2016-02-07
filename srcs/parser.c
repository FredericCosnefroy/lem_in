/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 19:51:29 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 19:47:41 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static int			parse_hash(char *line, t_list **data, int *ok)
{
	if (*line == '#')
	{
		if (is_command(line))
		{
			if (!(*data))
				*ok = 0;
			else
				*data = list_add(data, line, ft_strlen(line) + 1);
		}
		return (1);
	}
	return (0);
}

static int			parse_all(char *line, t_list **data,
		int ((*parser[3])(char *)), int *i)
{
	if (!parser[*i](line))
	{
		(*i)++;
		if (*i > 2 || !parser[*i](line))
			return (0);
		else
			*data = list_add(data, line, ft_strlen(line) + 1);
	}
	else
		*data = list_add(data, line, ft_strlen(line) + 1);
	return (1);
}

t_list				*parse_data(t_list **raw_data)
{
	char		*line;
	int			((*parser[3])(char *));
	t_list		*data;
	int			ok;
	int			i;

	i = 0;
	ok = 1;
	data = NULL;
	*raw_data = NULL;
	parser[0] = &is_antnumber;
	parser[1] = &is_room;
	parser[2] = &is_link;
	while (ok && (get_next_line(0, &line) > 0) && *line)
	{
		*raw_data = list_add(raw_data, line, ft_strlen(line) + 1);
		if (!parse_hash(line, &data, &ok))
			ok = parse_all(line, &data, parser, &i);
		free(line);
	}
	if (i != 2)
		ft_error();
	return (data);
}
