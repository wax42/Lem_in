/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:32:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/14 15:24:22 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_room 		*ft_check(char *line, t_param *p, t_room *head)
{
	int keycode;
	int sub;
	char *name;
	t_room *room;
	t_room *target;

	room = head;
	if ((keycode = ft_check_htag(line) > 0))
	{
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	if ((sub = ft_parse_room(line)))
	{
		name = ft_strsub(line, 0, sub);
		while (room->next)
		{
			if (ft_strequ(name, room->name))
				ft_exit(0);
			room = room->next;
		}
		room->next = ft_crea_room(p, keycode, name);
	}
	else if ((room = ft_crea_tube(line, head, &target)))
	{
		if (room->tube == NULL)
		{
			ft_putstr("FIRST ELEM\n");
			ft_putendl(target->name);
			room->tube = ft_new_tube(target);
			room->tube->tube_next = NULL;
		}
		else
			room->tube = ft_add_tube(room->tube, target);
		if (target->tube == NULL)
		{
			target->tube = ft_new_tube(room);
			target->tube->tube_next = NULL;
		}
		else
			target->tube = ft_add_tube(target->tube, room);
	}
	return (head);
}

t_room 		*ft_read(t_param *p)
{
	t_room *head;
	char *line;

	if (!(head = (t_room*)malloc(sizeof(t_room))))
		ft_exit(-1);
	head->type_of_room = -1;
	head->next = NULL;
	head->name = NULL;
	while (get_next_line(0, &line))
	{
		head = ft_check(line, p, head);
		ft_strdel(&line);
	}
	return (head);
}

void		ft_display_tube(t_tube *tube)
{
	while (tube)
	{
		ft_putstr("->");
		ft_putstr(tube->next->name);
		tube = tube->tube_next;
	}
}

void		ft_display_room(t_room *room)
{
	while (room)
	{
		ft_putstr(room->name);
		ft_display_tube(room->tube);
		ft_putendl("");
		room = room->next;
	}
}

int main(void)
{
	t_param p;
	char *line;

	get_next_line(0, &line);
	p.nbr_fourmi = ft_atoi(line);
	ft_strdel(&line);
	if (!p.nbr_fourmi)
		ft_putstr("error 1");
	p.head = ft_read(&p);
	ft_display_room(p.head->next);
	return (0);
}
