/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:32:19 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/12 23:32:58 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

int main(void)
{
	t_param p;
	char *line;

	while (get_next_line(0, &line))
	{
		ft_check_htag(line, &p);
		ft_crea_room(line, &p);
		ft_crea_tub(line, &p);
	}
}
