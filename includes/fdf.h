/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:39:41 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/20 19:34:27 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"
# include <math.h>
# define BUFF_SIZE 1024
# define PURPLE 0xCC00CC
# define YELLOW 0xD1C518
# define GREEN 0x66CC00

typedef struct	s_fdf
{
	int		mov_x;
	int		mov_y;
}				t_fdf;

typedef struct s_line
{
	int y2;
	int y1;
	int x2;
	int x1;
	int dx;
	int dy;
	int e;
}				t_line;

typedef struct 	s_all
{
	void			*mlx;
	void			*win;
	struct s_coord	***coord;
	struct s_line	line;
}				t_all;

typedef struct 	s_coord
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		value;
}				t_coord;

void		ft_init_line_y(int i, int j, int a, t_all *all);
void		ft_init_line_x(int i, int j, int b, t_all *all);

void		ft_line(t_all *all);

void		ft_first_arc(t_all *all);
void		ft_second_arc(t_all *all);
void		ft_others_cond(t_all *all);

void		ft_thirth_quadrant(t_all *all);
void		ft_fourth_quadrant(t_all *all);
void		ft_second_quadrant(t_all *all);
void		ft_first_quadrant(t_all *all);


void		ft_sixth_octant(int x1, int y1, int y2, t_all *all);
void		ft_thirth_octant(int x1, int y1, int y2, t_all *all);
void		ft_seventh_octant(int x1, int y1, int y2, t_all *all);
void		ft_second_octant(int x1, int y1, int y2, t_all *all);
void		ft_first_octant(int x1, int y1, int x2, t_all *all);

void		ft_init_e_x(t_line line);
void		ft_init_e_y(t_line line);

void		error_dir(char *file);
void		error_file(char *file);
void		error_presence_alpha(char ****map, char *file);
char		***map_read(char **content);
void		map_del(char ****map);
char		**content_file(char *file);
char		***content_read_file(char *file);
char		**parse_file(char *file);
int			parse_map_alpha(char ***map);
void		init_mlx(t_all *all);
void		affect_coord(int x, int y, int z, t_coord **coord);
int			extract_color_coord(char *c);
int			extract_value_coord(char *c);
t_coord		*init_coord(int x, int y, int z, int color);
t_coord		***init_tab_coord(char ***map);
t_coord		**init_line_coord(char **map, t_coord **lbcoord);
void		del_tab_coord(t_coord ***coord);
void		fill_tab_coord(char ***map, t_coord ****coord);
void		fill_line_tab_coord(char **map, t_coord **coord);
int			ft_pixel_put(t_all all);

#endif