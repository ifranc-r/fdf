/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:58:19 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/19 21:09:30 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_funct_key(int keycode, void *mlx)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit((int)mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_all		all;
	// int		fd;
	char		***map;
	int			i;
	int			j;

	if (argc > 1)
	{
		map = content_read_file(argv[1]);
		all.coord = init_tab_coord(map);
		init_mlx(&all);
		i = -1;
		while (all.coord[++i])
		{
			j = -1;
			// TODO: faire apparaitre les points dans la fenetre mlx
			while (all.coord[i][++j])
			{
				printf("valeur de x: %d\nvaleur de y: %d\nvaleur de z: %d\n\n ", all.coord[i][j]->x, all.coord[i][j]->y, all.coord[i][j]->z);
				mlx_pixel_put(all.mlx, all.win, all.coord[i][j]->x, all.coord[i][j]->z, 0xFFFFFF);
			}
		}
		// fd = open(argv[1], O_RDONLY);
		// map = read_map(fd);
		// init_mlx(&all);
		// // ft_pixel_put(all.mlx, all.win, map);
		mlx_key_hook(all.win, mlx_funct_key, all.mlx);
		mlx_loop(all.mlx);
	}
	return (EXIT_SUCCESS);
}
