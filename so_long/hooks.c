/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:26:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/12 13:48:50 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_exit(t_so_long *game)
{
	if(game->map)
		free_map(game);
	if(game->map_copy)
		free_map_copy(game);
	if(game->mlx && game->textures.img_coin)
		mlx_destroy_image(game->mlx, game->textures.img_coin);
	if(game->mlx && game->textures.img_wall)
		mlx_destroy_image(game->mlx, game->textures.img_wall);
	if(game->mlx && game->textures.img_exit)
		mlx_destroy_image(game->mlx, game->textures.img_exit);
	if(game->mlx && game->textures.img_player)
		mlx_destroy_image(game->mlx, game->textures.img_player);
	if(game->mlx && game->textures.img_floor)
		mlx_destroy_image(game->mlx, game->textures.img_floor);
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

void	open_window(t_so_long *game)
{
	game->win = mlx_new_window(game->mlx,960,640, "so_long");
}
int	exit_game(void *param)
{
	(void)param;
	t_so_long *game = (t_so_long *)param;
	clean_exit(game);
	return(0);
}
int	exit_esc(int keycode, void *param)
{
	(void)param;
	t_so_long *game = (t_so_long *)param;
	if(keycode == 65307)
		clean_exit(game);
	return(0);
}
int can_move(t_so_long *game, int x, int y)
{

	if (game->map[y] == NULL || game->map[y][x] == '\0')
		return 0;
	if(game->map[y][x] == '1')
		return(0);
	if (coin_check(game) > 0)
	{
		if(game->map[y][x] == 'E')
			return(0);
	}
	if(coin_check(game) == 0)
	{
		if(game->map[y][x] == 'E')
		{
			ft_printf("Congratulations! 🎉✨");
			exit_game(game);
		}
	}
	return(1);
}

void	make_moves(int keycode, void *param, t_so_long *game)
{
	(void)param;
	int flag;
	game->old_x = game->player_x;
	game->old_y = game->player_y;
	flag = 0;
	if(keycode == 65361 || keycode == 97)
	{
		move_left(game);
		update_palyer(game);
		flag++;
	}
	else if (keycode == 65363 || keycode == 100)
	{
		move_right(game);
		update_palyer(game);
		flag++;
	}
	else if (keycode == 65362 || keycode == 119)
	{
		move_up(game);
		update_palyer(game);
		flag++;
	}
	else if (keycode == 65364 || keycode == 115)
	{
		move_down(game);
		update_palyer(game);
		flag++;
	}
	if(flag > 0)
		start_game(game);
}

void	update_palyer(t_so_long *game)
{
	game->map[game->old_y][game->old_x] = '0';
	game->map[game->player_y][game->player_x] = 'P';
}

int wrapper(int keycode, void *param)
{
	t_so_long *game = (t_so_long *)param;

	make_moves(keycode,NULL,game);
	return(0);
}
void move_left(t_so_long *game)
{
	int x ;
	int y;
	x = game->player_x - 1;
	y = game->player_y;
	
	if (can_move(game, x, y))
	{
		game->player_x = x;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}
void move_right(t_so_long *game)
{
	int x ;
	int y;
	x = game->player_x + 1;
	y = game->player_y;
	
	if (can_move(game, x, y))
	{
		game->player_x = x;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}

void move_up(t_so_long *game)
{
	int x ;
	int y;
	x = game->player_x;
	y = game->player_y - 1;
	
	if (can_move(game, x, y))
	{
		game->player_y = y;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}
void move_down(t_so_long *game)
{
	int x ;
	int y;
	x = game->player_x;
	y = game->player_y + 1;
	
	if (can_move(game, x, y))
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