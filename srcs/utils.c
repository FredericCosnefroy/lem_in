/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 20:09:05 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 19:07:59 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

int		ft_strchri(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (i);
}

int		get_max_path(t_mat matrix)
{
	int		cpt;
	int		i;
	int		j;

	cpt = 0;
	i = matrix.end;
	j = 0;
	while (j < matrix.size)
	{
		if (matrix.adj[i][j])
			cpt++;
		j++;
	}
	return (cpt);
}

void	print_move(int ant_no, char *room_name, int *printed)
{
	if (*printed)
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(ant_no);
	ft_putchar('-');
	ft_putstr(room_name);
	*printed = 1;
}
