/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:17:41 by mbarthe           #+#    #+#             */
/*   Updated: 2018/04/11 02:33:22 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

#define NOEUD 2
#define FALSE -1
#define TRUE 1

int     secur_path(t_room *room)
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
          if ((tmp_int = secur_path(tmp->next)))
          {
              if (tmp_int == TRUE)
              {
                  room->path = tmp_int;
                  return (TRUE);
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

void   ft_aff(int id, char *name, int *state)
{
    if (*state == 1)
      *state = 0;
    else
      ft_putchar(' ');
    ft_putchar('L');
    ft_putnbr(id);
    ft_putchar('-');
    ft_putstr(name);
}

int  ft_deplace(t_room *room, int id, int *state)
{
    t_tube *tube;
    t_room *tmp;

    tube = room->tube;
    tmp = room;
    while (tube)
    {
        if ((room->index > tube->next->index && tube->next->index != -1) && (tube->next->nbr_fourmi == 0 || tube->next->type_of_room == END))
        {
          ft_aff(id, tube->next->name, state);
          room->nbr_fourmi = 0;
          if (tube->next->type_of_room == END)
            return (1);
          else
            tube->next->nbr_fourmi = id;
          return (0);
        }
        tube = tube->tube_next;
    }
    tube = room->tube;
    tmp = room;
    while (tube)
    {
        if ((room->index == tube->next->index && tube->next->index != -1) && (tube->next->nbr_fourmi == 0 || tube->next->type_of_room == END))
        {
          ft_aff(id, tube->next->name, state);
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

void    ft_secure(t_room *head)
{
    int count;
    t_room *tmp;

    count = 0;
    tmp = head;
    while(tmp)
    {
        if (tmp->index != -1 && tmp->index != 0)
            count = 1;
        tmp = tmp->next;
    }
    if (count == 0)
        ft_exit(0);
}

void    resolution(t_param *p, t_lines *header)
{
    t_room   *tmp;
    t_room   *room;
    t_room   *target;
    int id;
    int decal;
    int ret;
    int state;

    decal = 0;
    state = 1;
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
    secur_path(room);
    if (target->path > 0 || target->type_of_room == END)
    {
        if (target->index > 0 || target->index == -1)
            target->index = 0;
    }
    ft_path(target, 1);
    ft_secure(p->head->next);
    ft_display_lines(header);
    while (target->nbr_fourmi != p->nbr_fourmi)
    {
        // ft_display_room(room);
        id =  1;   //generation
        while (p->nbr_fourmi >= id)
        {
            if ((tmp = ft_envoi_room(p->head->next, id)))
            {
              ret = ft_deplace(tmp, id, &state);
              if (ret != -1)
                target->nbr_fourmi += ret;
            }
            id++;
        }
        id = decal + 1; //lancer de start
        tmp = ft_find_start(p->head->next);
        while (p->nbr_fourmi >= id)
        {
            ret = ft_deplace(tmp, id, &state);
            if (ret != -1)
            {
              target->nbr_fourmi += ret;
              decal += 1;
            }
            id++;
        }
        if (target->nbr_fourmi < p->nbr_fourmi)
          state = 1;
        ft_putchar('\n');
    }
}
