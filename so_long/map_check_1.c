/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:25:38 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 14:28:15 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(t_so_long *game)
{
	int	palyer;
	int	exit;
	int	x;
	int	y;

	palyer = 0;
	exit = 0;
	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				palyer++;
			if (game->map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (palyer == 1 && exit == 1)
		return (1);
	return (0);
}

int	coin_check(t_so_long *game)
{
	int	x;
	int	y;
	int	colect;

	y = 0;
	colect = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				colect++;
			x++;
		}
		y++;
	}
	if (colect >= 1)
		return (1);
	return (0);
}

int	check_top_bottom_wall(t_so_long *game)
{
	game->y = 0;
	game->last = 0;
	while (game->map[game->y])
		game->y++;
	game->last = game->y;
	game->x = 0;
	while (game->map[0][game->x] && game->map[0][game->x] != '\n')
	{
		if (game->map[0][game->x] != '1')
			return (0);
		game->x++;
	}
	game->x = 0;
	while (game->map[game->last - 1][game->x] &&
			game->map[game->last - 1][game->x] != '\n')
	{
		if (game->map[game->last - 1][game->x] != '1')
			return (0);
		game->x++;
	}
	return (1);
}

int	wall_check(t_so_long *game)
{
	game->y = 0;
	while (game->map[game->y])
	{
		game->x = 0;
		game->lastx = ft_strlen(game->map[game->y]);
		if (game->map[game->y][game->lastx - 1] == '\n')
			game->lastx--;
		if (game->map[game->y][0] != '1')
			return (0);
		if (game->map[game->y][game->lastx -1] != '1')
			return (0);
		game->y++;
	}
	return (1);
}

t_point	map_len(t_so_long *game)
{
	t_point	size;

	game->x = 0;
	game->y = 0;
	while (game->map[game->y] != NULL)
		game->y++;
	while (game->map[0][game->x] != '\0' && game->map[0][game->x] != '\n')
		game->x++;
	size.y = game->y;
	size.x = game->x;
	return (size);
}
