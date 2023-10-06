/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:50:16 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 19:21:32 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count(long int i)
{
	size_t	count;

	count = 0;
	if (i < 0)
	{
		i = i * -1;
		count++;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char	*digit_to_char(char *s, size_t count, size_t i, int n)
{
	while (count-- > i)
	{
		if (n < 0)
		{
			s[count] = '0' + (n % 10 * (-1));
			n = n / 10;
		}
		else
		{
			s[count] = '0' + n % 10;
			n = n / 10;
		}
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	size_t	count;

	count = ft_count(n);
	s = (char *)malloc((count + 1));
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		i = 1;
	}
	else
		i = 0;
	digit_to_char(s, count, i, n);
	return (s);
}

void	moves_counter(t_game *game)
{
	char	*move;

	move = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->w, 20, 15, 0xffffffff, "number of moves :");
	mlx_string_put(game->mlx, game->w, 140, 15, 0xffffffff, move);
	free(move);
}

int	animate_game(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	if (game->f)
		return (0);
	if (game->map[game->pos->y][game->pos->x] == 'C')
	{
		game->map[game->pos->y][game->pos->x] = '0';
		game->col--;
	}
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\0' && game->map[y][x] != '\n')
		{
			image_updater(game->map[y][x], x, y, game);
			x++;
		}
		y++;
	}
	render(game);
	return (0);
}
