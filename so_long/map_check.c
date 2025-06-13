/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:59:39 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 15:20:09 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	filler(t_so_long *game, t_point size, int y, int x)
{
	if (y < 0 || x < 0 || y >= size.y || x >= size.x)
		return ;
	if (game->map_copy[y][x] == 'D' || game->map_copy[y][x] == '1')
		return ;
	if (game->map_copy[y][x] != '0'
		&& game->map_copy[y][x] != 'C' && game->map_copy[y][x] != 'E' &&
		game->map_copy[y][x] != 'P')
		return ;
	game->map_copy[y][x] = 'D';
	filler(game, size, y + 1, x);
	filler(game, size, y - 1, x);
	filler(game, size, y, x + 1);
	filler(game, size, y, x - 1);
}

void	flood_fill(t_so_long *game, t_point size, t_point begin)
{
	filler(game, size, begin.y, begin.x);
}

int	way_check(t_so_long *game, t_point *begin, int y, int x)
{
	t_point	size;

	if (game->map_copy)
		free_map_copy(game);
	map_duplicate(game);
	if (!game->map_copy)
		return (0);
	size = map_len(game);
	flood_fill(game, size, *begin);
	while (game->map_copy[y])
	{
		x = 0;
		while (game->map_copy[y][x] != '\0' && game->map_copy[y][x] != '\n')
		{
			if (game->map_copy[y][x] == 'E' || game->map_copy[y][x] == 'C'
				|| game->map_copy[y][x] == '0' )
				return (0);
			x++;
		}
		y++;
	}
	free_map_copy(game);
	if (!map_checker(game))
		return (0);
	return (1);
}

int	find_palyer(t_so_long *game, t_point *begin)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				begin->x = x;
				begin->y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
