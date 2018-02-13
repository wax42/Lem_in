/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:12:26 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/13 06:17:32 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H
# include "../libft/libft.h"
# define START 1
# define END 2

typedef struct s_tube
{
	struct s_room *next;
	struct s_tube *tube_next;
}				t_tube;


typedef struct s_room
{
	int 		type_of_room;
	char 		*name;
	int 		nbr_fourmi;
	int 		nbr_tube;
	struct s_room 	*next;
	t_tube    	*tube;
}				t_room;

typedef struct s_param
{
	t_room *head;
	size_t 	nbr_fourmi;
}				t_param;


void  	ft_exit(int keycode);

int 	ft_check_htag(char *line);

t_room	*ft_crea_room(t_param *p, int keycode, char *name);

int 	ft_parse_room(char *line);


int 	ft_crea_tube(char *str, t_param *p);

#endif
