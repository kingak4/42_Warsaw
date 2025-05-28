/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:34:34 by kikwasni          #+#    #+#             */
/*   Updated: 2025/05/28 13:00:26 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_so_long
{
	void *mlx;
	void *win;
	char *map;
	int player_x;
	int player_y;
	int moves;
} t_so_long;

typedef struct  s_point
{
  int           x;
  int           y;
} 				t_point;

int		exit_game(void *param);
void	setup_hooks(t_so_long *game);
int		exit_esc(int keycode, void *param);
char	**readmap(int *w, int *s);
int		map_checker(char **map);
int		wall_check(char **map);

#endif