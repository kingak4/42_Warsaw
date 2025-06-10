/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:26:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/10 13:25:23 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int can_move(char **map,int x, int y)
{
	if (map[y] == NULL || map[y][x] == '\0')
		return 0;
	if(map[y][x] == '1')
		return(0);
	if (coin_check(map) > 0)
	{
		if(map[y][x] == 'E')
			return(0);
	}
	if(coin_check(map) == 0)
	{
		if(map[y][x] == 'E')
		{
			ft_printf("Congratulations! 🎉✨");
			exit_game(NULL);
		}
	}
	return(1);
}

void	make_moves(int keycode, void *param, char **map, t_so_long *game)
{
	(void)param;
	int flag;
	game->old_x = game->player_x;
	game->old_y = game->player_y;
	flag = 0;
	if(keycode == 65361 || keycode == 97)
	{
		move_left(game, map);
		update_palyer(game, map);
		flag++;
	}
	else if (keycode == 65363 || keycode == 100)
	{
		move_right(game, map);
		update_palyer(game, map);
		flag++;
	}
	else if (keycode == 65362 || keycode == 119)
	{
		move_up(game, map);
		update_palyer(game, map);
		flag++;
	}
	else if (keycode == 65364 || keycode == 115)
	{
		move_down(game, map);
		update_palyer(game, map);
		flag++;
	}
	if(flag > 0)
	{
		start_game(map, game);
	}

}

void	update_palyer(t_so_long *game, char ** map)
{
	map[game->old_y][game->old_x] = '0';
	map[game->player_y][game->player_x] = 'P';
}

int wrapper(int keycode, void *param)
{
	t_so_long *game = (t_so_long *)param;
	
	char **map = game->map;
	make_moves(keycode,NULL,map, game);
	return(0);
}
void move_left(t_so_long *game, char **map)
{
	int x ;
	int y;
	x = game->player_x - 1;
	y = game->player_y;
	
	if (can_move(map, x, y))
	{
		game->player_x = x;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}
void move_right(t_so_long *game, char **map)
{
	int x ;
	int y;
	x = game->player_x + 1;
	y = game->player_y;
	
	if (can_move(map, x, y))
	{
		game->player_x = x;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}

void move_up(t_so_long *game, char **map)
{
	int x ;
	int y;
	x = game->player_x;
	y = game->player_y - 1;
	
	if (can_move(map, x, y))
	{
		game->player_y = y;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}
void move_down(t_so_long *game, char **map)
{
	int x ;
	int y;
	x = game->player_x;
	y = game->player_y + 1;
	
	if (can_move(map, x, y))
	{
		game->player_y = y;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}
void	setup_hooks(t_so_long *game)
{
	mlx_hook(game->win, 2, 1L<<0, wrapper, game);
	mlx_key_hook(game->win,exit_esc,game);
	mlx_hook(game->win,17, 0, exit_game,game);
}