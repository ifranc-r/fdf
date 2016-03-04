/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:40:09 by aramanan          #+#    #+#             */
/*   Updated: 2016/03/04 18:07:53 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

char	**content_file(char *file)
{
	int		fd;
	char	**tab;
	char	**tmp;

	tab = NULL;
	if ((fd = open(file, O_RDONLY)) > 2)
	{
		tab = (char**)malloc(sizeof(char*) * (999999999999 + 1));
		tab[80000] = NULL;
		tmp = tab;
		while ((get_next_line(fd, &(*tmp++))) > 0)
			;
		*tmp = NULL;
		close(fd);
	}
	return (tab);
}

char	***content_read_file(char *file)
{
	char	**content;
	char	***map;

	if ((content = parse_file(file)) == NULL)
		exit(EXIT_FAILURE);
	if ((map = map_read(content)))
	{
		if ((parse_map_alpha(map)) == 1)
			error_presence_alpha(&map, file);
		else
			return (map);
	}
	return (NULL);
}
