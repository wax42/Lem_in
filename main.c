/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:32:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 06:35:14 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_room 		*ft_check(char *line, t_param *p, t_room *head)
{
	int keycode;
	int sub;
	char *name;
	t_room *room;

	room = head;
	if ((keycode = ft_check_htag(line) > 0))
	{
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	if ((sub = ft_parse_room(line)))
	{
		ft_putstr("OUI\n\n");
		name = ft_strsub(line, 0, sub);
		while (room->next)
		{
			ft_putstr("sale enfoiré\n");
			ft_putendl(room->next->name);
			ft_putstr("sale fpd\n");
			if (ft_strequ(name, room->name))
				ft_exit(0);
			room = room->next;
		}
		ft_putendl(name);
		room->next = ft_crea_room(p, keycode, name);
	}
//	else if (ft_check_tube(line, room))
//	{
//		while (room->next)
//		{
//			ft_putstr("sale enfoiré\n");
//			ft_putendl(room->next->name);
//			ft_putstr("sale fpd\n");
//			if (ft_strequ(name, room->name))
//				ft_exit(0);
//			room = room->next;
//		}
//		ft_putendl(name);
//		room->next = ft_crea_tub();
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
		ft_putendl(line);
		head = ft_check(line, p, head);
		ft_strdel(&line);
	}
	return (head);
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
	return (0);
}
