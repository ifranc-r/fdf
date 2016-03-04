/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:13:03 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/03/04 16:15:09 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_e_x(t_line line)
{
	line.e = line.dx;
	line.dx = line.e * 2;
	line.dy = line.dy * 2;
}

void		ft_init_e_y(t_line line)
{
	line.e = line.dy;
	line.dy = line.e * 2;
	line.dx = line.dx * 2;
}

void		ft_init_line_x(int i, int j, t_all *all)
{
	all->line.x1 = all->coord[i][j]->x;
	all->line.y1 = all->coord[i][j]->z;
	all->line.x2 = all->coord[i][j + 1]->x;
	all->line.y2 = all->coord[i][j + 1]->z;
	if (all->coord[i][j]->value == 0 && all->coord[i][j + 1]->value == 0)
		all->line.color = PURPLE;
	if (all->coord[i][j]->value == 0 && all->coord[i][j + 1]->value > 0)
		all->line.color = YELLOW;
	if (all->coord[i][j]->value == 0 && all->coord[i][j + 1]->value < 0)
		all->line.color = GREEN;
	if (all->coord[i][j]->value > 0 && all->coord[i][j + 1]->value == 0)
		all->line.color = YELLOW;
	if (all->coord[i][j]->value < 0 && all->coord[i][j + 1]->value == 0)
		all->line.color = GREEN;

}
void		ft_init_line_y(int i, int j, t_all *all)
{
	all->line.x1 = all->coord[i][j]->x;
	all->line.y1 = all->coord[i][j]->z;
	all->line.color_p1 = all->coord[i][j]->color;
	all->line.x2 = all->coord[i + 1][j]->x;
	all->line.y2 = all->coord[i + 1][j]->z;
	all->line.color_p2 = all->coord[i + 1][j]->color;
}
