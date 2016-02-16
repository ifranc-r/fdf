/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 15:05:52 by aramanan          #+#    #+#             */
/*   Updated: 2016/02/16 16:56:22 by aramanan         ###   ########.fr       */
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