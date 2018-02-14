/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_tube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:50 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/14 10:23:36 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int			ft_check_t(char *str)
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

	if (!ft_check_t(str))
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

t_room		*ft_get_room(char *room, t_room *head)
{
	t_room	*myroom;

	myroom = head->next;
	while (myroom->next)
	{
		if (ft_strequ(myroom->name, room))
			return (myroom);
		else
			myroom = myroom->next;
	}
	return (myroom);
}


t_tube		*ft_new_tube(t_room *room)
{
	t_tube  *new;

	new = (t_tube*)malloc(sizeof(t_tube));
	new->tube_next = NULL;
	new->next = room;
	return (new);
}

t_room		*ft_crea_tube(char *str, t_room *room, t_room **target)
{
	char	*room1;
	char	*room2;
	t_room	*room_1;
	t_room	*room_2;

	ft_check_tube(str, &room1, &room2);
	room_1 = ft_get_room(room1, room);
	room_2 = ft_get_room(room2, room);
	*target = room_2;
	/*
	if (room_1->tube->next == NULL)
	{
		room_1->tube->tube_next = NULL;
		room_1->tube->next = room_2;
	}
	else
		ft_putstr("OK");
*/
		return (room_1);
}
