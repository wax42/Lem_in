/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:12:26 by vguerand          #+#    #+#             */
/*   Updated: 2018/04/11 00:01:05 by mbarthe          ###   ########.fr       */
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
	int 		path;
	int 		type_of_room;
	char 		*name;
	int 		nbr_fourmi;
	int 		index;
	int 		time;
	int 		nbr_tube;
	struct s_room 	*next;
	t_tube    	*tube;
}				t_room;

typedef struct s_param
{
	t_room *head;
	int 	nbr_fourmi;
}				t_param;

typedef struct s_lines
{
	char *line;
	struct s_lines *next;
}				t_lines;

void         ft_display_lines(t_lines *header);

void    resolution(t_param *p, t_lines *header);

void  	ft_exit(int keycode);

t_lines    *ft_ant_nbr(t_param *p, t_lines *tmp);

void		ft_display_tube(t_tube *tube);

void		ft_display_room(t_room *room);

int 	ft_check_htag(char *line);

t_room	*ft_crea_room(t_param *p, int keycode, char *name);

int 	ft_parse_room(char *line);

t_room		*ft_crea_tube(char *str, t_room *room, t_room **target);

t_tube		*ft_new_tube(t_room *room);

t_tube		*ft_add_tube(t_tube *head, t_room *target);

#endif
