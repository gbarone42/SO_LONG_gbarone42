/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:50:16 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/28 23:11:19 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_updater(t_game *game, int x, int y, t_imgs*images)
{
	if (game->col > 0)
		mlx_put_image_to_window(game->mlx, game->w, images->uscita, x, y);
}

void	image_updater(char c, int x, int y, t_game *game)
{
	void	*p;

	p = game->mlx;
	x = x * 50;
	y = y * 50;
	if (!(x / 50 == game->pos->x && y / 50 == game->pos->y))
	{
		if (c == '0')
			mlx_put_image_to_window(p, game->w, game->imgs->t, x, y);
		if (c == '1')
			mlx_put_image_to_window(p, game->w, game->imgs->wall, x, y);
		if (c == 'C')
			mlx_put_image_to_window(p, game->w, game->imgs->fuel, x, y);
		if (c == 'E')
			door_updater(game, x, y, game->imgs);
	}
}
