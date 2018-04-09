/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:11:22 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/27 01:03:50 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int		ft_parse_room(char *line)
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
	return ((sub > 0) ? sub : -1);
}

t_room	*ft_crea_room(t_param *p, int keycode, char *name)
{
	t_room *new_room;

	if (!(new_room = (t_room*)malloc(sizeof(t_room))))
		ft_exit(-1);
	if (keycode == END || keycode == -1)
		new_room->nbr_fourmi = 0;
	else if (keycode == START)
		new_room->nbr_fourmi = p->nbr_fourmi;
	new_room->type_of_room = keycode;
	new_room->name = ft_strdup(name);
	new_room->next = NULL;
	new_room->path = 0;
	new_room->index = -1;
	new_room->nbr_fourmi = 0;	
	new_room->tube = NULL;
	return (new_room);
}
