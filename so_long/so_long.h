/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/12 14:19:36 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_texture
{
	void *img_wall;
	void *img_floor;
	void *img_player;
	void *img_exit;
	void *img_coin;
	int w;
	int h;
} t_texture;

typedef struct s_so_long
{
	void *mlx;
	void *win;
	char **map;
	char **map_copy;
	int player_x;
	int player_y;
	int old_x;
	int old_y;
	int count_moves;
	char *map_line;
	int w;
	int s;
	int fd;
	int s_check;
	int	i;
	int	x;
	int	y;
	int	last;
	int	lastx;
	t_texture textures;
} t_so_long;

typedef struct  s_point
{
  int	x;
  int	y;
} 				t_point;

void	count_map_w(t_so_long *game);
void	count_map_s(t_so_long *game);
void	free_map(t_so_long *game);
void	free_map_copy(t_so_long *game);
void	map_duplicate(t_so_long *game);
int		load_map(t_so_long *game);
int		readmap( t_so_long *game);
void	init_textures(t_so_long *game);
void	draw_map(t_so_long *game);
void	start_game(t_so_long *game);
void	open_window(t_so_long *game);
int		exit_game(void *param);
int		exit_esc(int keycode, void *param);
int		can_move(t_so_long *game, int x, int y);
void	make_moves(int keycode, void *param, t_so_long *game);
void	update_palyer(t_so_long *game);
int		wrapper(int keycode, void *param);
void	move_left(t_so_long *game);
void	move_right(t_so_long *game);
void	move_up(t_so_long *game);
void	move_down(t_so_long *game);
void	setup_hooks(t_so_long *game);
int		map_checker(t_so_long *game);
int		coin_check(t_so_long *game);
int		check_top_bottom_wall(t_so_long *game);
int		wall_check(t_so_long *game);
int		find_palyer(t_so_long *game, t_point *begin);
int		check_top_bottom_wall(t_so_long *game);
int		wall_check(t_so_long *game);
void	clean_exit(t_so_long *game);
void	filler(t_so_long *game,t_point size,int y, int x);
void	flood_fill(t_so_long *game, t_point size, t_point begin);
t_point	map_len(t_so_long *game);
int		way_check(t_so_long *game, t_point *begin);
int		find_palyer(t_so_long *game,t_point *begin);
int		final_check(t_so_long *game,t_point *begin);
#endif
