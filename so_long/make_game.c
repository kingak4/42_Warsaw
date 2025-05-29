/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:38:35 by kikwasni          #+#    #+#             */
/*   Updated: 2025/05/29 12:50:02 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_textures(t_texture *image)
{	
	image->w = 64;
	image->h = 64;
	image->img_coin = mlx_xpm_file_to_image(image->mlx,"textures/hart.xpm",&image->w, &image->h);
	image->img_wall = mlx_xpm_file_to_image(image->mlx,"textures/wall.xpm",&image->w, &image->h);
	image->img_exit = mlx_xpm_file_to_image(image->mlx,"textures/exit.xpm",&image->w, &image->h);
	image->img_player = mlx_xpm_file_to_image(image->mlx,"textures/char_02.xpm",&image->w, &image->h);
}