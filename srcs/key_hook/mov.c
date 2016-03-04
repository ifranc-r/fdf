/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:46:36 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/03/02 19:02:50 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		mlx_funct_key(int keycode, void *all)
{
	// (t_all*)all;
	printf("key event %d\n", keycode);
	if (keycode == 53) // Bouton echap
		exit(1);
	if (keycode == 126 || keycode == 123 || keycode == 124 || keycode == 125)
		mov_picture((t_all*)all, keycode);
	return (0);
}

static	void	mov_up(t_all *all)
{
	all->p_img_y += -5;
}

static	void	mov_down(t_all *all)
{
	all->p_img_y += 5;
}

static	void	mov_left(t_all *all)
{
	all->p_img_x += -5;
}

static	void	mov_right(t_all *all)
{
	all->p_img_x += 5;
}

void	mov_picture(t_all *all, int keycode)
{
	if (keycode == 126)
		mov_up(all);
	if (keycode == 123)
		mov_left(all);
	if (keycode == 125)
		mov_down(all);
	if (keycode == 124)
		mov_right(all);
	mlx_clear_window(all->mlx, all->win);
	test_img(*all);
	mlx_put_image_to_window(all->mlx, all->win, all->img, all->p_img_x, all->p_img_y);
}
