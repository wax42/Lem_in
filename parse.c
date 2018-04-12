/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:05:29 by mbarthe           #+#    #+#             */
/*   Updated: 2018/04/11 00:58:01 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_tube		*ft_add_tube(t_tube *head, t_room *target)
{
	t_tube	*tmp;

	tmp = ft_new_tube(target);
	tmp->tube_next = head;
	return (tmp);
}

int			ft_tube_exists(t_room *room, t_room *target)
{
	t_tube *tmp;

	tmp = room->tube;
	while (tmp)
	{
		if (ft_strcmp(tmp->next->name, target->name) == 0)
			return (0);
		tmp = tmp->tube_next;
	}
	return (1);
}

void		ft_tube_link(t_room *room, t_room *target)
{
	if (ft_tube_exists(room, target))
	{
		if (room->tube == NULL)
		{
			room->tube = ft_new_tube(target);
			room->tube->tube_next = NULL;
		}
		else
			room->tube = ft_add_tube(room->tube, target);
	}
	if (ft_tube_exists(target, room))
	{
		if (target->tube == NULL)
		{
			target->tube = ft_new_tube(room);
			target->tube->tube_next = NULL;
		}
		else
			target->tube = ft_add_tube(target->tube, room);
	}
}

void		ft_room_link(char *name, t_room *room, t_param *p, int keycode)
{
	while (room->next)
	{
		if (ft_strequ(name, room->name))
			ft_exit(0);
		room = room->next;
	}
	room->next = ft_crea_room(p, keycode, name);
}

t_lines		*ft_ant_nbr(t_param *p, t_lines *tmp)
{
	int i;

	while (tmp)
	{
		if (ft_check_htag(tmp->line) == 3)
			tmp = tmp->next;
		else
		{
			i = -1;
			while (tmp->line[++i])
			{
				if (ft_isdigit(tmp->line[i]) == 0)
					ft_exit(0);
			}
			p->nbr_fourmi = ft_atoi(tmp->line);
			break ;
		}
	}
	if (!p->nbr_fourmi)
		ft_exit(0);
	tmp = tmp->next;
	while (ft_check_htag(tmp->line) == 3)
		tmp = tmp->next;
	return (tmp);
}
