/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 08:51:29 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/23 02:32:09 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

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
		ft_putendl("");
		room = room->next;
	}
}

void	ft_exit(int keycode)
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

t_tube		*ft_add_tube(t_tube *head, t_room *target)
{
	t_tube	*tmp;

	tmp = ft_new_tube(target);
	tmp->tube_next = head;
	tmp->n = 0;
	return (tmp);
}
