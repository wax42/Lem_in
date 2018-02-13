/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_htag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:41:50 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 01:46:49 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int 	ft_check_htag(char *line, t_param *p)
{
	int keycode;

	if (ft_strstr(line , "#"))
	{
		ft_strdel(&line);
		return (1);
	}
	 if (!(ft_strstr(line, "##")))
	 	ft_exit(0);
	if ((ft_strstr(line, "start")))
		keycode = START;
	if ((ft_strstr(line, "end")))
		keycode = END;
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_crea_room(line, p, keycode);
	return (1);
}
