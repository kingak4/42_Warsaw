/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:32:51 by kikwasni          #+#    #+#             */
/*   Updated: 2025/04/16 21:37:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_function(int exiter)
{
	if(exiter == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
	exit(0);
}
int	open_file(char *file,int in)
{
	int n;
	if(in == 0)
		n = open(file,O_RDONLY,0777);
	if(in == 1)
		n = open(file,O_RDWR | O_CREAT | O_TRUNC,0777);
	if (n == -1)
	{
		perror("Error in opening file");
		exit(-1);
	}
	return(n);
}
void	free_sp(char **splited)
{
	int i;
	
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
	int i;
	int j;

	i = 0;
	j = 0;
	while (env[j] != NULL)
	{
		i = 0;
		while(env[j][i] == name[i] && name[i] != '\0') 
		{
			i++;
			if(name[i] == '\0' && env[j][i] == '=')
				return(&env[j][i + 1]);
		}
		j++;
	}
	return(NULL);

}

char	*get_path(char *cmd,char **env)
{
	char	*is_path;
	char 	**all_path;
	char	*full_path;
	char	*exe_path;
	int 	i;

	i = 0;
	if(ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return(ft_strdup(cmd));	
	}
	is_path = my_getenv("PATH",env);
	if(!is_path)
		return(NULL);
	all_path = ft_split(is_path, ':');
	while (all_path[i] != NULL)
	{
		full_path = ft_strjoin(all_path[i],"/");
		exe_path = ft_strjoin(full_path,cmd);
		if (access(exe_path, F_OK | X_OK) == 0)
		{
			free(full_path);
			return(exe_path);
		}
		else
		{
			free(exe_path);
			free(full_path);
		}
		i++;
	}
	free_sp(all_path); 
	return(NULL);
	
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
