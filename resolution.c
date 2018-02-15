/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:17:41 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/15 20:20:51 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

#define NOEUD 2
#define FALSE -1
#define TRUE 1



int     secur_path(t_room *room, char *name)
{
    t_tube *tmp;
    int tmp_int;

    ft_putstr(room->name);
    ft_putchar('\t');
    ft_putnbr(room->path);
    ft_putchar('\n');


    if (room->type_of_room == END || room->path == TRUE)
    {
            ft_putendl("Emd");
            room->path = TRUE;
            return (TRUE);
    }
    if (room->path == NOEUD)
    {
        room->path = FALSE;
        return (0);
    }
    if (room->path == 0)
    {
        room->path = NOEUD;
        tmp = room->tube;
        while (tmp)
        {
            if (!ft_strequ(tmp->next->name, name))
            {
                if ((tmp_int = secur_path(tmp->next, room->name)))
                {
                    if (tmp_int == TRUE && !ft_strequ(room->name, name))
                    {
                        room->path = tmp_int;
                        return (TRUE);
                    }
                }
            }
            tmp = tmp->tube_next;
        }
    }
    return (FALSE);
}

void    resolution(t_param *p)
{
    t_room   *room;
//    int i = 1;

    ft_display_room(p->head->next);
    room = p->head->next;
    while (room)
    {
        if (room->type_of_room == START)
            break ;
        room = room->next;
    }
    ft_putendl(room->name);
    secur_path(room, room->name);
    ft_putendl("oui");
    ft_display_room(room);

    //on commence a la fourmi la plus avancé

//    path_fourmi = crea_path_fourmi(room);
//    while (i <= nbr_fourmi)//
//    {
//        path_fourmi[i] = path_fourmi[i]->next;
//        ft_aff(path_fourmi[i]->next);
//    }
}
