/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_tube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:50 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/14 17:18:14 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_tube		*ft_add_tube(t_tube *head, t_room *target)
{
	t_tube	*tmp;

	tmp = ft_new_tube(target);
	tmp->tube_next = head;
	return (tmp);
}

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
			ft_exit(0);
		i++;
	}
	return (count == 1) ? 1 : 0;
}

void		ft_check_tube(char *str, char **room1, char **room2)
{
	int i;

	i = 0;

	if (!ft_check_t(str))
		ft_exit(0);
	while (str[i])
	{
		if (str[0] == '-')
			ft_exit(0);
		if (str[i] == '-')
		{
			*room1 = ft_strsub(str, 0, i);
			*room2 = ft_strsub(str, i + 1, ft_strlen(str));
		}
		i++;
	}
	if (!ft_strlen(*room2))
		ft_exit(0);
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
	return (room_1);
}
