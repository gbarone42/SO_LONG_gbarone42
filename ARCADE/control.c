/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:00:30 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 19:21:28 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialization(t_game *game)
{
	game->map = NULL;
	game->map_lines = 0;
	game->moves = 0;
	game->mlx = NULL;
	game->pos = NULL;
	game->guards = NULL;
	game->w = NULL;
	game->col = 0;
	game->imgs = NULL;
	game->guards_number = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->moved = 1;
	game->frame = 1;
	game->dead = 0;
	game->total_max_fr = 160;
	game->f = 0;
}

int	control_init(int ac, char **av, t_game	*g)
{
	if (ac != 2)
		return (0);
	if (ac > 2)
		ft_printf("\033[0;31mToo many arguments.\n\033[0;37m");
	if (ac < 2)
		ft_printf("\033[0;31mThe Map file is missing.\n\033[0;37m");
	if (verify_map(av[1]) != 0)
	{
		ft_printf("\033[0;31m Waju' eddaje insert a valid map!\n\033[0;37m");
		return (0);
	}
	initialization(g);
	g->map = map_creation(av[1], g);
	g->mlx = mlx_init();
	g->imgs = malloc(sizeof(t_imgs));
	g->pos = malloc (sizeof(t_vector));
	g->pos->x = 0;
	g->pos->y = 0;
	g->guards = guards_check(g);
	init_each_guards(g);
	img_anim(g->imgs, g->mlx, g->map_width, g->map_height);
	g->w = mlx_new_window(g->mlx, g->map_width, g->map_height, "sl");
	initialize_player_position(g);
	return (1);
}
