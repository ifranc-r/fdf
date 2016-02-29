/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:58:19 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/20 19:29:31 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_all		all;
	// int		fd;
	char		***map;
	int			i;
//	int			j;

	if (argc > 1)
	{
		map = content_read_file(argv[1]);
		all.coord = init_tab_coord(map);
		init_mlx(&all);
		i = -1;
		ft_pixel_put(all);
		mlx_key_hook(all.win, mlx_funct_key, all.mlx);
		mlx_loop(all.mlx);
	}
	return (EXIT_SUCCESS);
}
