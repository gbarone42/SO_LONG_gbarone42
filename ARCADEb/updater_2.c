/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:50:16 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/29 23:02:57 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	door_updater_2(t_game *game, int x, int y, int u)
{
	if (game->frame > u * 4 && game->frame <= u * 5)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e5, x, y);
	if (game->frame > u * 5 && game->frame <= u * 6)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e6, x, y);
	if (game->frame > u * 6 && game->frame <= u * 7)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e7, x, y);
	if (game->frame > u * 7 && game->frame <= u * 8)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e8, x, y);
	if (game->frame > u * 8 && game->frame <= u * 9)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e9, x, y);
	if (game->frame > u * 9 && game->frame <= u * 10)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e10, x, y);
	if (game->frame > u * 10 && game->frame <= u * 11)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e11, x, y);
	if (game->frame > u * 11 && game->frame <= u * 12)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e12, x, y);
	if (game->frame > u * 12 && game->frame <= u * 13)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->e13, x, y);
	if (game->frame > u * 13)
	{
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->ez, x, y);
		game->col = -1;
	}
}

void	door_updater(t_game *game, int x, int y, t_imgs*images)
{
	static int	start;
	int			u;

	u = game->total_max_fr / 14;
	if (game->col > 0)
		mlx_put_image_to_window(game->mlx, game->w, images->uscita, x, y);
	if (game->col == 0 && game->frame == 1)
		start = 1;
	if (game->col == 0 && start == 1)
	{
		if (game->frame <= u)
			mlx_put_image_to_window(game->mlx, game->w, images->air, x, y);
		if (game->frame > u && game->frame <= u * 2)
			mlx_put_image_to_window(game->mlx, game->w, images->e2, x, y);
		if (game->frame > u * 2 && game->frame <= u * 3)
			mlx_put_image_to_window(game->mlx, game->w, images->e3, x, y);
		if (game->frame > u * 3 && game->frame <= u * 4)
			mlx_put_image_to_window(game->mlx, game->w, images->e4, x, y);
		if (game->frame > u * 4)
			door_updater_2(game, x, y, u);
	}
	if (game->col == -1)
		mlx_put_image_to_window(game->mlx, game->w, images->ez, x, y);
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
