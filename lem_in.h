/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:12:26 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/12 23:12:55 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "__LEM_IN_H__"
# define __LEM_IN_H__
# include "lem_in.h"
# include "libft.h"

typedef struct s_tub
{
	struct s_room *next;
	struct s_tub *tub_next;
}


typedef struct s_room
{
	char 		*name;
	int 		nbr_fourmi;
	int 		nbr_tube;
	struct s_room 	*next;
	t_tub    	*tub;
}
