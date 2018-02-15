/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_htag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:41:50 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/14 18:33:59 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

int		ft_check_htag(char *line)
{
	if ((ft_strequ(line, "##start")))
		return (START);
	else if ((ft_strequ(line, "##end")))
		return (END);
	else if (line[0] == '#')
		return (3);
	return (0);
}
