/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:11:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 03:47:10 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"


int ft_parse_room(char *line)
{
	int i;
	int tmp;
	int sub;

	i = 0;
	tmp = i;
	while (line[i] != 'L' && ft_isalnum(line[i]))
		i++;
	sub = i;
	if (tmp == i)
		return (0);
	while (line[i] == ' ')
		i++;
	tmp = i;
	while ((ft_isdigit(line[i])))
		i++;
	if (tmp == i)
		return (0);
	while (line[i] == ' ')
		i++;
	tmp = i;
	while ((ft_isdigit(line[i])))
		i++;
	if (tmp == i)
		return (0);
	return (sub);
}

int	ft_crea_room(char *line, t_param *p, int keycode)
{
	t_room *room;
	t_room *new_room;
	char *name;
	int sub;

	if (!(sub = ft_parse_room(line)))
		return (0);
	name = ft_strsub(line, 0, sub);
	ft_putendl(name);
	room = p->head;
	while (room && room->next)
	{
		ft_putstr("je rentre pas");
		if ((ft_strequ(name, room->name)))
			ft_exit(0);
		room = room->next;
	}
	ft_putstr("pute");
	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		ft_exit(-1);
	if (keycode == 0 || keycode == END)
		new_room->nbr_fourmi = 0;
	else if (keycode == START)
		new_room->nbr_fourmi = p->nbr_fourmi;
	new_room->type_of_room = keycode;
	new_room->name = name;
	new_room->next = NULL;
	if (!(new_room->tube = (t_tube*)malloc(sizeof(t_tube))))
		ft_exit(-1);
	room->next = new_room;
	p->head->next = room;
	sleep(4);
	return (1);
}
