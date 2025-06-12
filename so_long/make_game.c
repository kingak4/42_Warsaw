/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:38:35 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/12 17:15:46 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_so_long *game)
{
	game->textures.w = 64;
	game->textures.h = 64;
	game->textures.img_coin = mlx_xpm_file_to_image(game->mlx,
			"textures/col.xpm",
			&game->textures.w, &game->textures.h);
	game->textures.img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall1.xpm", &game->textures.w, &game->textures.h);
	game->textures.img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit1.xpm", &game->textures.w, &game->textures.h);
	game->textures.img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/p.xpm", &game->textures.w, &game->textures.h);
	game->textures.img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/f1.xpm", &game->textures.w, &game->textures.h);
}

static void	witch_texture(t_so_long *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->textures.img_wall, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->textures.img_coin, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->win, game->textures.img_player, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->textures.img_exit, x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->textures.img_floor, x * 64, y * 64);
}

void	draw_map(t_so_long *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			witch_texture(game, x, y);
			x++;
		}
		y++;
	}
}

void	start_game(t_so_long *game)
{
	draw_map(game);
}
