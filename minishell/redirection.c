/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdyga <kdyga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:26:05 by kdyga             #+#    #+#             */
/*   Updated: 2025/07/01 20:50:21 by kdyga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// #define TRUNC 0
// #define APPEND 1
// #define STDOUT 1
// #define STDERR 2

// typedef struct s_mini
// {
// 	int		output_file;
// 	int		ret;
// 	int		no_file;
// }			t_mini;

// typedef struct s_token
// {
// 	char	*str;
// }			t_token;

// void	ft_putstr_fd(char *s, int fd)
// {
// 	write(fd, s, strlen(s));
// }

// void	ft_putendl_fd(char *s, int fd)
// {
// 	ft_putstr_fd(s, fd);
// 	write(fd, "\n", 1);
// }
//
void	redir(t_mini *mini, t_token *token, int type)
{
	int	flags;

	flags = O_CREAT | O_WRONLY | O_TRUNC;
	close(mini->output_file);
	if (type == TRUNC)
		mini->output_file = open(token->str, flags, S_IRWXU);
	else
		mini->output_file = open(token->str, flags, S_IRWXU);
	if (mini->output_file == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd("no file", STDERR);
		ft_putendl_fd(token->str, STDERR);
		mini->ret = 1;
		mini->no_file = 1;
		return ;
	}
	dup2(mini->output_file, STDOUT);
}
//
//int	main(void)
// {
// 	t_mini	mini;
// 	t_token	token;

// 	mini = {.output_file;
// 	mini = {.output_file = -1, .ret;
// 	mini = {.output_file = -1, .ret = 0, .no_file;
// 	mini = {.output_file = -1, .ret = 0, .no_file = 0};
// 	token.str = "output.txt";
// 	redir(&mini, &token, TRUNC);
// 	write(STDOUT_FILENO, "test\n", 4);
// 	if (mini.output_file > 2)
// 		close(mini.output_file);
// 	return (0);
// }
