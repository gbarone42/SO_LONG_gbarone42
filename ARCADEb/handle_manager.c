/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:48:59 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 16:06:53 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	v(t_game *game, int y, int x)
{
	if (game->col <= 0)
		return (1);
	if (game->map[game->pos->y + y][game->pos->x + x] != 'E')
		return (1);
	return (1);
}

int	handle_keypress(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->pos->x;
	y = game->pos->y;
	if (key == 100)
		if (game->map[game->pos->y][game->pos->x + 1] != '1' && v(game, 0, 1))
			game->pos->x += 1;
	if (key == 119)
		if (game->map[game->pos->y - 1][game->pos->x] != '1' && v(game, -1, 0))
			game->pos->y -= 1;
	if (key == 97)
		if (game->map[game->pos->y][game->pos->x - 1] != '1' && v(game, 0, -1))
			game->pos->x -= 1;
	if (key == 115)
		if (game->map[game->pos->y + 1][game->pos->x] != '1' && v(game, 1, 0))
			game->pos->y += 1;
	if (x != game->pos->x || y != game->pos->y)
	{
		game->moves++;
		game->moved = 1;
	}
	if (key == 65307)
		release_memory(game);
	return (0);
}
/*int	handle_keypress(int key, t_game *game)
{
	int new_x;
	int new_y;

	new_x = game->pos->x;
	new_y = game->pos->y;
	if (key == 100 && game->map[new_y][new_x + 1] != '1' && v(game, 0, 1))
		new_x++;
	if (key == 119 && game->map[new_y - 1][new_x] != '1' && v(game, -1, 0))
		new_y--;
	if (key == 97 && game->map[new_y][new_x - 1] != '1' && v(game, 0, -1))
		new_x--;
	if (key == 115 && game->map[new_y + 1][new_x] != '1' && v(game, 1, 0))
		new_y++;

	if (new_x != game->pos->x || new_y != game->pos->y)
	{
		game->pos->x = new_x;
		game->pos->y = new_y;
		game->moves++;
		game->moved = 1;
	}

	if (key == 65307)
		release_memory(game);

	return (0);
}*/