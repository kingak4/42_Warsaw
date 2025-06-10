/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/10 15:08:15 by kikwasni         ###   ########.fr       */
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
	int player_x;
	int player_y;
	int old_x;
	int old_y;
	int count_moves;
	t_texture textures;
} t_so_long;

typedef struct  s_point
{
  int           x;
  int           y;
} 				t_point;

int		exit_game(void *param);
void	setup_hooks(t_so_long *game);
int		exit_esc(int keycode, void *param);
char	**readmap(int *w, int *s, t_so_long *game);
int		map_checker(char **map);
int		wall_check(char **map);
void	open_window(t_so_long *game);
void	start_game(char **map, t_so_long *game);
void	draw_map(t_so_long *game,char **map);
void	init_textures(t_so_long *game);
int		find_palyer(char **map,t_so_long *game);
int		can_move(char **map,int x, int y);
void	make_moves(int keycode, void *param, char **map, t_so_long *game);
int		wrapper(int keycode, void *param);
void	move_left(t_so_long *game, char **map);
void	move_right(t_so_long *game, char **map);
void	move_up(t_so_long *game, char **map);
void	move_down(t_so_long *game, char **map);
void	update_palyer(t_so_long *game, char ** map);
int		coin_check(char **map);
int		final_check(char **map);

#endif
