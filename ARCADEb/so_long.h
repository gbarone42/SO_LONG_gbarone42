/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:48 by gbarone           #+#    #+#             */
/*   Updated: 2023/07/27 16:07:55 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "mlx_int.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_imgs
{
	void	*p;
	void	*fuel;
	void	*wall;
	void	*t;
	void	*uscita;
	void	*banner;
	void	*air;
	void	*e2;
	void	*e3;
	void	*e4;
	void	*e5;
	void	*e6;
	void	*e7;
	void	*e8;
	void	*e9;
	void	*e10;
	void	*e11;
	void	*e12;
	void	*e13;
	void	*ez;
	void	*g4;
	void	*g3;
	void	*g2;
	void	*g1;
	void	*end;
	void	*sb;
	void	*sb2;
	void	*sb3;
	void	*sb4;
	void	*sb5;
	void	*sb6;
	void	*sb7;
	void	*black;
}	t_imgs;

typedef struct s_game
{
	char		**map;
	int			map_lines;
	int			moves;
	void		*mlx;
	t_vector	*pos;
	t_vector	**guards;
	void		*w;
	int			col;
	t_imgs		*imgs;
	int			guards_number;
	int			map_height;
	int			map_width;
	int			moved;
	int			frame;
	int			dead;
	int			total_max_fr;
	int			f;
}	t_game;

int			main(int ac, char **av);
int			control_init(int ac, char **av, t_game *game);
int			verify_map(char *av);
int			line_counter(char *av);
int			verify_map_perimeter(char **map, int lines);
int			invalid_char_check(char **map);
int			very_map_character(char **map);
int			count_specific_char(char **map, char c);
int			map_explorer(char **map);
t_vector	char_finder(char **map, char c);
void		map_flooding(char **map, int x, int y);
//void		free_map(int fd, char **map);
void		free_map(char **map);
void		initialization(t_game *game);
char		**map_creation(char *av, t_game *game);
int			width_calculator(char *line);
t_vector	**guards_check(t_game *game);
void		g_initialization(t_game *game, t_vector *ghost);
void		init_each_guards(t_game *game);
void		img_anim(t_imgs *images, void *mlx, int ww, int wh);
void		gate_anim(t_imgs *images, void *mlx, int wdt);
void		initialize_player_position(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			v(t_game *game, int y, int x);
int			release_memory(t_game *game);
int			animate_game(t_game *game);
void		image_updater(char c, int x, int y, t_game *game);
void		door_updater(t_game *game, int x, int y, t_imgs *images);
void		door_updater_2(t_game *game, int x, int y, int u);
void		render(t_game *game);
void		g_manager(t_game *game);
void		g_render(t_game *game, t_vector *ghost);
void		player_render(t_game *game);
void		moves_counter(t_game *game);
char		*ft_itoa(int n);
size_t		ft_count(long int i);
char		*digit_to_char(char *s, size_t count, size_t i, int n);
int			ft_abs(int nb);
void		ft_death(t_game *game);
void		ft_close(t_game *game);
void		cleanup_map(char **map);
void		cleanup_img(t_imgs *i, void *m);
void		cleanup_img_2(t_imgs *i, void *m);
void		cleanup_guards(t_game *game);
void		g_mover(t_game *game, t_vector *ghost, int i);

#endif
