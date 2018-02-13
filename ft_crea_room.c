/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:11:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 01:20:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int ft_parse_room(char *line)
{
	int i;
	int tmp;
	int sub;

	i = 0;
	tmp = i;
	while (ft_isalnum(line[i]) && line[i] != 'L')
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
	room = p->head->next;
	while (room)
	{
		if (!(ft_strequ(name, room->name)))
			ft_exit(0);
		room = room->next;
	}
	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		ft_exit(-1);
	if (keycode == 0 || keycode == END)
		new_room->nbr_fourmi = 0;
	else if (keycode == START)
		new_room->nbr_fourmi = p->nbr_fourmi;
	new_room->type_of_room = keycode;
	new_room->name = name;
	new_room->next = NULL;
	room->next = new_room;
	return (1);
}
