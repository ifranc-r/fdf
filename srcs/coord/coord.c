/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:38:01 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/22 21:10:59 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_coord		*init_coord(int x, int y, int z, int c)
{
	t_coord		*coord;

	coord = NULL;
	if ((coord = (t_coord*)malloc(sizeof(t_coord))))
	{
		coord->x = x;
		coord->y = y;
		coord->z = z;
		coord->color = c;
	}
	return (coord);
}

static	int	nbcase(char **line)
{
	int		ncase;

	ncase = 0;
	while (*line)
	{
		++ncase;
		++line;
	}
	return (ncase);
}

t_coord		**init_line_coord(char **line, t_coord **lbcoord)
{
	int		ncase;
	t_coord	**lcoord;
	int		i;

	ncase = nbcase(line);
	lcoord = NULL;
	if ((lcoord = (t_coord**)malloc(sizeof(t_coord*) * (ncase + 1))))
	{
		i = -1;
		while (++i < ncase)
		{
			if (lbcoord == NULL)
				lcoord[i] = init_coord(50 + (50 * i), 40 + (40 * i), 440 - \
					((25 * i) + (extract_value_coord(line[i]) * 10)),\
						extract_color_coord(line[i]));
			else
				lcoord[i] = init_coord((lbcoord[0]->x + 50) + (50 * i), \
					(lbcoord[0]->y + 40) + (40 * i), (lbcoord[0]->z + 40) \
						- ((25 * i) + (extract_value_coord(line[i]) * 10)), \
							extract_color_coord(line[i]));
		}
		lcoord[ncase] = NULL;
	}
	return (lcoord);
}

void		del_tab_coord(t_coord ***coord)
{
	while (*coord)
	{
		free(*coord);
		++coord;
	}
}
