/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 20:40:41 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/16 20:42:07 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	init_mlx(t_all *all)
{
	//all->img.img = mlx_new_image(all->mlx, 1000, 1000);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIN_X, WIN_Y, "FDF");
}
