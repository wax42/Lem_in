/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarthe <mbarthe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:50:41 by mbarthe           #+#    #+#             */
/*   Updated: 2018/04/10 19:56:18 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_line(char **str, char **line)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	k = 0;
	while (str[0][i])
	{
		if (str[0][i] == '\n')
		{
			k = 1;
			*line = ft_strsub(*str, 0, i);
			tmp = *str;
			*str = ft_strsub(*str, i + 1, ft_strlen(*str));
			ft_strdel(&tmp);
			return (1);
		}
		i++;
	}
	*line = ft_strsub(*str, 0, i);
	ft_strdel(str);
	if (line[0][0] != '\0')
		return (1);
	return (0);
}

int		get_first_line(const int fd, char **line)
{
	static char	*str;
	char		buf[2];
	char		*temp;
	int			ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (str == NULL)
		str = ft_memalloc(1);
	while ((ret = read(fd, buf, 1)) > 0)
	{
		if (buf[0] == '\0')
			return (-1);
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&temp);
		if (ft_strchr(str, '\n'))
			return (ft_get_line(&str, line));
	}
	if (ft_get_line(&str, line))
		return (1);
	if (ret == -1)
		return (-1);
	return (0);
}
