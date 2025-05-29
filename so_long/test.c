/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:10:00 by kikwasni          #+#    #+#             */
/*   Updated: 2025/05/29 11:30:23 by kikwasni         ###   ########.fr       */
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
//	int height = 32;
//	while (y <= height)
//	{
//		mlx_put_image_to_window(mlx, win, "bird_img",x,y);
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
//	void *param;

//    mlx = mlx_init();

//    win = mlx_new_window(mlx, 800, 600, "Bird Test");

//    bird_img = mlx_xpm_file_to_image(mlx, "bird.xpm", &width, &height);

	
//	mlx_loop_hook(mlx,hokkey,param);
//    mlx_hook(win, 17, 0, close_window, mlx); // Zamyka okno przy kliknięciu w krzyżyk
//    return (0);
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
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct s_data {
    void *mlx;
    void *win;
    void *img;
}   t_data;

// Funkcja do zamykania okna
int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

// Funkcja rysująca obrazek w pętli (hook)
int render(void *param)
{
    t_data *data = (t_data *)param;
    int x = 100;
    int y = 32;

    while (y <= WIN_HEIGHT - 32)
    {
        mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
        y += 32;
    }
    return (0);
}

int main(void)
{
    t_data data;
    int img_width, img_height;

    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);

    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Bird Test");
    if (!data.win)
        return (1);

    data.img = mlx_xpm_file_to_image(data.mlx, "wall.xpm", &img_width, &img_height);
    if (!data.img)
    {
        printf("❌ Nie można załadować bird.xpm\n");
        return (1);
    }

    // Ustawienie hooków
    mlx_loop_hook(data.mlx, render, &data);
    mlx_hook(data.win, 17, 0, (int (*)(void *))close_window, &data);
    mlx_loop(data.mlx);

    return (0);
}