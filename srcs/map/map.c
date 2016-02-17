/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:53:03 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/17 20:40:12 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static	int		nbline(char **content)
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

char			***map_read(char **content)
{
	char	***tab;
	char	**tmp;
	int		line;

	line = nbline(content);
	if ((tab = (char***)malloc(sizeof(char**) * (line + 1))))
	{
		tab[line] = NULL;
		while (*content)
		{
			*tab = ft_strsplit(*content, ' ');
			++content;
			++tab;
		}
		return (tab);
	}
	return (NULL);
}
