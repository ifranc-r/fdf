/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:05:52 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/18 16:49:29 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	error_file(char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": No such file", 2);
	exit(EXIT_FAILURE);
}

void	error_dir(char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": It's a directory", 2);
	exit(EXIT_FAILURE);
}

void	error_presence_alpha(char ****map, char *file)
{
	map_del(map);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(": Alphabet character(s) detected", 2);
	exit(EXIT_FAILURE);
}
