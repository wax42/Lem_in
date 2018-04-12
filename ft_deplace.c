/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deplace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:01:16 by vguerand          #+#    #+#             */
/*   Updated: 2018/04/12 16:01:18 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

void	ft_aff(int id, char *name, int *state)
{
	if (*state == 1)
		*state = 0;
	else
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(id);
	ft_putchar('-');
	ft_putstr(name);
}

int		ft_deplace(t_room *room, int id, int *state)
{
	t_tube *tube;
	t_room *tmp;

	tube = room->tube;
	tmp = room;
	while (tube)
	{
		if ((room->index > tube->next->index && tube->next->index != -1) && \
		(tube->next->nbr_fourmi == 0 || tube->next->type_of_room == END))
		{
			ft_aff(id, tube->next->name, state);
			room->nbr_fourmi = 0;
			if (tube->next->type_of_room == END)
				return (1);
			else
				tube->next->nbr_fourmi = id;
			return (0);
		}
		tube = tube->tube_next;
	}
	tube = room->tube;
	tmp = room;
	while (tube)
	{
		if ((room->index == tube->next->index && tube->next->index != -1) && \
		(tube->next->nbr_fourmi == 0 || tube->next->type_of_room == END))
		{
			ft_aff(id, tube->next->name, state);
			room->nbr_fourmi = 0;
			if (tube->next->type_of_room == END)
				return (1);
			else
				tube->next->nbr_fourmi = id;
			return (0);
		}
		tube = tube->tube_next;
	}
	return (-1);
}
