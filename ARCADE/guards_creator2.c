/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guards_creator2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:25:06 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/30 00:46:30 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*r;

	r = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		r[i] = '\0';
		i++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	y;

	y = size * count;
	if (count != 0 && size != y / count)
		return (NULL);
	p = (void *)malloc(y);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, y);
	return (p);
}

void	g_mover(t_game *game, t_vector *ghost, int i)
{
	static int	*proj;

	if (!proj)
		proj = ft_calloc(sizeof(int), game->guards_number);
	if (proj[i] != 1 && proj[i] != -1)
		proj[i] = -1;
	if (game->map[ghost->y + proj[i]][ghost->x] == '0')
	{
		if (proj[i] == -1)
			ghost->y--;
		else
			ghost->y++;
	}
	else if (game->map[ghost->y - proj[i]][ghost->x] == '0')
	{
		proj[i] = -proj[i];
		g_mover(game, ghost, i);
	}
	free (proj);
	proj = NULL;
	return ;
}

void	g_manager(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->guards_number)
	{
		if (game->frame == game->total_max_fr)
			g_mover(game, game->guards[i], i);
		i++;
	}
	i = 0;
	while (i < game->guards_number)
	{
		g_render(game, game->guards[i]);
		i++;
	}
}

void	g_render(t_game *game, t_vector *ghost)
{
	int	x;
	int	y;
	int	current_frame;

	current_frame = game->frame % game->total_max_fr;
	x = ghost->x * 50;
	y = ghost->y * 50;
	if (current_frame)
		mlx_put_image_to_window(game->mlx, game->w, game->imgs->g1, x, y);
}
