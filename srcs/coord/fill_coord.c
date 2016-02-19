/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:22:09 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/19 18:23:12 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static		nbline(char ***map)
{
	int		nline;

	nline = 0;
	while (*map)
	{
		++nbline;
		++map;
	}
	return (nline);
}

t_coord		***init_tab_coord(char ***map)
{
	t_coord	***coord;
	int		nline;
	int		i;

	nline = nbline(map);
	coord = NULL;
	if ((coord = (t_coord***)malloc(sizeof(t_coord**) * (nbline + 1))))
	{
		i = -1;
		while (++i < nline)
		{
			if (i == 0)
				coord[i] = init_line_coord(*map++, NULL);
			else
				coord[i] = init_line_coord(*map++, coord[i - 1]);
		}
		coord[nbline] = NULL;
	}
	return (coord);
}
