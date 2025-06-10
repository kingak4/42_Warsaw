/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:55:42 by kikwasni          #+#    #+#             */
/*   Updated: 2025/06/10 15:30:28 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>


void	open_window(t_so_long *game)
{
	game->win = mlx_new_window(game->mlx,960,640, "so_long");
}
int	exit_game(void *param)
{
	(void)param;
	exit(0);
	return(0);
}
int	exit_esc(int keycode, void *param)
{
	(void)param;
	if(keycode == 65307)
		exit(0);
	return(0);
}

char	**readmap(int *w, int *s, t_so_long *game)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	int		check;
	
	i = 0;
	*w = 0;
	*s = 0;
	
	fd = open("maps/map4.ber", O_RDONLY);
	if (fd < 0)
		return(NULL);
	while((line = get_next_line(fd)) != NULL)
	{
		(*w)++;
		free(line);
	}
	close(fd);
	fd = open("maps/map4.ber", O_RDONLY);
	if (fd < 0)
		return(NULL);
	if (line != NULL)
	{
		line = get_next_line(fd);
		check = 0;
		*s = ft_strlen(line);
		free(line);
	}
	while((line = get_next_line(fd)) != NULL)
	{
		check = ft_strlen(line);
		if (line[check - 1] == '\n')
			check--;
		if (i == 0)
			*s = check;
		else if (check != *s)
		{
			free(line);
			close(fd);
			return (NULL);
		}
		i++;
		free(line);
	}
	close(fd);
	map = malloc(sizeof(char *) * (*w + 1));
	if(!map)
		return(NULL);
	i = 0;
	fd = open("maps/map4.ber", O_RDONLY);
	if (fd < 0)
		return(NULL);
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = ft_strdup(line);
		if(!map[i])
		{
			free(line);
			return(NULL);
		}
		i++;
		free(line);
	}
	map[i] = NULL;
	close(fd);
	game->map = map;
	return(map);
}

int main()
{
	t_so_long game;
	
	int w = 0, s = 0;
	char **map = readmap(&w, &s,&game);
	
	game.map = map;
	game.count_moves = 0;
	if(final_check(map) > 0)
	{
		game.mlx = mlx_init();
		open_window(&game);
		init_textures(&game);
		find_palyer(map,&game);
		draw_map(&game,map);
		setup_hooks(&game);
		mlx_loop(game.mlx);
	}
}

