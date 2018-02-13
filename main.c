/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:32:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 01:50:07 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"


int main(void)
{
	t_param p;
	char *line;

	if (!(p.head = (t_room*)malloc(sizeof(t_room))))
		ft_exit(-1);
	p.head->next = NULL;
	while (get_next_line(0, &line))
	{
		if ((ft_check_htag(line, &p) || ft_crea_room(line, &p, 0) ))//|| ft_crea_tub(line, &p)))
			ft_strdel(&line);
		else
			ft_putstr("ERROR ? ");
	}
}
