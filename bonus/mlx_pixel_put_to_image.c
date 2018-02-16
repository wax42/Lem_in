/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_put_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:27:03 by vguerand          #+#    #+#             */
/*   Updated: 2018/01/30 15:28:21 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	mlx_pixel_put_to_image(t_mlx p, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WIN_X * WIN_Y * p.bpp / 8;
	if (x < 0 || y < 0 || y * p.size_line + x * p.bpp / 8 > \
		img_size
		|| x >= p.size_line / (p.bpp / 8) || y >= img_size / \
		p.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = p.bpp / 8;
	p.map[y * p.size_line + x * bit_pix] = color1;
	p.map[y * p.size_line + x * bit_pix + 1] = color2;
	p.map[y * p.size_line + x * bit_pix + 2] = color3;
}
