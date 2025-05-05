/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:10:00 by kikwasni          #+#    #+#             */
/*   Updated: 2025/05/05 09:39:15 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>

//int close_window(void *param)
//{
//    mlx_destroy_window(param, param);
//    exit(0);
//}
//int	hokkey(int x ,void *win, void *mlx)
//{ 
//	int y = 32;
//	while (y <= height)
//	{
//		mlx_put_image_to_window(mlx, win, bird_img,x,y);
//		y += 32;
//		printf("%d", y);
//	}
//}
//int main(void)
//{
//    void *mlx;
//    void *win;
//    int width = 800;
//    int height = 600;
//    void *bird_img;
//	int x = 100;
//	int y = 32;
	

//    mlx = mlx_init();

//    win = mlx_new_window(mlx, 800, 600, "Bird Test");

//    bird_img = mlx_xpm_file_to_image(mlx, "bird.xpm", &width, &height);

	
//	mlx_loop_hook()
//    //mlx_hook(win, 17, 0, close_window, mlx); // Zamyka okno przy kliknięciu w krzyżyk
//    //return (0);
//}

//int main()
//{
//	void *mlx;
//	void *window;
//	void *image;
//	char *addr;
//	int i ;
//	int g ;
//	int b;
//	int rest;
//	int y = 5;
//	int x = 10;
//	unsigned int color;

//	color = 0x00FF0000;
//	mlx = mlx_init();
//	window = mlx_new_window(mlx,800,600, "bird.xpm");
//	image = mlx_new_image(mlx,800,600);
//	addr = mlx_get_data_addr(image, &i, &g, &b);
//	rest = (y * g) + ( x * i / 8);
//	*(unsigned int *)(addr + rest) = color;
//	mlx_put_image_to_window(mlx, window, image, 0, 0);
//	mlx_loop(mlx);
	
//}
