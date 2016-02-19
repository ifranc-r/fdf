/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:22:09 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/19 13:55:42 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// TODO: creer fonction qui rempli ligne par ligne tab_coord

void		fill_line_tab_coord(char **map, t_coord **coord)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (map[i][j])
	{
		coord[i][j].x = 440;
		coord[i][j].z = 50;
		coord[i][j].y = coord[0][0].z + coord[0][0].x;
	}
	j++;
	while (*map)
	{
		coord[i][j].x = 50 + coord[i][j - 1].x;
		coord[i][j].z = 40 + coord[i][j - 1].z;
		coord[i][j].y = 50 + coord[i][j - 1].y;
		++j;
		++map;
	}
}

void		fill_tab_coord(char ***map, t_coord ****coord)
{
	fill_line_tab_coord(*map, **coord);
}
