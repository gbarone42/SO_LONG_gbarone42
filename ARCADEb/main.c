/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:35:39 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/28 23:01:32 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game_manager;

	if (control_init(ac, av, &game_manager) == 0)
		return (1);
	mlx_key_hook(game_manager.w, handle_keypress, &game_manager);
	mlx_loop_hook(game_manager.mlx, animate_game, &game_manager);
	mlx_hook(game_manager.w, 17, 0, release_memory, &game_manager);
	mlx_loop(game_manager.mlx);
}
/*hooking covers a range of techniques used to alter or augment t
he behaviour of an operating system, of applications, or of other 
software components by intercepting function calls or messages or 
events passed between software components.*/