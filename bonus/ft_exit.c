/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 13:59:44 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/16 15:03:07 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bonus.h"

static void	ft_aff_error(int code)
{
	if (code == -1)
		ft_putendl("ESC");
	else if (code == 0)
		ft_putstr("Usage : ./graph <filename>  || ./Lem_in < 'Fichier_input' | ./graph\n");
	else if (code == 1)
		ft_putstr("READ ERROR\n");
	else if (code == 3)
		ft_putendl("MALLOC ERROR\n");
	else if (code == 2)
	{
		ft_putstr("\nGame End\n");
	}
	else
		ft_putnbr(code);
}

int			ft_exit(int i)
{
	ft_aff_error(i);
	exit(0);
}
