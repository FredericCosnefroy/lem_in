/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosnefr <fcosnefr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/06 20:07:13 by fcosnefr          #+#    #+#             */
/*   Updated: 2015/06/08 18:01:44 by fcosnefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h/lem_in.h"

int		is_command(char *string)
{
	if (ft_strequ(string, "##start") || ft_strequ(string, "##end"))
		return (1);
	return (0);
}

int		is_link(char *string)
{
	int		has_dash;

	has_dash = ft_strchri(string, '-');
	if (string[has_dash] && string[has_dash + 1] && has_dash > 0)
		return (1);
	return (0);
}

int		is_room(char *string)
{
	int		i;

	i = 0;
	if (string[0] == 'L')
		return (0);
	while (string[i] && ft_isalnum(string[i]) && string[i] != ' ')
		i++;
	if (string[i] == ' ')
		i++;
	else
		return (0);
	while (string[i] && ft_isdigit(string[i]) && string[i] != ' ')
		i++;
	if (string[i] == ' ')
		i++;
	else
		return (0);
	while (string[i] && ft_isdigit(string[i]))
		i++;
	if (!string[i])
		return (1);
	return (0);
}

int		is_antnumber(char *string)
{
	int		i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	ft_putstr("ERROR\n");
	exit(-1);
}
