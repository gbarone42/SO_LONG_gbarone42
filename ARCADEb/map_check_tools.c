/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:59:23 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 15:34:48 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_explorer(char **map)
{
	t_vector	exit;
	t_vector	plr;

	plr = char_finder(map, 'P');
	exit = char_finder(map, 'E');
	if (plr.x == -1 || plr.y == -1 || exit.x == -1 || exit.y == -1)
		return (1);
	map_flooding(map, exit.x, exit.y);
	if (map[plr.y][plr.x] != '1')
		return (1);
	if (count_specific_char(map, 'C') != 0)
		return (1);
	return (0);
}

void	map_flooding(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	map[y][x] = '1';
	map_flooding(map, x + 1, y);
	map_flooding(map, x - 1, y);
	map_flooding(map, x, y + 1);
	map_flooding(map, x, y - 1);
}

void	free_map(char **map)
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
