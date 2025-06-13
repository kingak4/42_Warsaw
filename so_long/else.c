/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   else.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:21:08 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 11:59:22 by kikwasni         ###   ########.fr       */
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
void check_if_one(t_so_long *game, int tmp)
{
	if (tmp == 1)
	{
		ft_printf("ERROR:The lines are not equal in length.\n");
		free(game->map_line);
		close(game->fd);
		clean_exit(game);
	}
}
