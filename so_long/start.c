/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:55:42 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 12:00:15 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	count_map_w(t_so_long *game)
{
	game->w = 0;
	game->fd = open("maps/map_error3.ber", O_RDONLY);
	if (game->fd < 0)
		return ;
	game->map_line = get_next_line(game->fd);
	while (game->map_line != NULL)
	{
		game->w++;
		free (game->map_line);
		game->map_line = get_next_line(game->fd);
	}
	close(game->fd);
}

void	count_map_s(t_so_long *game, int tmp)
{
	game->i = 0;
	game->s_check = 0;
	game->s = 0;
	game->fd = open("maps/map_error3.ber", O_RDONLY);
	if (game->fd < 0)
		return ;
	game->map_line = get_next_line(game->fd);
	while (game->map_line != NULL)
	{
		game->s_check = ft_strlen(game->map_line);
		if (game->map_line[game->s_check - 1] == '\n')
			game->s_check--;
		if (game->i == 0)
			game->s = game->s_check;
		else if (game->s_check != game->s)
			tmp = 1;
		game->i++;
		free(game->map_line);
		game->map_line = get_next_line(game->fd);
	}
	check_if_one(game, tmp);
	close(game->fd);
}

int	load_map(t_so_long *game)
{
	game->i = 0;
	game->map = malloc(sizeof(char *) * (game->w + 1));
	game->fd = open("maps/map_error3.ber", O_RDONLY);
	if (!game->map || game->fd < 0)
		return (0);
	while (game->i < game->w)
	{
		game->map_line = get_next_line(game->fd);
		if (!game->map_line)
			return (free_map_fd(game), 0);
		game->map[game->i] = ft_strdup(game->map_line);
		if (!game->map_line)
		{
			free(game->map_line);
			return (free_map_fd(game), 0);
		}
		free(game->map_line);
		game->i++;
	}
	game->map[game->i] = NULL;
	close(game->fd);
	return (1);
}

int	readmap(t_so_long *game)
{
	count_map_w(game);
	count_map_s(game, 0);
	if (game->w == 0 || game->s == 0)
		return (0);
	if (!load_map(game))
		return (0);
	map_duplicate(game);
	return (1);
}

int	main(void)
{
	t_so_long	game;
	t_point		begin;

	ft_bzero(&game, sizeof(t_so_long));
	readmap(&game);
	find_palyer(&game, &begin);
	if (final_check(&game, &begin) == 1)
	{
		game.count_moves = 0;
		game.mlx = mlx_init();
		open_window(&game);
		init_textures(&game);
		draw_map(&game);
		setup_hooks(&game);
		mlx_loop(game.mlx);
	}
	free_map(&game);
	free_map_copy(&game);
}
