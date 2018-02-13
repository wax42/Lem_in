/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_tube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:50 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/13 04:16:54 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int			ft_check(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '-')
			count++;
		else if (!ft_isalnum(str[i]))
			exit (0);
		i++;
	}
	return (count == 1) ? 1 : 0;
}

void		ft_check_tube(char *str, char **room1, char **room2)
{
	int i;

	i = 0;
	if (!ft_check(str))
		exit(0);
	while (str[i])
	{
		if (str[0] == '-')
			exit(0);
		if (str[i] == '-')
		{
			*room1 = ft_strsub(str, 0, i);
			*room2 = ft_strsub(str, i + 1, ft_strlen(str));
		}
		i++;
	}
	if (!ft_strlen(*room2))
		exit (0);
}

t_room		*ft_get_room(char *room, t_param *p)
{
	t_room	*myroom;

	myroom = p->head->next;
	while (!ft_strequ(myroom->name, room) || myroom->next != NULL)
		myroom = myroom->next;
	return (myroom);
}


int 	ft_crea_tube(char *str, t_param *p)
{
	char	*room1;
	char	*room2;
	t_room	*room_1;
	t_room	*room_2;
	t_tube	*tube;

	ft_putendl(str);
	ft_check_tube(str, &room1, &room2);
	room_1 = ft_get_room(room1, p);
	ft_putendl("yes");
	room_2 = ft_get_room(room2, p);
	tube = room_1->tube->tube_next;
	while (tube)
		tube  = tube->tube_next;

	tube = (t_tube*)malloc(sizeof(t_tube));
	tube->next = room_2;
	return (1);
}
