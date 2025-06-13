/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:33:59 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 14:00:42 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	free_map_fd(t_so_long *game)
{
	free_map(game);
	close(game->fd);
	return (0);
}

void	map_duplicate(t_so_long *game)
{
	if (game->map_copy)
		free_map_copy(game);
	game->i = 0;
	game->map_copy = malloc(sizeof(char *) * (game->w + 1));
	if (!game->map_copy)
		return ;
	game->fd = open("maps/map_error3.ber", O_RDONLY);
	if (game->fd < 0)
		return ;
	game->map_line = get_next_line(game->fd);
	while (game->map_line != NULL)
	{
		game->map_copy[game->i] = ft_strdup(game->map_line);
		if (!game->map_copy[game->i])
		{
			game->map_copy[game->i] = NULL;
			free_map_copy(game);
			return ;
		}
		game->i++;
		free(game->map_line);
		game->map_line = get_next_line(game->fd);
	}
	game->map_copy[game->i] = NULL;
	close(game->fd);
}

int	wrapper(int keycode, void *param)
{
	t_so_long	*game;

	game = (t_so_long *)param;
	make_moves(keycode, NULL, game);
	return (0);
}
