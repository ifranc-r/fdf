/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:23:08 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/23 18:25:23 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_line2(int x1, int y1, int x2, int y2, t_all all)
{
	int dx;
	int dy;
	int	e;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dy) < 0)
							{
								y1 = y1 + 1;
								e = e + dx;
							}
							++x1;
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (++y1 != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dx) < 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while ((x1 = x1 + 1) != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dy) < 0)
							{
								y1 = y1 - 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while ((y1 = y1 - 1) != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dx) < 0)
							{
								x1 = x1 + 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while ((x1 = x1 + 1) != x2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
		}
		else
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while ((x1 = x1 - 1) != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dy) != 0)
							{
								y1 = y1 + 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while ((y1 = y1 + 1) != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e + dx) != 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while ((x1  = x1 - 1) != x2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dy) >= 0)
							{
								y1 = y1 - 1;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while ((y1  = y1 - 1) != y2)
						{
							mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
							if ((e = e - dx) >= 0)
							{
								x1 = x1 - 1;
								e = e + dy;
							}
						}
					}
				}
			}
			else // dy = 0 and dx < 0
			{
				while ((x1 = x1 - 1) != x2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
		}
	}
	else // dx = 0
	{
		if ((dy = y2 - y1) != 0)
		{
			if (dy > 0)
			{
				while ((y1 = y1 + 1) != y2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
			else // dy < 0 and dx = 0
			{
				while ((y1 = y1 - 1) != y2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
		}
	}
}

int		ft_pixel_put(t_all all) // ax + bx
{
	int		i;
	int		j;

	i = -1;
	while (all.coord[++i])
	{
		j = -1;
		while (all.coord[i][++j])
		{
			if (all.coord[i][j + 1])
			{
				ft_line2(all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i][j + 1]->x, all.coord[i][j + 1]->z, all);
				mlx_pixel_put(all.mlx, all.win, all.coord[i][j + 1]->x, all.coord[i][j + 1]->z, all.coord[i][j + 1]->color);
			}
			// a = i + 1;
			// b = j + 1;
			// if (all.coord[a])
			// if (all.coord[i][b])
			// 	ft_line2(all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i][b]->x, all.coord[i][b]->z, all);
			// mlx_pixel_put(all.mlx, all.win, all.coord[i][j]->x, all.coord[i][j]->z, 0x00FF00);
		}
	}

	i = 0;
	j = 0;
	while (all.coord[i][j])
	{
		while (all.coord[i] != NULL) // FIXME: segmentation fault lors du parcours chaine
		{
			printf("Boucle - i vaut : %d j vaut : %d\n", i, j);
			if (all.coord[i + 1] != NULL)
			{
				printf("Condition - i vaut : %d j vaut : %d\n", i, j);
				ft_line2(all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i + 1][j]->x, all.coord[i + 1][j]->z, all);
			}
			i++;
			if (all.coord[i] == NULL)
				ft_putendl("STOP");
		}
		i = 0;
		j++;
	}
	return (1);
}
