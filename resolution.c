/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:17:41 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/27 20:07:44 by mbarthe          ###   ########.fr       */
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

    if (room->type_of_room == END || room->path == TRUE)
    {
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
                if ((tmp_int = secur_path(tmp->next, name)))
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

t_tube  *ft_calcul(t_tube *tube, int index)
{
    int a;
    t_tube *adress;

    a = tube->n;
    adress = NULL;
    while (tube)
    {
        if (a > tube->n && (tube->next->path == 1 || tube->next->type_of_room == END))
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

void  ft_noeud_init(t_room *room)
{
    t_tube *tube;

    tube = room->tube;
    while (tube)
    {
        if (room->index > tube->next->index && tube->next->index != -1 && tube->next->nbr_fourmi)
            room->pa++;
        tube = tube->tube_next;
    }
}

int  ft_start(t_room *room, int id, int fourmi_rest)
{
    t_tube *tube;
    int tmp_dist;
    int old_dist;
    t_room *tmp;

    tube = room->tube;
    tmp = room->tube->next;
    tmp_dist = ft_distance(tmp);
    while (tube->next)
    {
        if (room->index <= tube->next->index && !tube->next->nbr_fourmi)
        {
            old_dist = tmp_dist;
            if ((tmp_dist = ft_distance(tube->next)) < old_dist)
                tmp = tube->next;
        }
        tube = tube->tube_next;
    }
    if (fourmi_rest - tmp_dist > 0)
    {
        ft_aff(id, tmp->name);
        tmp->id = id;
        tmp->nbr_fourmi++;
        //room->id = 0; // SECURITE
        //room->nbr_fourmi = 0;
    }
    else
        return (1);
    return (0);
}

int    ft_distance(t_room *room, int n)
{
    t_tube *tmp;

    if (room->type_of_room == END)
            return (n);
    ft_noeud_init(room);
    tmp = room->tube;
    while (tmp)
    {
        if (tmp->next->index >= room->index)
            n = ft_distance(tmp->next, n + 1);
        if (tmp->next->pa != -1)
            tmp->n = n + tmp->next->pa;
        else
            tmp->n = n;
        tmp = tmp->tube_next;
    }
    if ((tmp = ft_calcul(room->tube)))
        n = tmp->n;
    return (n);
}

void    resolution(t_param *p)
{
    t_room   *room;
    t_room   *target;
    // t_tube   *tmp;
    int id = 1;

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
    //ft_putendl(room->name);
    //ft_putnbr(room->nbr_fourmi);
    secur_path(room, room->name);
    if (room->path > 0 || room->type_of_room == START)
    {
        if (room->index > 0 || room->index == -1)
            room->index = 0;
    }
    ft_path(room, 1);
    //ft_putendl("");
    //ft_putendl("On passe a la fin");
    ft_display_room(room);
    while (target->nbr_fourmi != id)
    {
        while (p->nbr_fourmi >= id)
        {
            if ((ft_start(room, id, p->nbr_fourmi)))
                break ;
            id++;
        }
        ft_generation(room); //va update le PA et faire avancer les fourmis
    }
}
