/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:17:41 by mbarthe           #+#    #+#             */
/*   Updated: 2018/02/27 19:20:25 by vguerand         ###   ########.fr       */
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
        if (tmp->next->path == 1 || tmp->next->type_of_room == START) ///essaye avec == 1
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

void   ft_aff(int id, char *name)
{
    ft_putchar('L');
    ft_putnbr(id);
    ft_putchar('-');
    ft_putstr(name);
    ft_putchar(' ');
}

int  ft_deplace(t_room *room, int id)
{
    t_tube *tube;
    t_room *tmp;

    tube = room->tube;
    tmp = room;
    // ft_putstr(room->name);
    // ft_putstr("oui ");
    while (tube)
    {
        // ft_putstr("o");
        if (room->index <= tube->next->index && (tube->next->nbr_fourmi == 0 || tube->next->type_of_room == END))
        {
          ft_aff(id, tube->next->name);
          room->nbr_fourmi = 0;
          if (tube->next->type_of_room == END)
            return (1);
          else
            tube->next->nbr_fourmi = id;
          return (0);
        }
        tube = tube->tube_next;
    }
    return (-1);
}

t_room    *ft_envoi_room(t_room *room, int id)
{
  t_room   *tmp;

  tmp = room;
  while (tmp)
  {
    if (tmp->type_of_room != END && tmp->type_of_room != START && tmp->nbr_fourmi == id)
        return (tmp);
    tmp = tmp->next;
  }
  return (NULL);
}

t_room    *ft_find_start(t_room *room)
{
  t_room   *tmp;

  tmp = room;
  while (tmp)
  {
    if (tmp->type_of_room == START)
        return (tmp);
    tmp = tmp->next;
  }
  return (NULL);
}

void    resolution(t_param *p)
{
    t_room   *tmp;
    t_room   *room;
    t_room   *target;
    int id;
    int decal;
    int ret;

    decal = 0;

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
    secur_path(room, room->name);
    ft_path(room, 1);

    if (room->path > 0 || room->type_of_room == START)
    {
        if (room->index > 0 || room->index == -1)
            room->index = 0;
    }
    ft_display_room(room);
    while (target->nbr_fourmi != p->nbr_fourmi)
    {
        id = target->nbr_fourmi + 1;   //generation
        sleep(2);
        // ft_putstr("generation \n");
        while (p->nbr_fourmi >= id)
        {
          // ft_putnbr(id);
            if ((tmp = ft_envoi_room(p->head->next, id)))
            {
              ret = ft_deplace(tmp, id);
              if (ret != -1)
                target->nbr_fourmi += ret;
            }
            id++;
        }
        // ft_putstr("START \n");
        // ft_putnbr(decal);
        // ft_putstr("NBR_FOURMI \n");
        // ft_putnbr(p->nbr_fourmi);
        id = decal + 1; //lancer de start
        tmp = ft_find_start(p->head->next);
        ft_putnbr(p->nbr_fourmi);
        while (p->nbr_fourmi >= id)
        {
            // ft_putstr(" \n TEST \n");
            // ft_putnbr(id);
            ret = ft_deplace(tmp, id);
            if (ret != -1)
            {
              target->nbr_fourmi += ret;
              decal += 1;
            }
            // ft_putstr("fils de pute");
            id++;
        }
        if (target->nbr_fourmi < p->nbr_fourmi)
          ft_putchar('\n');
        // ft_display_room(room);
    }
    sleep(2);
}
