/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:32:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/22 22:30:15 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void	ft_tube_link(t_room *room, t_room *target)
{
	if (room->tube == NULL)
	{
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

void	ft_room_link(char *line, t_room *room, int sub, t_param *p, int keycode)
{
	char	*name;

	//ft_putendl(line);
	name = ft_strsub(line, 0, sub);
	while (room->next)
	{
		if (ft_strequ(name, room->name))
			ft_exit(0);
		room = room->next;
	}
	room->next = ft_crea_room(p, keycode, name);
}

t_room	*ft_check(char **line, t_param *p, t_room *head)
{
	int		keycode;
	int		sub;
	t_room	*room;
	t_room	*target;

	room = head;
	ft_putendl(*line);
	if ((keycode = ft_check_htag(*line)) > 0)
	{
		ft_strdel(line);
		get_next_line(0, line);
		ft_putendl(*line);
	}
	if ((sub = ft_parse_room(*line)))
		ft_room_link(*line, room, sub, p, keycode);
	else if ((keycode != 3) && (room = ft_crea_tube(*line, head, &target)))
		ft_tube_link(room, target);
	else
		ft_putendl(*line);
	return (head);
}

t_room	*ft_read(t_param *p)
{
	t_room	*head;
	char	*line;

	if (!(head = (t_room*)malloc(sizeof(t_room))))
		ft_exit(-1);
	head->type_of_room = -1;
	head->index = -1;
	head->next = NULL;
	head->name = NULL;
	while (get_next_line(0, &line) > 0)
	{
		head = ft_check(&line, p, head);
		ft_strdel(&line);
	}
	return (head);
}

int	main(void)
{
	t_param	p;
	char	*line;
	char	*tmp;
	char	buf[1];

	line = ft_strnew(0);
	while ((read(0, buf, 1)) > 0)
	{
		if (buf[0] == '\n')
			break ;
		if (buf[0] == '\0')
			ft_exit(0);
		if (!ft_isdigit(buf[0]))
			ft_exit(0);
		tmp = line;
		line = ft_strjoin(buf, line);
		ft_putstr(line);
		ft_strdel(&tmp);
	}
	p.nbr_fourmi = ft_atoi(line);
	ft_strdel(&line);
	if (!p.nbr_fourmi)
		ft_exit(0);
	p.head = ft_read(&p);
	resolution(&p);
	return (0);
}
