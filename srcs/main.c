/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 13:39:57 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 19:46:14 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

static void	print_data(t_list *raw_data)
{
	while (raw_data)
	{
		ft_putstr(raw_data->content);
		ft_putchar('\n');
		raw_data = raw_data->next;
	}
	ft_putchar('\n');
}

int			main(int argc, char **argv)
{
	t_mat	matrix;
	t_list	*raw_data;
	t_list	*data;
	t_final	optimal;
	t_node	**sender;

	data = parse_data(&raw_data);
	matrix = init_matrix(data);
	matrix.ants = ft_atoi(data->content);
	optimal = find_optimal_path(get_compatible_paths(find_paths(matrix),
				get_max_path(matrix)), matrix.ants);
	sender = init_sender(optimal, data);
	print_data(raw_data);
	move_ants(sender, optimal, matrix.ants);
	(void)argc;
	(void)argv;
	return (0);
}
