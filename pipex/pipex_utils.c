/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kikwasni <kikwasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:32:51 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/23 13:41:53 by kikwasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*checker(char *cmd, char **env)
{
	char	*is_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
	}
	is_path = my_getenv("PATH", env);
	if (!is_path)
		return (NULL);
	else
		return (is_path);
}

int	open_file(char *file, int in)
{
	int	n;

	if (in == 0)
		n = open(file, O_RDONLY, 0777);
	if (in == 1)
		n = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (n == -1)
	{
		perror("Error in opening file");
		exit(-1);
	}
	return (n);
}

void	free_sp(char **splited)
{
	int	i;

	i = 0;
	while (splited[i] != NULL)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

char	*my_getenv(char *name, char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[j] != NULL)
	{
		i = 0;
		while (env[j][i] == name[i] && name[i] != '\0')
		{
			i++;
			if (name[i] == '\0' && env[j][i] == '=')
				return (&env[j][i + 1]);
		}
		j++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	*is_path;
	char	**all_path;
	char	*full_path;
	char	*exe_path;
	int		i;

	i = 0;
	is_path = checker(cmd, env);
	all_path = ft_split(is_path, ':');
	while (all_path[i] != NULL)
	{
		full_path = ft_strjoin(all_path[i], "/");
		exe_path = ft_strjoin(full_path, cmd);
		if (access(exe_path, F_OK | X_OK) == 0)
		{
			free(full_path);
			free_sp(all_path);
			return (exe_path);
		}
		free(exe_path);
		free(full_path);
		i++;
	}
	free_sp(all_path);
	return (NULL);
}

// int main(int argc, char **argv, char **env)
// {
// 	char *rest;
// 	rest = my_getenv("PATH", env);
//      printf("PATH: %s\n", rest);
// }
// int main(void)
// {
//     extern char **environ;
//     char *cmd = "ls";
//     char *result = get_path(cmd, environ);
//     if (result)
//     {
//         printf("Znaleziono ścieżkę: %s\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("Nie znaleziono komendy: %s\n", cmd);
//     }
//     return 0;
// }
