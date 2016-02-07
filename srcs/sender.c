/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 20:08:31 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 20:17:55 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static int			move_existing_ants(t_node **sender, t_pt pt, int printed,
		int *ants)
{
	while (pt.j >= 0)
	{
		if (sender[pt.i][pt.j].ant_no == 0 && (pt.j - 1 >= 0) &&
				sender[pt.i][pt.j - 1].ant_no != 0)
		{
			sender[pt.i][pt.j].ant_no = sender[pt.i][pt.j - 1].ant_no;
			sender[pt.i][pt.j - 1].ant_no = 0;
			print_move(sender[pt.i][pt.j].ant_no, sender[pt.i][pt.j].room_name,
					&printed);
			if (!sender[pt.i][pt.j + 1].room_name)
			{
				sender[pt.i][pt.j].ant_no = 0;
				(*ants)--;
			}
		}
		pt.j--;
	}
	return (printed);
}

static void			add_new_ant(t_node **sender, t_final *optimal, t_gar gar,
		int *printed)
{
	int		*i;
	int		*id;
	int		*ants;

	i = gar.i;
	id = gar.id;
	ants = gar.ants;
	sender[*i][1].ant_no = *id;
	(*id)++;
	optimal->paths[*i].ants--;
	(*i)++;
	print_move(sender[*i - 1][1].ant_no, sender[*i - 1][1].room_name, printed);
	if (!sender[*i - 1][2].room_name)
	{
		sender[*i - 1][1].ant_no = 0;
		(*ants)--;
	}
}

static t_node		**next_cycle(t_node **sender, t_final *optimal, int *id,
		int *ants)
{
	int		printed;
	int		i;
	int		j;

	i = 0;
	printed = 0;
	while (sender[i])
	{
		j = 0;
		while (sender[i][j].room_name)
			j++;
		j--;
		printed |= move_existing_ants(sender, (t_pt){i, j}, printed, ants);
		if (sender[i][1].ant_no == 0 && optimal->paths[i].ants > 0)
		{
			add_new_ant(sender, optimal, (t_gar){&i, id, ants}, &printed);
			continue;
		}
		i++;
	}
	ft_putchar('\n');
	return (sender);
}

void				move_ants(t_node **sender, t_final optimal, int ants)
{
	int		id;

	id = 1;
	while (ants > 0)
	{
		sender = next_cycle(sender, &optimal, &id, &ants);
	}
}

t_node				**init_sender(t_final optimal, t_list *data)
{
	t_node		**sender;
	t_list		*tmp;
	t_list		*tmp2;
	int			i;
	int			j;

	i = 0;
	sender = (t_node **)malloc(sizeof(t_node *) * (optimal.size + 1));
	tmp = optimal.combination;
	while (i < optimal.size)
	{
		sender[i] = malloc(sizeof(t_node) * (optimal.paths[i].size + 2));
		j = 0;
		tmp2 = tmp->content;
		while (j < optimal.paths[i].size + 1)
		{
			sender[i][j++] = (t_node){0, get_name_by_number(data,
					((t_int *)tmp2->content)->nb)};
			tmp2 = tmp2->next;
		}
		sender[i++][j] = (t_node){-1, NULL};
		tmp = tmp->next;
	}
	sender[i] = NULL;
	return (sender);
}
