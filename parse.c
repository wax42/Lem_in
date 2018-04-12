/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 22:05:29 by mbarthe           #+#    #+#             */
/*   Updated: 2018/04/11 00:58:01 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lem_in.h"

t_lines    *ft_ant_nbr(t_param *p, t_lines *tmp)
{
    int i;

    while (tmp)
    {
        if (ft_check_htag(tmp->line) == 3)
            tmp = tmp->next;
        else
        {
            i = -1;
            while (tmp->line[++i])
            {
                if (ft_isdigit(tmp->line[i]) == 0)
                    ft_exit(0);
            }
            p->nbr_fourmi = ft_atoi(tmp->line);
            break ;
        }
    }
    if (!p->nbr_fourmi)
        ft_exit(0);
    tmp = tmp->next;
    while (ft_check_htag(tmp->line) == 3)
        tmp = tmp->next;
    return (tmp);
}
