/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:22:09 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/22 17:16:44 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	int	nbline(char ***map)
{
	int		nline;

	nline = 0;
	while (*map)
	{
		++nline;
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
	if ((coord = (t_coord***)malloc(sizeof(t_coord**) * (nline + 1))))
	{
		i = -1;
		while (++i < nline)
		{
			if (i == 0)
				coord[i] = init_line_coord(*map++, NULL);
			else
				coord[i] = init_line_coord(*map++, coord[i - 1]);
		}
		coord[nline] = NULL;
	}
	return (coord);
}

int			extract_color_coord(char *cas)
{
	int		value;

	value = ft_atoi(cas);
	if (value == 0)
		return (PURPLE);
	if (value > 0)
		return (YELLOW);
	return (GREEN);
}
