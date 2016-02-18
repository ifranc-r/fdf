/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:39:41 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/18 20:20:38 by aramanan         ###   ########.fr       */
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
# define BUFF_SIZE 1024

typedef struct	s_fdf
{
	int		mov_x;
	int		mov_y;

}				t_fdf;
// TODO: attention coco
typedef struct 	s_all
{
	void	*mlx;
	void	*win;
}				t_all;

typedef struct 	s_coord
{
	int		x;
	int		y;
	int		z;
}				t_coord;

void		error_dir(char *file);
void		error_file(char *file);
void		error_presence_alpha(char ****map, char *file);
int			get_next_line(int const fd, char **line);
char		***read_map(int const fd);
char		***map_read(char **content);
void		map_del(char ****map);
char		**content_file(char *file);
char		***content_read_file(char *file);
char		**parse_file(char *file);
int			parse_map_alpha(char ***map);
void		init_mlx(t_all *all);
void		affect_coord(int x, int y, int z, t_coord *coord);
t_coord	**init_tab_coord(char ***map);
t_coord	*init_line_coord(char **map);
t_coord	del_tab_coord(t_coord ***coord);

#endif
