/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:55:42 by kikwasni          #+#    #+#             */
/*   Updated: 2025/05/05 17:13:21 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	open_window(t_so_long *game)
{
	game->mlx = mlx_init();
	printf("Otwarcie okna...\n");
	game->win = mlx_new_window(game->mlx,832,640, "so_long");
	printf("Otwarcie okna...\n");
	mlx_loop(game->mlx);
}
int main()
{
	t_so_long game;
	
	open_window(&game);
}