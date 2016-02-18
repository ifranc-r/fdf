/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:40:09 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/18 14:56:50 by aramanan         ###   ########.fr       */
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
		tab = (char**)malloc(sizeof(char*) * (80000 + 1));
		tab[80000] = NULL;
		tmp = tab;
		while ((get_next_line(fd, &(*tmp++))) > 0)
			;
		*tmp = NULL;
		close(fd);
	}
	return (tab);
}
