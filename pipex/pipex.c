/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:32:48 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/23 12:39:44 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exe(char *cmd, char **env)
{
	char	**path_splited;
	char	*way;

	path_splited = ft_split(cmd, ' ');
	way = get_path(path_splited[0], env);
	if (execve(way, path_splited, env) == -1)
	{
		write(2, "command not found\n", 18);
		free(way);
		free_sp(path_splited);
		exit(1);
	}
	free(way);
	free_sp(path_splited);
}

void	child(char *cmd, int *tab_fd, char **env, char *file)
{
	int	in;
	int	fd;

	in = 0;
	fd = 0;
	fd = open_file(file, in);
	dup2(fd, 0);
	close(fd);
	dup2(tab_fd[1], 1);
	close(tab_fd[0]);
	exe(cmd, env);
}

void	parent(char *cmd2, int *tab_fd, char **env, char *file)
{
	int	in;
	int	fd;

	fd = 0;
	in = 1;
	fd = open_file(file, in);
	dup2(fd, 1);
	close(fd);
	dup2(tab_fd[0], 0);
	close(tab_fd[0]);
	close(tab_fd[1]);
	exe(cmd2, env);
}

int	main(int ac, char *av[], char **envp)
{
	int		tab_fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("to few arguments :( \n", 2);
		exit(0);
	}
	if (pipe(tab_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (pid == 0)
		child(av[2], tab_fd, envp, av[1]);
	else if (pid > 0)
		parent(av[3], tab_fd, envp, av[4]);
	return (0);
}
// int main(int argc, char *argv[], char **envp)
// {
// 	int	fd[2];
// 	char *s = "hello";
// 	printf("env: %s\n", envp[0]);
// 	if(pipe(fd) == -1)
// 		return (1);
// 	int id;
// 	id = fork();
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		write(fd[1], s, 5 );
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		char	y[6];
// 		read(fd[0], y, 5);
// 		close(fd[0]);
// 		y[5] = '\0';
// 		printf("%s\n", y);
// 		y[3] = 's';
// 		printf("%s\n", y);
// 	}
// 	}