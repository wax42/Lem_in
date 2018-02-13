/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_htag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:41:50 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 05:51:55 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int 	ft_check_htag(char *line)
{
	if ((ft_strstr(line, "#")))
			return (-1);
	if (!(ft_strstr(line , "##")))
		return (0);
	if ((ft_strstr(line, "start")))
		return (START);
	if ((ft_strstr(line, "end")))
		return (END);
	return (1);
}
