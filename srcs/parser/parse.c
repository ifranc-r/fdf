/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:37:23 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/18 14:41:34 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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

int		parse_map_alpha(char ***map)
{
	char	**line;
	char	*word;

	while (*map)
	{
		line = *map;
		while (*line)
		{
			word = *line;
			if (ft_isalpha(word[0]) == 1)
				return (1);
			++line;
		}
		++map;
	}
	return (0);
}
