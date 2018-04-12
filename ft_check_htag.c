/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_htag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:41:50 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/14 18:33:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int		ft_check_htag(char *line)
{
	if ((ft_strequ(line, "##start")))
		return (START);
	else if ((ft_strequ(line, "##end")))
		return (END);
	else if (line[0] == '#')
		return (3);
	return (0);
}

int		secur_path(t_room *room)
{
	t_tube	*tmp;
	int		tmp_int;

	if (room->type_of_room == END || room->path == TRUE)
	{
		room->path = TRUE;
		return (TRUE);
	}
	if (room->path == NOEUD)
	{
		room->path = FALSE;
		return (0);
	}
	if (room->path == 0)
	{
		room->path = NOEUD;
		tmp = room->tube;
		while (tmp)
		{
			if ((tmp_int = secur_path(tmp->next)))
			{
				if (tmp_int == TRUE)
				{
					room->path = tmp_int;
					return (TRUE);
				}
			}
			tmp = tmp->tube_next;
		}
	}
	return (FALSE);
}

void	ft_path(t_room *room, int index)
{
	t_tube *tmp;

	tmp = room->tube;
	while (tmp)
	{
		if (tmp->next->path == 1 || tmp->next->type_of_room == START)
		{
			if (tmp->next->index > index || tmp->next->index == -1)
			{
				tmp->next->index = index;
				ft_path(tmp->next, index + 1);
			}
		}
		tmp = tmp->tube_next;
	}
}
