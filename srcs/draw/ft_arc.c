/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:08:35 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/29 18:53:18 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_first_arc(t_all *all)
{
	if (all->line.dy != 0)
	{
		if (all->line.dy > 0)
			ft_first_quadrant(all);
		else
			ft_fourth_quadrant(all);
	}
	else
		while ((all->line.x1 = all->line.x1 + 1) != all->line.x2)
			mlx_pixel_put(all->mlx, all->win, all->line.x1, all->line.y1, 0xFFFFFFF);
}

void		ft_second_arc(t_all *all)
{
	if ((all->line.dy = all->line.y2 - all->line.y1) != 0)
	{
		if (all->line.dy > 0)
			ft_second_quadrant(all);
		else
			ft_thirth_quadrant(all);
	}
	else // dy = 0 and all->line.dx < 0
	{
		while ((all->line.x1 = all->line.x1 - 1) != all->line.x2)
			mlx_pixel_put(all->mlx, all->win, all->line.x1, all->line.y1, 0xFFFFFFF);
	}
}

void		ft_others_cond(t_all *all)
{
	if ((all->line.dy = all->line.y2 - all->line.y1) != 0)
	{
		if (all->line.dy > 0)
		{
			while ((all->line.y1 = all->line.y1 + 1) != all->line.y2)
				mlx_pixel_put(all->mlx, all->win, all->line.x1, all->line.y1, 0xFFFFFFF);
		}
		else // all->line.dy < 0 and all->line.dx = 0
		{
			while ((all->line.y1 = all->line.y1 - 1) != all->line.y2)
				mlx_pixel_put(all->mlx, all->win, all->line.x1, all->line.y1, 0xFFFFFFF);
			}
		}
	}
