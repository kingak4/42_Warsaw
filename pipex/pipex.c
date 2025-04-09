/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:32:48 by kikwasni          #+#    #+#             */
/*   Updated: 2025/03/13 09:24:24 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char **envp)
{
	int	fd[2];
	char *s = "hello";

	printf("env: %s\n", envp[0]);
	if(pipe(fd) == -1)
		return (1);
	int id;
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], s, 5 );
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		char	y[6];
		
		read(fd[0], y, 5);
		close(fd[0]);
		y[5] = '\0';
		printf("%s\n", y);
		y[3] = 's';
		printf("%s\n", y);
	}
	}
	
