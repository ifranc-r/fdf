/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:58:19 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/03/04 16:33:43 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int		mlx_funct_key(int keycode, void *mlx)
// {
// 	printf("key event %d\n", keycode);
// 	if (keycode == 53)
// 		exit((int)mlx);
// 	return (0);
// }
void	test_img(t_all all) /* Test dessin dans une image */
{
	int		i;
	int		j;

	i = -1;
	while (all.coord[++i])
	{
		j = -1;
		while (all.coord[i][++j])
			mlx_pixel_put_image(all.img, all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i][j]->color);
	}
}

int		main(int argc, char **argv)
{
	t_all		all;
	char		***map;

	if (argc > 1)
	{
		map = content_read_file(argv[1]);
		all.coord = init_tab_coord(map);
		init_mlx(&all);
		// test
		// test_img(all);
		// fin test
		ft_pixel_put(all);
		mlx_put_image_to_window(all.mlx, all.win, all.img, all.p_img_x, all.p_img_y);
		mlx_key_hook(all.win, mlx_funct_key, (void*)&all);
		mlx_loop(all.mlx);
	}
	return (EXIT_SUCCESS);
}
