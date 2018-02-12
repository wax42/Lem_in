/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:12:26 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/12 23:33:24 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "__LEM_IN_H__"
# define __LEM_IN_H__
# include "lem_in.h"
# include "libft/libft.h"

typedef struct s_tube
{
	struct s_room *next;
	struct s_tube *tube_next;
}				t_tube;


typedef struct s_room
{
	char 		*name;
	int 		nbr_fourmi;
	int 		nbr_tube;
	struct s_room 	*next;
	t_tub    	*tube;
}				t_room;

typedef struct s_param
{
	char *start;
	char *end;
	t_room *head;
	size_t 	nbr_fourmi;
}				t_param
