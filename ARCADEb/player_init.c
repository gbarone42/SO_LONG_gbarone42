/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:20:13 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 18:41:19 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_player_position(t_game *game)
{
	int		y;
	int		x;

	x = 0;
	y = 0;
	while (game->map[y][x] != '\0')
	{
		if (game->map[y][x] == 'P')
		{
			game->map[y][x] = '0';
			game->pos->x = x;
			game->pos->y = y;
			return ;
		}
		if (game->map[y][x + 1] == '\0')
		{
			y++;
			x = 0;
		}
		else
		{
			x++;
		}
	}
}

	/*
void	player_init(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				game->player_pos->x_rightleft = x;
				game->player_pos->y_updown = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}
*/