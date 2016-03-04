/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:38:01 by aramanan          #+#    #+#             */
/*   Updated: 2016/03/04 16:51:09 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_coord		*init_coord(int x, int y, int z, int c, int v)
{
	t_coord		*coord;

	coord = NULL;
	if ((coord = (t_coord*)malloc(sizeof(t_coord))))
	{
		coord->x = x;
		coord->y = y;
		coord->z = z;
		coord->color = c;
		coord->value = v;
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
				lcoord[i] = init_coord((RATIO_X * i), (35 * i), 500 - \
					((25 * i) + (extract_value_coord(line[i]) * RATIO_SOMMET)),\
						extract_color_coord(line[i]), extract_value_coord(line[i]));
			else
				lcoord[i] = init_coord((lbcoord[0]->x + RATIO_X) + (RATIO_X * i), \
					((lbcoord[0]->y + 40) + (40 * i)), (lbcoord[0]->z + 30) \
						- ((25 * i) + (extract_value_coord(line[i]) * RATIO_SOMMET)), \
							extract_color_coord(line[i]), extract_value_coord(line[i]));
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
