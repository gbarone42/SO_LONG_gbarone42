/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:59:23 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 19:21:31 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_counter(char *av)
{
	char	c;
	int		bytes_r;
	int		fd;
	int		line;

	bytes_r = 1;
	line = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (-1);
	}
	while (bytes_r)
	{
		bytes_r = read(fd, &c, 1);
		if (c == '\n' && bytes_r)
			line++;
	}
	if (c != '\n')
		line++;
	close(fd);
	return (line);
}

static int	ft_correct_form(char **map)
{
	int		i;
	size_t	len;

	len = strlen(map[0]);
	i = 1;
	while (map && map[i])
	{
		if (strlen(map[i]) != len)
			return (1);
		i++;
	}
	return (0);
}

int	verify_map_perimeter(char **map, int lines)
{
	int		i;
	int		j;

	i = 0;
	while (map[0][i] == '1')
		i++;
	if (map[0][i] != '\n')
		return (1);
	j = i - 1;
	i = 0;
	while (map[lines - 1][i] == '1')
		i++;
	if (map[lines - 1][i] != '\0' && map[lines - 1][i] != '\n')
		return (1);
	i = 0;
	while (i < lines && (map[i][0] == '1' && map[i][j] == '1'))
		i++;
	if (i < lines)
		return (1);
	i = invalid_char_check(map);
	if (i != 1)
		i = ft_correct_form(map);
	return (i);
}

int	verify_map(char *av)
{
	int		fd;
	int		lines;
	char	**map;
	int		check;
	t_game	game;

	check = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[0;31mThe Map cannot be opened. \n\033[0;37m");
		return (1);
	}
	if (read(fd, 0, 0) == -1 || fd < 0)
		return (1);
	lines = line_counter(av);
	map = map_creation(av, &game);
	check += verify_map_perimeter(map, lines);
	check += very_map_character(map);
	if (check == 0)
		check += map_explorer(map);
	close(fd);
	free_map(map);
	return (check);
}
