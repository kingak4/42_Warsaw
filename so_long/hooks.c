/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:26:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/12 21:20:25 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	update_palyer(t_so_long *game)
{
	game->map[game->old_y][game->old_x] = '0';
	game->map[game->player_y][game->player_x] = 'P';
}

void	setup_hooks(t_so_long *game)
{
	mlx_hook(game->win, 2, 1L<<0, wrapper, game);
	mlx_key_hook(game->win,exit_esc,game);
	mlx_hook(game->win,17, 0, exit_game,game);
}