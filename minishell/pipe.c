/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdyga <kdyga@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:38:31 by kdyga             #+#    #+#             */
/*   Updated: 2025/07/01 20:52:37 by kdyga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// do weryfikacji czy można global variable ustalic
int	minipipe(t_mini *mini)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		printf("Error pipe.c didn't make pipe");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		printf("Error pipe.c fork dind't make a process");
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	else if (pid == 0)
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
		{
			perror("Error pipe.c parent");
			close(pipefd[0]);
			return (-1);
		}
		close(pipefd[0]);
		mini->pipe_read = STDIN_FILENO;
		mini->pipe_write = -1;
		mini->pid = -1;
		mini->parent = 0;
		return (0);
	}
	else if (pid > 0)
	{
		close(pipefd[0]);
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			perror("Error pipe.c parent");
			close(pipefd[1]);
			return (-1);
		}
		close(pipefd[1]);
		mini->pipe_read = -1;
		mini->pipe_write = STDOUT_FILENO;
		mini->pid = pid;
		mini->last = 0;
		mini->parent = 1;
		return (1);
	}
	return (-1);
}
