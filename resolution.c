/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:17:41 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/23 02:37:00 by mbarthe          ###   ########.fr       */
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

void        ft_path(t_room *room, int index)
{
    t_tube *tmp;

    tmp = room->tube;
    while (tmp)
    {
        if (tmp->next->path > 0 || tmp->next->type_of_room == START) ///essaye avec == 1
        {
            if (tmp->next->index > index || tmp->next->index == -1)
            {
                tmp->next->index = index;
                ft_path(tmp->next, index + 1);
            }
        }
        tmp = tmp->tube_next;
    }
}

t_tube  *ft_calcul(t_tube *tube)
{
    int a;
    t_tube *adress;

    a = -1;
    adress = NULL;
    while (tube)
    {
        if (a > tube->n && tube->next->path > 0 && !tube->next->nbr_fourmi)
        {
            a = tube->n;
            adress = tube;
        }
        tube = tube->tube_next;
    }
    return (adress);
}

void   ft_aff(int id, char *name)
{
    ft_putchar('L');
    ft_putnbr(id);
    ft_putchar('-');
    ft_putstr(name);
    ft_putchar(' ');
}

int    ft_generation(t_room *room, int n)
{
    t_tube *tmp;

    if (room->type_of_room == END)
            return (n);
    if (room->nbr_fourmi == 1)
        n = n + 1;
    tmp = room->tube;
    while (tmp)
    {
        if (tmp->next->index >= room->index)
            tmp->n = ft_generation(tmp->next, n + 1);
        tmp = tmp->tube_next;
    }
    if ((tmp = ft_calcul(room->tube)))
    {
        ft_aff(room->id, room->tube->next->name);
        room->tube->next->id = room->id;
        room->id = 0; // SECURITE
        room->nbr_fourmi = 0;
        tmp->next->nbr_fourmi++;
    }
    return (n);
}



void    resolution(t_param *p)
{
    t_room   *room;
    t_room   *target;
    size_t id = 1;

    //ft_display_room(p->head->next);
    room = p->head->next;
    target = room;
    while (room)
    {
        if (room->type_of_room == START)
            break ;
        room = room->next;
    }
    while (target)
    {
        if (target->type_of_room == END)
            break ;
        target = target->next;
    }
    ft_putendl(room->name);
    ft_putnbr(room->nbr_fourmi);
    secur_path(room, room->name);
    if (room->path > 0 || room->type_of_room == START)
    {
        if (room->index > 0 || room->index == -1)
            room->index = 0;
    }
    ft_path(room, 1);
    while (p->nbr_fourmi < id)
    {
        while (room->tube)
        {
            room->next->id = id;
            room->tube->n = ft_generation(room, 0);
            //ft_calcul(*dist);
            ft_putchar('\n');
            // si le path est valide
            room->tube = room->tube->tube_next;
        }
    }
    ft_display_room(room);

    //on commence a la fourmi la plus avancé

//    path_fourmi = crea_path_fourmi(room);
//    while (i <= nbr_fourmi)//
//    {
//        path_fourmi[i] = path_fourmi[i]->next;
//        ft_aff(path_fourmi[i]->next);
//    }
}
