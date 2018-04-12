/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:17:41 by mbarthe           #+#    #+#             */
/*   Updated: 2018/04/12 15:54:19 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_room		*ft_envoi_room(t_room *room, int id)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->type_of_room != END \
			&& tmp->type_of_room != START && tmp->nbr_fourmi == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room		*ft_find_start(t_room *room)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->type_of_room == START)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		ft_secure(t_room *head)
{
	int		count;
	t_room	*tmp;

	count = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->index != -1 && tmp->index != 0)
			count = 1;
		tmp = tmp->next;
	}
	if (count == 0)
		ft_exit(0);
}

void		resolution(t_param *p, t_lines *header)
{
	t_room	*tmp;
	t_room	*room;
	t_room	*target;
	int		id;
	int		decal;
	int		ret;
	int		state;

	decal = 0;
	state = 1;
	room = p->head->next;
	target = room;
	while (room)
	{
		if (room->type_of_room == START)
			break ;
		room = room->next;
	}
	while (target)
	{
		if (target->type_of_room == END)
			break ;
		target = target->next;
	}
	secur_path(room);
	if (target->path > 0 || target->type_of_room == END)
	{
		if (target->index > 0 || target->index == -1)
			target->index = 0;
	}
	ft_path(target, 1);
	ft_secure(p->head->next);
	ft_display_lines(header);
	while (target->nbr_fourmi != p->nbr_fourmi)
	{
		id = 1;
		while (p->nbr_fourmi >= id)
		{
			if ((tmp = ft_envoi_room(p->head->next, id)))
			{
				ret = ft_deplace(tmp, id, &state);
				if (ret != -1)
					target->nbr_fourmi += ret;
			}
			id++;
		}
		id = decal + 1;
		tmp = ft_find_start(p->head->next);
		while (p->nbr_fourmi >= id)
		{
			ret = ft_deplace(tmp, id, &state);
			if (ret != -1)
			{
				target->nbr_fourmi += ret;
				decal += 1;
			}
			id++;
		}
		if (target->nbr_fourmi < p->nbr_fourmi)
			state = 1;
		ft_putchar('\n');
	}
}
