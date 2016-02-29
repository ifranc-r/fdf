/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:40:41 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/29 16:04:11 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_mlx(t_all *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, 1500, 1000, "FDF");
	all->img = mlx_new_image(all->mlx, 1500, 1000);
}

void	mlx_pixel_put_image(void *img, int x, int y, int color)
{
	t_pic	p;
	int		i;

	p.data = mlx_get_data_addr(img, &(p.bpp), &(p.sizeline), &(p.endian));
	i = x * 4 + y * p.sizeline;
	if (x >= 0 && y >= 0)
	{
		p.data[i] = color % 256;
		color /= 256;
		p.data[i + 1] = color % 256;
		color /= 256;
		p.data[i + 2] = color % 256;
		color /= 256;
		p.data[i + 3] = 0;
		color /= 256;
	}
}
