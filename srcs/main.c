/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:58:19 by ifranc-r          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/02/23 12:41:56 by aramanan         ###   ########.fr       */
=======
/*   Updated: 2016/02/20 19:29:31 by ifranc-r         ###   ########.fr       */
>>>>>>> origin/try
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
	char		***map;
	int			i;
//	int			j;

	if (argc != 2)
	{
		map = content_read_file(argv[1]);
		all.coord = init_tab_coord(map);
		init_mlx(&all);
		i = -1;
		ft_pixel_put(all);
/*		while (all.coord[++i])
		{
			j = -1;
			while (all.coord[i][++j])
			{
				printf("valeur de x: %d\nvaleur de y: %d\nvaleur de z: %d\n\n ", all.coord[i][j]->x, all.coord[i][j]->y, all.coord[i][j]->z);
				mlx_pixel_put(all.mlx, all.win, all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i][j]->color);
			}
		}*/
		// fd = open(argv[1], O_RDONLY);
		// map = read_map(fd);
		// init_mlx(&all);
		// // ft_pixel_put(all.mlx, all.win, map);
		mlx_key_hook(all.win, mlx_funct_key, all.mlx);
		mlx_loop(all.mlx);
	}
	return (EXIT_SUCCESS);
}
