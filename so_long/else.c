/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:21:08 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 14:24:06 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_exit(t_so_long *game)
{
	if (game->map)
		free_map(game);
	if (game->map_copy)
		free_map_copy(game);
	if (game->mlx && game->textures.img_coin)
		mlx_destroy_image(game->mlx, game->textures.img_coin);
	if (game->mlx && game->textures.img_wall)
		mlx_destroy_image(game->mlx, game->textures.img_wall);
	if (game->mlx && game->textures.img_exit)
		mlx_destroy_image(game->mlx, game->textures.img_exit);
	if (game->mlx && game->textures.img_player)
		mlx_destroy_image(game->mlx, game->textures.img_player);
	if (game->mlx && game->textures.img_floor)
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

void	check_if_one(t_so_long *game, int tmp)
{
	if (tmp == 1)
	{
		ft_printf("ERROR:The lines are not equal in length.\n");
		free(game->map_line);
		close(game->fd);
		clean_exit(game);
	}
}

int	check_keycode(int flag, t_so_long *game, int keycode)
{
	if (keycode == 65361 || keycode == 97)
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
	return (flag);
}

static	void	another_ch(t_so_long *game, int *flag)
{
	if (game->map[game->y][game->x] == 'P' ||
	game->map[game->y][game->x] == 'E' ||
	game->map[game->y][game->x] == 'C' ||
	game->map[game->y][game->x] == '0' ||
	game->map[game->y][game->x] == '1' ||
	game->map[game->y][game->x] == '\n')
		return ;
	else
		(*flag)++;
}

int	sign_checker(t_so_long *game)
{
	int	flag;

	game->y = 0;
	flag = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			another_ch(game, &flag);
			game->x++;
		}
		game->y++;
	}
	if (flag > 0)
	{
		ft_printf("There are invalid characters on the map.");
		return (0);
	}
	return (1);
}
