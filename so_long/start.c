/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:55:42 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/12 16:42:19 by kikwasni         ###   ########.fr       */
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
	while ((game->map_line = get_next_line(game->fd)) != NULL)
	{
		game->w++;
		free (game->map_line);
	}
	close(game->fd);
}

void	count_map_s(t_so_long *game)
{
	int	i;

	i = 0;
	game->s_check = 0;
	game->s = 0;
	game->fd = open("maps/map_error3.ber", O_RDONLY);
	if (game->fd < 0)
		return ;
	while ((game->map_line = get_next_line(game->fd)) != NULL)
	{
		game->s_check = ft_strlen(game->map_line);
		if (game->map_line[game->s_check - 1] == '\n')
			game->s_check--;
		if (i == 0)
			game->s = game->s_check;
		else if (game->s_check != game->s)
		{
			free(game->map_line);
			close(game->fd);
			return ;
		}
		i++;
		free(game->map_line);
	}
	close(game->fd);
}

void	map_duplicate(t_so_long *game)
{
	if (game->map_copy)
		free_map_copy(game);
	game->i = 0;
	game->map_copy = malloc(sizeof(char *) * (game->w+ 1));
	if (!game->map_copy)
		return ;
	game->fd = open("maps/map_error3.ber", O_RDONLY);
	if (game->fd < 0)
		return ;
	while ((game->map_line = get_next_line(game->fd)) != NULL)
	{
		game->map_copy[game->i] = ft_strdup(game->map_line);
		if (!game->map_copy[game->i])
		{
			game->map_copy[game->i] = NULL;
			free_map_copy(game);
			return;
		}
		game->i++;
		free(game->map_line);
	};
	game->map_copy[game->i] = NULL;
	close(game->fd);
}

int	load_map(t_so_long *game)
{
	game->i = 0;
	count_map_w(game);
	game->map = malloc(sizeof(char *) * (game->w + 1));
	game->fd = open("maps/map_error3.ber", O_RDONLY);
	if (!game->map || game->fd < 0)
		return (0);
	while(game->i < game->w)
	{
		game->map_line = get_next_line(game->fd);
		if(!game->map_line || !(game->map[game->i] = ft_strdup(game->map_line)))
		{
			free(game->map_line);
			free_map(game);
			close(game->fd);
			return (0);
		}
		free(game->map_line);
		game->i++;
	}
	game->map[game->i] = NULL;
	close(game->fd);
	return (1);
}

void	free_map(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_map_copy(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map_copy[i] != NULL)
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
	game->map_copy = NULL;
}

int	readmap(t_so_long *game)
{
	count_map_w(game);
	count_map_s(game);
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
