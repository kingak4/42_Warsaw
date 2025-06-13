/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:17:11 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/13 14:20:30 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_so_long *game)
{
	int	x ;
	int	y;

	x = game->player_x - 1;
	y = game->player_y;
	if (can_move(game, x, y))
	{
		game->player_x = x;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}

void	move_right(t_so_long *game)
{
	int	x;
	int	y;

	x = game->player_x + 1;
	y = game->player_y;
	if (can_move(game, x, y))
	{
		game->player_x = x;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}

void	move_up(t_so_long *game)
{
	int	x ;
	int	y;

	x = game->player_x;
	y = game->player_y - 1;
	if (can_move(game, x, y))
	{
		game->player_y = y;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}

void	move_down(t_so_long *game)
{
	int	x ;
	int	y;

	x = game->player_x;
	y = game->player_y + 1;
	if (can_move(game, x, y))
	{
		game->player_y = y;
		game->count_moves++;
		ft_printf("Steps: %d\n", game->count_moves);
	}
}

void	make_moves(int keycode, void *param, t_so_long *game)
{
	int	flag;

	(void)param;
	game->old_x = game->player_x;
	game->old_y = game->player_y;
	flag = 0;
	flag = check_keycode(flag, game, keycode);
	if (flag > 0)
		start_game(game);
}
