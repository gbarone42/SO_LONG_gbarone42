/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:44:30 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 15:38:47 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_specific_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	invalid_char_check(char **map)
{
	int		current_char;
	int		current_line;
	char	c;

	current_line = 0;
	while (map[current_line])
	{
		current_char = 0;
		while (map[current_line][current_char])
		{
			c = map[current_line][current_char];
			if (c != '1' && c != '0' && c != 'C' && c != 'P' && c != 'E'
				&& c != 'G' && c != '\n')
				return (1);
			current_char++;
		}
		current_line++;
	}
	return (0);
}

int	very_map_character(char **map)
{
	int		count_p;
	int		count_e;
	int		count_c;

	count_p = count_specific_char(map, 'P');
	count_e = count_specific_char(map, 'E');
	count_c = count_specific_char(map, 'C');
	if (count_p != 1 || count_e != 1 || count_c == 0)
	{
		return (1);
	}
	return (0);
}

t_vector	char_finder(char **map, char c)
{
	int			i;
	int			j;
	t_vector	position;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
			{
				position.x = i;
				position.y = j;
			}
			i++;
		}
		j++;
	}
	return (position);
}
