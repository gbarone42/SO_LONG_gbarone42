/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guards_creator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:13:30 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 16:05:23 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_each_guards(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->guards_number)
	{
		g_initialization(game, game->guards[i]);
		i++;
	}
}

void	g_initialization(t_game *game, t_vector *ghost)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'G')
			{
				game->map[y][x] = '0';
				ghost->x = x;
				ghost->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

t_vector	**guards_check(t_game *game)
{
	t_vector	**guards_pos;
	int			i;

	i = 0;
	guards_pos = malloc(sizeof(t_vector *) * game->guards_number);
	while (i < game->guards_number)
	{
		guards_pos[i] = malloc(sizeof(t_vector));
		guards_pos[i]->x = 0;
		guards_pos[i]->y = 0;
		i++;
	}
	return (guards_pos);
}
