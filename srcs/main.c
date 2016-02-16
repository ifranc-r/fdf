/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 11:58:19 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/16 20:58:31 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_funct_key(int keycode, void *mlx)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit ((int)mlx);
	return (0);
}

char 	***read_map(int const fd)
{
	int		i;
	char	***map;
	char	*line;

	map = (char ***)malloc(sizeof(char **) * 12);
	map[11] = NULL;	
	while (get_next_line(fd, &line) == 1)
	{
		map[i] = ft_strsplit(line, ' ');
		i++;
		free(line);
		line = NULL;
	}
	return (map);
} 

int 	ft_strraw_y(char ***tmp) // strlen de y
{
	int 		x;
	int 		y;

	x = 0;
	while (tmp[x])
	{
		y = 0;
		while (tmp[x][y])
		{
			printf("%s", tmp[x][y]);
			printf("   ");
			y++;
		}
		printf("\n");
		x++;
	}
	return (y);
}

int		ft_strraw_x(char ***tmp) // strlen de x
{
	int 		x;
	int 		y;
	t_fdf		color_x; // memorise les valeur differente de 0 

	x = 0;
	while (tmp[x])
	{
		y = 0;
		while (tmp[x][y])
		{
			y++;
		}
		x++;
	}
	return (x);
}

int		ft_pixel_put(void *mlx, void *win, char ***map) // ax + bx
{
	int		x;
	int		y;
	int		a;
	int		b;
	int		pixel_x;
	int		pixel_y;

	y = ft_strraw_x(map);
	pixel_y = 440;   // bx 
	pixel_x = 50;
	while (y--)
	{
		b = pixel_y;
		a = pixel_x;
		x = ft_strraw_y(map);
		while (x--)
		{
			mlx_pixel_put(mlx, win, pixel_x, pixel_y, 0x00FFFFFF);
			pixel_x = pixel_x + 50;
			pixel_y = pixel_y + 40;
		}
		pixel_x = a + 50;
		pixel_y = b - 40;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_all	all;
	int		fd;
	char	***map;
	char	**content;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		map = read_map(fd);
		all.mlx = mlx_init();
		all.win = mlx_new_window(all.mlx, 1000, 1000, "FDF");
		ft_pixel_put(all.mlx, all.win, map);
		mlx_key_hook(all.win, mlx_funct_key, all.mlx);
		mlx_loop(all.mlx);
	}
	return (EXIT_SUCCESS);
}
