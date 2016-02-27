/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:46:36 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/27 15:46:44 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		mlx_funct_key(int keycode, void *mlx)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit((int)mlx);
	return (0);
}

/*int		mlx_hook_mov(int keycode, t_all *all)
{
	printf("a");
	if (keycode == 125)
	{
		all->img.img = mlx_get_data_addr(all->img.img, &all->img.bitpx, &all->img.size, &all->img.endian);

		mlx_clear_window(all->mlx, all->win);
		mlx_image(&all, &all->img, &all->coord);
		mlx_put_image_to_window(all->mlx, all->win, image, 0, 0);
	}
	return (0);
}

 void	mlx_image(t_all *all, t_img *img, t_coord *coord)
{
	int  size;

	size = ((coord->y * img->size) + (coord->x * 4);
	if ((coord->x >= 0) && (coord->y >= 0))
	{
		img->data[size] = set_color(&coord, &all);
		img->data[size + 1] = set_color(&coord, &all);
		img->data[size + 2] = set_color(&coord, &all);
	}
}


void	set_color(t_coord *coord, t_all *all)
{

	all->coord.z > 0 && all->coord.z < 50 ? color->red = 102 : 0;
	all->coord.z > 0 && all->coord.z < 50 ? color->green = 51 : 0;
	all->coord.z > 0 && all->coord.z < 50 ? color->blue = 0 : 0;
	all->coord.z <= 0 && all->coord.z > -50 ? color->red = 51 : 0;
	all->coord.z <= 0 && all->coord.z > -50 ? color->green = 51 : 0;
	all->coord.z <= 0 && all->coord.z > -50 ? color->blue = 255 : 0;
}*/
