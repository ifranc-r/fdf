/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 21:09:39 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/29 21:09:44 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void		set_color(t_color *color)
{
	color->red = 255;
	color->green = 255;
	color->blue = 255;
}
/*
void	mlx_image(void *img, int x, int y, int color)
{
	t_pic	p;
	int		i;

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
}*/
static void		mlx_image(t_all *all, int x, int y, t_img *img)
{
	int  size;


	if (x >= 0 && y >= 0)
	{
		set_color(&all->color)
		size = ((x * 4) + y * img->size);
		img->data[size] =  all->color.red;
		img->data[size + 1] =  all->color.green;
		img->data[size + 2] =  all->color.blue;
		img->data[size + 3] =  all->color.alpha;
	}
}