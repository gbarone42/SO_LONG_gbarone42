/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:14:01 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/30 00:30:54 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_img_2(t_imgs *i, void *m)
{
	mlx_destroy_image(m, i->uscita);
	mlx_destroy_image(m, i->air);
	mlx_destroy_image(m, i->e2);
	mlx_destroy_image(m, i->e3);
	mlx_destroy_image(m, i->e4);
	mlx_destroy_image(m, i->e5);
	mlx_destroy_image(m, i->e6);
	mlx_destroy_image(m, i->e7);
	mlx_destroy_image(m, i->e8);
	mlx_destroy_image(m, i->e9);
	mlx_destroy_image(m, i->e10);
	mlx_destroy_image(m, i->e11);
	mlx_destroy_image(m, i->e12);
	mlx_destroy_image(m, i->e13);
	mlx_destroy_image(m, i->ez);
}

void	cleanup_img(t_imgs *i, void *m)
{
	mlx_destroy_image(m, i->black);
	mlx_destroy_image(m, i->fuel);
	mlx_destroy_image(m, i->banner);
	mlx_destroy_image(m, i->g1);
	mlx_destroy_image(m, i->g2);
	mlx_destroy_image(m, i->g3);
	mlx_destroy_image(m, i->g4);
	mlx_destroy_image(m, i->end);
	mlx_destroy_image(m, i->sb);
	mlx_destroy_image(m, i->p);
	mlx_destroy_image(m, i->sb2);
	mlx_destroy_image(m, i->sb3);
	mlx_destroy_image(m, i->sb4);
	mlx_destroy_image(m, i->sb5);
	mlx_destroy_image(m, i->sb6);
	mlx_destroy_image(m, i->sb7);
	mlx_destroy_image(m, i->t);
	mlx_destroy_image(m, i->wall);
	cleanup_img_2(i, m);
}

void	cleanup_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	cleanup_guards(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->guards_number)
	{
		free(game->guards[i]);
		i++;
	}
	free(game->guards);
}

int	release_memory(t_game *game)
{
	game->f = 1;
	free(game->pos);
	cleanup_guards(game);
	cleanup_map(game->map);
	cleanup_img(game->imgs, game->mlx);
	free(game->imgs);
	mlx_destroy_window(game->mlx, game->w);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}
