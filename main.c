/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:32:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/04/11 02:30:15 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int    ft_tube_exists(t_room *room, t_room *target)
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

void	ft_tube_link(t_room *room, t_room *target)
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

t_room	*ft_check(t_lines **tmp, t_param *p, t_room *head)
{
	int		keycode;
	int		sub;
	t_room	*room;
	t_room	*target;

	room = head;
	while ((keycode = ft_check_htag((*tmp)->line)) > 0)
	{
		if (keycode == 1 || keycode == 2)
		{
			(*tmp) = (*tmp)->next;
			while (ft_check_htag((*tmp)->line) == 3)
				(*tmp) = (*tmp)->next;
			break ;
		}
		(*tmp) = (*tmp)->next;
	}
	if ((sub = ft_parse_room((*tmp)->line)))
		ft_room_link((*tmp)->line, room, sub, p, keycode);
	else if ((room = ft_crea_tube((*tmp)->line, head, &target)))
		ft_tube_link(room, target);
	else
		return (NULL);
	return (head);
}

t_room	*ft_read(t_param *p, t_lines *to_parse)
{
	t_room	*head;
	t_room	*ret;

	t_lines *tmp;

	tmp = to_parse;
	if (!(head = (t_room*)malloc(sizeof(t_room))))
		ft_exit(-1);
	head->type_of_room = -1;
	head->index = -1;
	head->next = NULL;
	head->name = NULL;
	tmp = ft_ant_nbr(p, tmp);
	while (tmp)
	{
		if (!(ret = ft_check(&tmp, p, head)))
			return (head);
		else
			head = ret;
		tmp = tmp->next;
	}
	return (head);
}

t_lines		*ft_link_lines(void)
{
	int ret;
	int start;
	int end;
	t_lines *tmp;
	t_lines *new;
	t_lines *header;

	start = 0;
	end = 0;
	header = (t_lines*)malloc(sizeof(t_lines));
	if ((get_first_line(0, &header->line) == -1))
		ft_exit(0);
	ret = -1;
	while(header->line[++ret])
	{
		if (!ft_isprint(header->line[ret]))
			ft_exit(0);
	}
	tmp = header;
	ret = 1;
	while (ret > 0)
	{

		new = (t_lines*)malloc(sizeof(t_lines));
		ret = get_next_line(0, &new->line);
		if ((ft_strequ(tmp->line, "##start")))
			start++;
		else if ((ft_strequ(tmp->line, "##end")))
			end++;
		tmp->next = new;
 		tmp = new;
	}
	if (start != 1 || end != 1)
		ft_exit(0);
	tmp->next = NULL;
	return (header);
}

int	main(void)
{
	t_param	p;
	t_lines *to_parse;

	to_parse = ft_link_lines();
	p.head = ft_read(&p, to_parse);
	if (p.head->next == NULL)
		ft_exit (0);
	resolution(&p, to_parse);
	return (0);
}
