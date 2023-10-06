/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:51:03 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/26 17:11:37 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_death(t_game *game)
{
	int	i;

	i = 0;
	game->dead = 0;
	while (i < game->guards_number)
	{
		if (game->pos->x == game->guards[i]->x)
			if (game->pos->y == game->guards[i]->y)
				game->dead = 1;
		i++;
	}
	if (game->dead)
		ft_close(game);
}

void	ft_close(t_game *game)
{
	mlx_clear_window(game->mlx, game->w);
	game->f = 1;
	if (!game->dead)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->banner, 0, 0);
	else
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->end, 0, 0);
}
