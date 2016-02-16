/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:37:23 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/16 16:56:42 by aramanan         ###   ########.fr       */
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
		tmp = tab;
		while ((get_next_line(fd, &(*tmp++))) > 0)
			;
		*tmp = NULL;
		close(fd);
	}
	return (tab);
}

/**
 * check l'argument passe en parametre
 * @param  file [argument]
 * @return      [retourne contenu ou NULL si rien]
 */
char	**parse_file(char *file)
{
	char	**content;

	if ((content = content_file(file)))
	{
		if (errno == EISDIR)
			error_dir(file);
		else
			return (content);
	}
	else
		error_file(file);
	return (NULL);
}