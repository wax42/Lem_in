/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 08:51:29 by mbarthe           #+#    #+#             */
/*   Updated: 2018/04/11 00:01:00 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

void		ft_display_lines(t_lines *header)
{
	t_lines *tmp;

	tmp = header;
	while (tmp)
	{
		ft_putendl(tmp->line);
		tmp = tmp->next;
	}
}

void		ft_display_tube(t_tube *tube)
{
	while (tube)
	{
		ft_putstr(tube->next->name);
		ft_putstr("->");
		tube = tube->tube_next;
	}
}

void		ft_display_room(t_room *room)
{
	while (room)
	{
		ft_putstr(room->name);
		ft_putstr("\tROOM PATH ");
		ft_putnbr(room->path);
		ft_putstr("\tINDEX  ");
		ft_putnbr(room->index);
		ft_putchar('\t');
		ft_display_tube(room->tube);
		ft_putchar('\n');
		ft_putstr("ID\t");
		ft_putnbr(room->nbr_fourmi);
		ft_putendl("");
		room = room->next;
	}
}

void		ft_exit(int keycode)
{
	if (keycode == 0)
		ft_putendl("ERROR");
	if (keycode == -1)
		ft_putendl("ERROR MALLOC");
	exit(0);
}

t_tube		*ft_new_tube(t_room *room)
{
	t_tube	*new;

	new = (t_tube*)malloc(sizeof(t_tube));
	new->next = room;
	return (new);
}
