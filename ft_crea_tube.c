/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crea_tube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:40:50 by mbarthe           #+#    #+#             */
/*   Updated: 2018/04/11 01:35:54 by mbarthe          ###   ########.fr       */
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
			return (0);
		i++;
	}
	return (count == 1) ? 1 : 0;
}

int		ft_check_tube(char *str, char **room1, char **room2)
{
	int i;

	i = 0;
	if (!ft_check_t(str))
		return (0);
	while (str[i])
	{
		if (str[0] == '-')
			return (0);
		if (str[i] == '-')
		{
			*room1 = ft_strsub(str, 0, i);
			*room2 = ft_strsub(str, i + 1, ft_strlen(str));
		}
		i++;
	}
	if (!ft_strlen(*room2))
		return (0);
	return (1);
}

t_room		*ft_get_room(char *room, t_room *head)
{
	t_room	*myroom;

	myroom = head->next;
	while (myroom)
	{
		if (ft_strequ(myroom->name, room))
			return (myroom);
		else
			myroom = myroom->next;
	}
	return (NULL);
}

t_room		*ft_crea_tube(char *str, t_room *room, t_room **target)
{
	char	*room1;
	char	*room2;
	t_room	*room_1;
	t_room	*room_2;

	if (!ft_check_tube(str, &room1, &room2))
		return (NULL);
	room_1 = ft_get_room(room1, room);
	room_2 = ft_get_room(room2, room);
	if (!room_1 || !room_2)
		ft_exit (0);
	if (!ft_strcmp(room1, room2))
		return (NULL);
	*target = room_2;
	ft_strdel(&room1);
	ft_strdel(&room2);
	return (room_1);
}
