/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 00:03:14 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 01:16:41 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void  	ft_exit(int keycode)
{
	if (keycode == 0)
		ft_putendl("ERROR");
	if (keycode == -1)
		ft_putendl("ERROR MALLOC");
	exit(0);
}
