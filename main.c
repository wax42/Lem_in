/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:32:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 05:33:51 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_room 		ft_check(char *line, t_param *p, t_room *room)
{
	int keycode;

	if (keycode = ft_check_htag(line, &p) > 0)
	{
		ft_strdel(&line);
		get_next_line(0, &line);
	}
	if (ft_check_form(line))
	{
		return (ft_crea_room(line, p, keycode, room));
	}
	else if (ft_check_tube(line, room))
	{
		return (ft_crea_tube(line, &p, room))
	}
}

t_room 		ft_read(t_param *p)
{
	t_room *head;

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
}
