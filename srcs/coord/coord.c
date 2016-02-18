/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:38:01 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/18 18:52:51 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_coord		**init_tab_coord(char ***map)
{
	int		nbline;
	t_coord	**coord;

	nbline = 0;
	while (*map)
	{
		++nbline;
		++map;
	}
	coord = NULL;
	if ((coord = (t_coord**)malloc(sizeof(t_coord*) * (nbline + 1))))
		coord[line] = NULL;
	return (coord);
}

t_coord		*init_line_coord(char **line)
{
	int		nbcase;
	t_coord	*lcoord;

	nbcase = 0;
	while (*line)
	{
		++nbcase;
		++line;
	}
	lcoord = NULL;
	if ((lcoord = (t_coord*)malloc(sizeof(t_coord) * (nbcase + 1))))
		lcoord[nbcase] = NULL;
	return (lcoord);
}

void		affect_coord(int x, int y, int z, t_coord *coord)
{
	coord->x = x;
	coord->y = y;
	coord->z = z;
}

void		del_tab_coord(t_coord ***coord)
{
	while (*coord)
	{
		free(*coord);
		++coord;
	}
}
