/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:51:49 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 18:44:56 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_anim(t_imgs *im, void *mlx, int ww, int wh)
{
	int	width;

	width = 50;
	im->p = mlx_xpm_file_to_image(mlx, "./images/p.xpm", &width, &width);
	im->fuel = mlx_xpm_file_to_image(mlx, "./images/fuel.xpm", &width, &width);
	im->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &width, &width);
	im->t = mlx_xpm_file_to_image(mlx, "./images/tile.xpm", &width, &width);
	im->uscita = mlx_xpm_file_to_image(mlx, "./images/e.xpm", &width, &width);
	im->banner = mlx_xpm_file_to_image(mlx, "./images/win.xpm", &ww, &wh);
	im->air = mlx_xpm_file_to_image(mlx, "./images/plano.xpm", &width, &width);
	im->e2 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e3 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e4 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e5 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e6 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e7 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e8 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e9 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e10 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e11 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e12 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->e13 = mlx_xpm_file_to_image(mlx, "./images/letsgo.xpm", &width, &width);
	im->ez = mlx_xpm_file_to_image(mlx, "./images/plano.xpm", &width, &width);
	im->end = mlx_xpm_file_to_image(mlx, "./images/l.xpm", &ww, &wh);
	gate_anim(im, mlx, width);
}

void	gate_anim(t_imgs *images, void *mlx, int wdt)
{
	images->g1 = mlx_xpm_file_to_image(mlx, "./images/police.xpm", &wdt, &wdt);
	images->g2 = mlx_xpm_file_to_image(mlx, "./images/policeb.xpm", &wdt, &wdt);
	images->g3 = mlx_xpm_file_to_image(mlx, "./images/police.xpm", &wdt, &wdt);
	images->g4 = mlx_xpm_file_to_image(mlx, "./images/policeb.xpm", &wdt, &wdt);
	images->sb = mlx_xpm_file_to_image(mlx, "./images/sel.xpm", &wdt, &wdt);
	images->sb2 = mlx_xpm_file_to_image(mlx, "./images/sel2.xpm", &wdt, &wdt);
	images->sb3 = mlx_xpm_file_to_image(mlx, "./images/sel.xpm", &wdt, &wdt);
	images->sb4 = mlx_xpm_file_to_image(mlx, "./images/sel2.xpm", &wdt, &wdt);
	images->sb5 = mlx_xpm_file_to_image(mlx, "./images/sel.xpm", &wdt, &wdt);
	images->sb6 = mlx_xpm_file_to_image(mlx, "./images/sboo.xpm", &wdt, &wdt);
	images->sb7 = mlx_xpm_file_to_image(mlx, "./images/sel2.xpm", &wdt, &wdt);
	images->black = mlx_xpm_file_to_image(mlx, "./images/b.xpm", &wdt, &wdt);
}
