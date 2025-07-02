/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:04:35 by kdyga             #+#    #+#             */
/*   Updated: 2025/07/02 14:09:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

#define EMPTY 0
#define TRUNC 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_cmd
{
	char	*line;
	char	*redi_file;
	int		*redi_signal;
	int		*count_redi;
}	t_cmd;

//pipe.c
 int	minipipe(t_mini *mini);
 void	redir(t_mini *mini, t_token *token, int type);

#endif
