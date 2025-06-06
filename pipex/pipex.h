/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:32:44 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/23 13:37:47 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*checker(char *cmd, char **env);
int		open_file(char *file, int in);
char	*my_getenv(char *name, char **envp);
char	*get_path(char *cmd, char **env);
void	free_sp(char **splited);
void	exe(char *cmd, char **env);
void	child(char *cmd2, int *tab_fd, char **env, char *file);
void	parent(char *cmd2, int *tab_fd, char **env, char *file);

#endif