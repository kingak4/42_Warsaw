/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:59:39 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 13:54:09 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void another_ch(t_so_long *game, int *flag)
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
	while(game->map[game->y])
	{
		game->x = 0;
		while(game->map[game->y][game->x])
		{
			another_ch(game, &flag);
			game->x++;
		}
		game->y++;
	}
	ft_printf("%d\n", flag);
	if(flag > 0)
	{
		ft_printf("There are invalid characters on the map.");
		return(0);
	}
	return(1);
}
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

int	way_check(t_so_long *game, t_point *begin)
{
	t_point size;
	int y = 0;
	int x;
	
	if (game->map_copy)
		free_map_copy(game);
	map_duplicate(game);
	if (!game->map_copy)
		return (0);
	size = map_len(game);
	flood_fill(game, size, *begin);
	while(game->map_copy[y])
	{
		x = 0;
		while(game->map_copy[y][x] != '\0' && game->map_copy[y][x] != '\n')
		{
			if(game->map_copy[y][x] == 'E'|| game->map_copy[y][x] == 'C' ||game->map_copy[y][x] == '0' )
				return(0);
			x++;	
		}
		y++;
	}
	free_map_copy(game);
	if(!map_checker(game))	
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

int	final_check(t_so_long *game,t_point *begin)
{
	if (map_checker(game) == 0 || find_palyer(game, begin) == 0)
	{
		ft_printf("Error: Incorrect number of arguments.");
		clean_exit(game);
		return (0);
	}
	if(sign_checker(game) == 0)
	{
		clean_exit(game);
		return(0);
	}
	if (coin_check(game) == 0)
	{
		ft_printf("Error: No collectibles on the map.");
		clean_exit(game);
		return (0);
	}
	if (check_top_bottom_wall(game) == 0)
	{
		ft_printf("Error: Top or bottom row is not \n");
		clean_exit(game);
		return (0);
	}
	if (wall_check(game) == 0)
	{
		ft_printf("Error: Map not fully surrounded by walls.");
		clean_exit(game);
		return (0);
	}
	if (way_check(game, begin) == 0)
	{
		ft_printf("Error: No valid path to exit or all collectibles.");
		clean_exit(game);
		return (0);
	}
	return (1);
}
