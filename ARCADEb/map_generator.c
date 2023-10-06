/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:55:41 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 19:21:29 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	line_calculator(char *av, t_game *game)
{
	char	c;
	int		bytes_r;
	int		fd;
	size_t	line;

	bytes_r = 1;
	line = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	while (bytes_r)
	{
		bytes_r = read(fd, &c, 1);
		if (c == 'C')
			game->col++;
		if (c == '\n' && bytes_r)
			line++;
		if (c == 'G')
			game->guards_number++;
	}
	if (c != '\n')
		line++;
	close(fd);
	return (line);
}

int	width_calculator(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i * 50);
}

char	**map_creation(char *av, t_game *game)
{
	int		fd;
	int		lines;
	char	**map;
	int		i;

	i = 0;
	lines = line_calculator(av, game);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	game->map_lines = lines;
	game->map_height = lines * 50;
	game->map_width = width_calculator(map[0]);
	return (map);
}
/*
static int	aline_counter(char *file, t_game *game)
{
	char	c;
	int		c_read;
	int		fd;
	int		lines;

	c_read = 1;
	lines = 0;
	fd = open(file, O_RDWR);
	while (c_read)
	{
		c_read = read(fd, &c, 1);
		if (c == 'C')
			game->coins++;
		if (c == '\n' && c_read)
			lines++;
		if (c == 'G')
			game->g_n++;
	}
	if (c != '\n')
		lines++;
	close(fd);
	return (lines);
}*/
