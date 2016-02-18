/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:53:03 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/18 15:32:26 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

/* Compte le nombre de ligne dans **content */
static	int	nbline(char **content)
{
	int		i;

	i = 0;
	while (*content)
	{
		++i;
		++content;
	}
	return (i);
}

char				***map_read(char **content)
{
	char	***tab;
	char	***tmp;
	int		line;

	line = nbline(content);
	if ((tab = (char***)malloc(sizeof(char**) * (line + 1))))
	{
		tab[line] = NULL;
		tmp = tab;
		while (*content)
		{
			*tmp = ft_strsplit(*content, ' ');
			++content;
			++tmp;
		}
		return (tab);
	}
	return (NULL);
}

void				map_del(char ****map)
{
	char	***tmp;
	char	**line;

	tmp = *map;
	while (*tmp)
	{
		line = *tmp;
		while (*line)
		{
			free(*line);
			line++;
		}
		free(*tmp);
		tmp++;
	}
	*map = NULL;
}
