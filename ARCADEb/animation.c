/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:46:05 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/29 23:02:13 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_updater(t_game *game)
{
	game->total_max_fr = 105000 / ((game->map_height * game->map_width) / 800);
	game->frame++;
	if (game->frame > game->total_max_fr)
		game->frame = 1;
}

void	player_render(t_game *game)
{
	int		x;
	int		y;
	int		u;
	int		current_frame;

	x = game->pos->x * 50;
	y = game->pos->y * 50;
	u = game->total_max_fr / 7;
	current_frame = game->frame % game->total_max_fr;
	if (current_frame <= u)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->sb, x, y);
	else if (current_frame <= u * 2)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->sb2, x, y);
	else if (current_frame <= u * 3)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->sb3, x, y);
	else if (current_frame <= u * 4)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->sb4, x, y);
	else if (current_frame <= u * 5)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->sb5, x, y);
	else if (current_frame <= u * 6)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->sb6, x, y);
	else
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->sb7, x, y);
}

void	render(t_game *game)
{
	g_manager(game);
	player_render(game);
	moves_counter(game);
	if (game->col <= 0 && game->map[game->pos->y][game->pos->x] == 'E')
		ft_close(game);
	frame_updater(game);
	ft_death(game);
}
