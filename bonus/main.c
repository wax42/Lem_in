/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:57:25 by vguerand          #+#    #+#             */
/*   Updated: 2018/02/21 03:42:49 by mbarthe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include "stdio.h"

int		rgb_to_hexa(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static int		my_key_funct(int keycode, t_mlx *p)
{
	if (keycode == 53)
		ft_exit(-1);
	if (keycode == 126)
	{
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	}
	p->mlx = 0;
	return (0);
}

int		ft_openfile(char *files)
{
	int	fd;

	fd = open(files, O_RDONLY);
	if (fd == -1)
		ft_exit(0);
	return (fd);
}

int main(int argc, char **argv)
{
	t_mlx p;

	if (argc == 2)
		p.fd = ft_openfile(argv[1]);
	else if (argc == 1)
		p.fd = 0;
	else
		ft_exit(0);
	p.mlx = mlx_init();
	p.img = mlx_new_image(p.mlx, WIN_X, WIN_Y);
	p.map = mlx_get_data_addr(p.img, &p.bpp, &p.size_line, &p.endian);
	//ft_read(&p);
	p.win = mlx_new_window(p.mlx, WIN_X, WIN_Y, "Lem_in");
	mlx_put_image_to_window(p.mlx, p.win, p.img, 0, 0);
	mlx_hook(p.win, 2, (1L << 0), my_key_funct, &p);
	mlx_loop(p.mlx);
	return (0);
}
