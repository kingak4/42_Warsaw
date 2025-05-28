/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:26:25 by kikwasni          #+#    #+#             */
/*   Updated: 2025/05/07 10:41:44 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_hooks(t_so_long *game)
{
	mlx_key_hook(game->win,exit_esc,game);
	mlx_hook(game->win,17, 0, exit_game,game);
}